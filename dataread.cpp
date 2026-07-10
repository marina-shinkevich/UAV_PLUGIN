#include "dataread.h"
#include "settings.h"
#include "dialitem.h"

#include <QtCore/QCoreApplication>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QEventLoop>
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>
#include <QTimer>
#include <qqmlengine.h>
#include <qqmlcontext.h>
#include <qqml.h>
#include <memory>
#include <QtXml>
#include <QFile>
#include <QDebug>

DataRead::DataRead(QObject *parent) : QObject(parent)
{
    engine.rootContext()->setContextProperty("pb", this);
    engine.rootContext()->setContextProperty("settings", &m_settings);
    engine.rootContext()->setContextProperty("report", &m_report);
    engine.rootContext()->setContextProperty("report2", &m_report2);  // Второй самолет
    qmlRegisterType<DialItem>("IGControls", 2,0,"DialItem");
    source = QStringLiteral("qrc:/main.qml");

    connect(&manager, &QNetworkAccessManager::authenticationRequired,this, &DataRead::slotAuthenticationRequired);
    tmrRequest.setInterval(100); 
    connect(&tmrRequest, &QTimer::timeout, this, &DataRead::refreshConnection);
    tmrRequest.start();

}
void DataRead::onClickReportTarget(){ if(!f_openMsgView){ engine.load(source); }  }

void DataRead::openReportMsgView() { f_openMsgView = true; tmrRequest.start(); }
void DataRead::closeReportMsgView() { f_openMsgView = false; tmrRequest.stop(); }


void DataRead::startRequest(const QUrl &request)
{
    url = request;
}

void DataRead::refreshConnection()
{
    url = QUrl("http://127.0.0.1:9280/mandala?descr");
    reply = manager.get(QNetworkRequest(url));

    connect(reply, &QNetworkReply::finished, this, &DataRead::httpFinished);

    connect(reply, &QIODevice::readyRead, this, &DataRead::httpReadyRead);

}

void DataRead::httpFinished()
{
    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << "Error in reply: " << reply->errorString();
        reply->deleteLater();
        return;
    }

}

void DataRead::httpReadyRead()
{
    QDomDocument xmlList;
    QVariant var;

    data = (QString) reply->readAll();
    lastXmlData = data;  
    
    qDebug() << "--- data update ---";
    qDebug() << "Aircraft:" << m_aircraftSelection;
    qDebug() << "Raw XML data length:" << data.length() << "bytes";

    xmlList.setContent(data);
    QDomElement root = xmlList.documentElement();

    QString Type = root.tagName();

    QDomNode n = root.firstChild();
    while (!n.isNull()) {
        QDomElement e = n.toElement();
        if(!e.isNull()){
            param.insert(e.tagName(),e.toElement().text());
        }
        n = n.nextSibling();
    }


    //обновляем данные для текущего выбранного вертолета
    if (m_aircraftSelection == 1) {
        UVH_VT_170();
    } else {
        VT_25V1();
    }
}



void DataRead::slotAuthenticationRequired(QNetworkReply *, QAuthenticator *authenticator)
{

}

void DataRead::updateVariables(QString name, QVariant state)
{
    qDebug() << "updateVariables" << name << state;
    QString reqURL = "http://127.0.0.1:9280/mandala";
    QString reqParam = name;
    QVariant temp = state;
    QString reqValue = temp.toString();

    QString reqFull = reqURL +"?"+ reqParam + "=" + reqValue;
    qDebug() << reqFull;
    reply = manager.get(QNetworkRequest(reqFull));

}
// переключение м-ду вертолетами
void DataRead::setAircraftSelection(int aircraft)
{
    if ((aircraft == 1 || aircraft == 2) && m_aircraftSelection != aircraft) {
        m_aircraftSelection = aircraft;
        qDebug() << "Aircraft switched to:" << aircraft;
        emit aircraftSelectionChanged();

        refreshInterface();
    }
}


void DataRead::refreshInterface()
{
    qDebug() << "Refreshing interface for aircraft:" << m_aircraftSelection;
    

    if (!lastXmlData.isEmpty()) {
        QDomDocument xmlList;
        xmlList.setContent(lastXmlData);
        QDomElement root = xmlList.documentElement();
    
        param.clear();
        
        QDomNode n = root.firstChild();
        while (!n.isNull()) {
            QDomElement e = n.toElement();
            if(!e.isNull()){
                param.insert(e.tagName(), e.toElement().text());
            }
            n = n.nextSibling();
        }
        
        if (m_aircraftSelection == 1) {
            UVH_VT_170();
        } else {
            VT_25V1();
        }
        
        qDebug() << "Interface refreshed with last data for aircraft:" << m_aircraftSelection;
    } else {
        qDebug() << "No saved data available for refresh";
    }
}


MandalaValues* DataRead::currentReport()
{
    return (m_aircraftSelection == 1) ? &m_report : &m_report2;
}
// для вертолета 1
void DataRead::UVH_VT_170()
{
    qDebug() << "=== PROCESSING AIRCRAFT 1 DATA ===";
    QVariant var;
    MandalaValues* current = &m_report;
    qDebug() << "Processing Aircraft 1 data";

    // Group 1 - System Variables
    var = param.value("sns.bat.voltage");
    current->setBatVoltage(var.toFloat());
    qDebug() << "Group1 - Battery Voltage:" << var.toFloat();
    
    var = param.value("sns.bat.current");
    current->setBatCurrent(var.toFloat());
    qDebug() << "Group1 - Battery Current:" << var.toFloat();
  
    var = param.value("sns.agi.radio");
    current->setAgiRadio(var.toFloat());
    qDebug() << "Group1 - AGI Radio:" << var.toFloat();
    
    var = param.value("sns.gbox.temp");
    current->setEngineGearBoxTemp(var.toFloat());
    qDebug() << "Group1 - Gear Box Temperature:" << var.toFloat();
    
    var = param.value("sns.gbox.rpm");
    current->setGboxRpm(var.toFloat());
    qDebug() << "Group1 - Gear Box RPM:" << var.toFloat();
    
    var = param.value("sns.eng.temp");
    current->setEngTemp(var.toFloat());
    qDebug() << "Group1 - Engine Temperature:" << var.toFloat();
    
    var = param.value("sns.eng.voltage");
    current->setEngVoltage(var.toFloat());
    qDebug() << "Group1 - Engine Voltage:" << var.toFloat();
    
    var = param.value("sns.eng.current");
    current->setEngCurrent(var.toFloat());
    qDebug() << "Group1 - Engine Current:" << var.toFloat();
    
    var = param.value("sns.eng.rpm");
    current->setEngRpm(var.toFloat());
    qDebug() << "Group1 - Engine RPM:" << var.toFloat();
    
    var = param.value("sns.agl.radio");
    current->setAglRadio(var.toFloat());
    qDebug() << "Group1 - AGL Radio:" << var.toFloat();
    
    var = param.value("sns.ers.block");
    current->setErsBlock(var.toFloat());
    qDebug() << "Group1 - ERS Block:" << var.toFloat();
    
    var = param.value("ctr.ers.launch");
    current->setErsLaunch(var.toFloat());
    qDebug() << "Group1 - ERS Launch Control:" << var.toFloat();
    
    var = param.value("sns.ers.status");
    current->setErsStatus(var.toFloat());
    qDebug() << "Group1 - ERS Status:" << var.toFloat();
    
    var = param.value("ctr.eng.thr");
    current->setCtrEngThr(var.toFloat()*100.0);
    qDebug() << "Group1 - Engine Throttle Control:" << var.toFloat();

    // Group 2
    var = param.value("est.usr.u1");           
    current->setUsrU1(var.toFloat());
    qDebug() << "Group2 - U1:" << var.toFloat();
    
    var = param.value("est.usr.u2");
    current->setUsrU2(var.toFloat());
    qDebug() << "Group2 - U2:" << var.toFloat();
    
    var = param.value("est.usr.u3");
    current->setUsrU3(var.toFloat());
    qDebug() << "Group2 - U3:" << var.toFloat();

    var = param.value("est.usr.u4");
    current->setUsrU4(var.toFloat());
    qDebug() << "Group2 - U4:" << var.toFloat();
    
    var = param.value("est.usr.u5");
    current->setUsrU5(var.toFloat());
    qDebug() << "Group2 - U5:" << var.toFloat();
    
    var = param.value("est.usr.u6");
    current->setUsrU6(var.toFloat());
    qDebug() << "Group2 - U6:" << var.toFloat();
    
    var = param.value("est.usr.u7");
    current->setUsrU7(var.toFloat());
    qDebug() << "Group2 - U7:" << var.toFloat();
    
    var = param.value("est.usr.u8");
    current->setUsrU8(var.toFloat());
    qDebug() << "Group2 - U8:" << var.toFloat();
    
    var = param.value("est.usr.u9");
    current->setUsrU9(var.toFloat());
    qDebug() << "Group2 - U9:" << var.toFloat();
    
    var = param.value("est.usr.u10");
    current->setUsrU10(var.toFloat());
    qDebug() << "Group2 - U10:" << var.toFloat();
    
    var = param.value("est.usr.u11");
    current->setUsrU11(var.toFloat());
    qDebug() << "Group2 - U11:" << var.toFloat();
    
    var = param.value("est.usr.u12");
    current->setUsrU12(var.toFloat());
    qDebug() << "Group2 - U12:" << var.toFloat();
    
    var = param.value("est.usr.u13");
    current->setUsrU13(var.toFloat());
    qDebug() << "Group2 - U13:" << var.toFloat();
    
    var = param.value("est.usr.u14");
    current->setUsrU14(var.toFloat());
    qDebug() << "Group2 - U14:" << var.toFloat();
    
    var = param.value("est.rc.thr");
    current->setRcThrottle(var.toFloat());
    qDebug() << "Group2 - RC Throttle:" << var.toFloat();

    // Group 3
    var = param.value("est.usrw.w1");
    current->setUsrW1(var.toInt());
    qDebug() << "Group3 - W1:" << var.toInt();
    
    var = param.value("est.usrw.w2");
    current->setUsrW2(var.toInt());
    qDebug() << "Group3 - W2:" << var.toInt();
    
    var = param.value("est.usrw.w3");
    current->setUsrW3(var.toInt());
    qDebug() << "Group3 - W3:" << var.toInt();
    
    var = param.value("est.usrw.w4");
    current->setUsrW4(var.toInt());
    qDebug() << "Group3 - W4:" << var.toInt();
    
    var = param.value("est.usrw.w5");
    current->setUsrW5(var.toInt());
    qDebug() << "Group3 - W5:" << var.toInt();
    
    var = param.value("est.usrw.w6");
    current->setUsrW6(var.toInt());
    qDebug() << "Group3 - W6:" << var.toInt();
    var = param.value("est.usrw.w7");
    current->setUsrW7(var.toInt());
    qDebug() << "Group3 - W7:" << var.toInt();

    // Group 4
    var = param.value("est.usrf.f1");
    current->setUsrF1(var.toFloat());
    qDebug() << "Group4 - F1:" << var.toFloat();
    
    var = param.value("est.usrf.f2");
    current->setUsrF2(var.toFloat());
    qDebug() << "Group4 - F2:" << var.toFloat();
    
    var = param.value("est.usrf.f3");
    current->setUsrF3(var.toFloat());
    qDebug() << "Group4 - F3:" << var.toFloat();
    
    var = param.value("est.usrf.f4");
    current->setUsrF4(var.toFloat());
    qDebug() << "Group4 - F4:" << var.toFloat();
    
    var = param.value("est.usrf.f5");
    current->setUsrF5(var.toFloat());
    qDebug() << "Group4 - F5:" << var.toFloat();
    
    var = param.value("est.usrf.f6");
    current->setUsrF6(var.toFloat());
    qDebug() << "Group4 - F6:" << var.toFloat();
    
    var = param.value("est.usrf.f7");
    current->setUsrF7(var.toFloat());
    qDebug() << "Group4 - F7:" << var.toFloat();
    
    var = param.value("est.usrf.f8");
    current->setUsrF8(var.toFloat());
    qDebug() << "Group4 - F8:" << var.toFloat();
    
    var = param.value("est.usrf.f9");
    current->setUsrF9(var.toFloat());
    qDebug() << "Group4 - F9:" << var.toFloat();

    // Group 5
    var = param.value("est.usrc.c1");
    current->setUsrC1(var.toInt());
    qDebug() << "Group5 - C1:" << var.toInt();
    
    var = param.value("est.usrc.c2");
    current->setUsrC2(var.toInt());
    qDebug() << "Group5 - C2:" << var.toInt();
    
    var = param.value("est.usrc.c3");
    current->setUsrC3(var.toInt());
    qDebug() << "Group5 - C3:" << var.toInt();

    // Group 6
    var = param.value("est.usrb.b1");
    bool bVal = (var.toString() == "on");
    current->setUsrB1(bVal);
    qDebug() << "Group6 - B1:" << bVal;
    
    var = param.value("est.usrb.b2");
    bool bVal2 = (var.toString() == "on");
    current->setUsrB2(bVal2);
    qDebug() << "Group6 - B2:" << bVal2;
    
    var = param.value("est.usrb.b3");
    bool bVal3 = (var.toString() == "on");
    current->setUsrB3(bVal3);
    qDebug() << "Group6 - B3:" << bVal3;
    
    var = param.value("est.usrb.b4");
    bool bVal4 = (var.toString() == "on");
    current->setUsrB4(bVal4);
    qDebug() << "Group6 - B4:" << bVal4;

    // BlackBox
    bblCnt++;
    bbrCnt++;

    var = param.value("userb_6");
    if(bblState != var.toBool()) {bblState = var.toBool(); bblCnt = 0; bblUpdate = true; }
    else if(bblCnt >= 50){bblCnt = 0; bblUpdate = false; }

    var = param.value("userb_8");
    if(bbrState != var.toBool()) {bbrState = var.toBool(); bbrCnt = 0; bbrUpdate = true; }
    else if(bbrCnt >= 50){bbrCnt = 0; bbrUpdate = false; }

    if(!m_settings.blackBoxUsed1()) bblUpdate = true;
    if(!m_settings.blackBoxUsed2()) bbrUpdate = true;

    current->setStatusBB(!(bblUpdate && bbrUpdate));

    // Clutch
    auto time = QDateTime::currentDateTime().currentSecsSinceEpoch();
    var = param.value("turret_shoot");
    if(var.toBool() && !current->servo()){
        m_servoTime = time;
        current->setServo(var.toBool());
    }
    else if(m_servoTime + m_settings.servoTimeout() < time){
            current->setServo(var.toBool());
    }

    // Gear
    if(current->rpmRotorReal() != 0){
        qreal gear = static_cast<qreal>(current->rpmEngineReal())/static_cast<qreal>(current->rpmRotorReal());
        auto flag = (gear < m_settings.gearMin() || gear > m_settings.gearMax());

        if(flag && !current->gear()){
            m_gearTime = time;
            current->setGear(flag);
        }
        else if(!flag && current->gear()){
            if(m_gearTime + m_settings.gearTimeout() < time)
                current->setGear(flag);
        }
    }
}

// для вертолета 2
void DataRead::VT_25V1()
{
    qDebug() << "=== PROCESSING AIRCRAFT 2 DATA ===";
    QVariant var;
    MandalaValues* current = &m_report2;
    qDebug() << "Processing Aircraft 2 data";

    // Group 1 - System Variables
    var = param.value("sns.bat.voltage");
    current->setBatVoltage(var.toFloat());
    qDebug() << "Group1 - Battery Voltage (Aircraft 2):" << var.toFloat();
    
    var = param.value("sns.bat.current");
    current->setBatCurrent(var.toFloat());
    qDebug() << "Group1 - Battery Current (Aircraft 2):" << var.toFloat();
  
    var = param.value("sns.agi.radio");
    current->setAgiRadio(var.toFloat());
    qDebug() << "Group1 - AGI Radio (Aircraft 2):" << var.toFloat();
    
    var = param.value("sns.gbox.temp");
    current->setEngineGearBoxTemp(var.toFloat());
    qDebug() << "Group1 - Gear Box Temperature (Aircraft 2):" << var.toFloat();
    
    var = param.value("sns.gbox.rpm");
    current->setGboxRpm(var.toFloat());
    qDebug() << "Group1 - Gear Box RPM (Aircraft 2):" << var.toFloat();
    
    var = param.value("sns.eng.temp");
    current->setEngTemp(var.toFloat());
    qDebug() << "Group1 - Engine Temperature (Aircraft 2):" << var.toFloat();
    
    var = param.value("sns.eng.voltage");
    current->setEngVoltage(var.toFloat());
    qDebug() << "Group1 - Engine Voltage (Aircraft 2):" << var.toFloat();
    
    var = param.value("sns.eng.current");
    current->setEngCurrent(var.toFloat());
    qDebug() << "Group1 - Engine Current (Aircraft 2):" << var.toFloat();
    
    var = param.value("sns.eng.rpm");
    current->setEngRpm(var.toFloat());
    qDebug() << "Group1 - Engine RPM (Aircraft 2):" << var.toFloat();
    
    var = param.value("sns.agl.radio");
    current->setAglRadio(var.toFloat());
    qDebug() << "Group1 - AGL Radio (Aircraft 2):" << var.toFloat();
    
    var = param.value("sns.ers.block");
    current->setErsBlock(var.toFloat());
    qDebug() << "Group1 - ERS Block (Aircraft 2):" << var.toFloat();
    
    var = param.value("ctr.ers.launch");
    current->setErsLaunch(var.toFloat());
    qDebug() << "Group1 - ERS Launch Control (Aircraft 2):" << var.toFloat();
    
    var = param.value("sns.ers.status");
    current->setErsStatus(var.toFloat());
    qDebug() << "Group1 - ERS Status (Aircraft 2):" << var.toFloat();

    // Group 2 
    var = param.value("est.usr.u1");           
    current->setUsrU1(var.toFloat());
    qDebug() << "Group2 - U1 (Aircraft 2):" << var.toFloat();
    
    var = param.value("est.usr.u2");
    current->setUsrU2(var.toFloat());
    qDebug() << "Group2 - U2 (Aircraft 2):" << var.toFloat();
    
    var = param.value("est.usr.u3");
    current->setUsrU3(var.toFloat());
    qDebug() << "Group2 - U3 (Aircraft 2):" << var.toFloat();

    var = param.value("est.usr.u4");
    current->setUsrU4(var.toFloat());
    qDebug() << "Group2 - U4 (Aircraft 2):" << var.toFloat();
    
    var = param.value("est.usr.u5");
    current->setUsrU5(var.toFloat());
    qDebug() << "Group2 - U5 (Aircraft 2):" << var.toFloat();
    
    var = param.value("est.usr.u6");
    current->setUsrU6(var.toFloat());
    qDebug() << "Group2 - U6 (Aircraft 2):" << var.toFloat();
    
    var = param.value("est.usr.u7");
    current->setUsrU7(var.toFloat());
    qDebug() << "Group2 - U7 (Aircraft 2):" << var.toFloat();
    
    var = param.value("est.usr.u8");
    current->setUsrU8(var.toFloat());
    qDebug() << "Group2 - U8 (Aircraft 2):" << var.toFloat();
    
    var = param.value("est.usr.u9");
    current->setUsrU9(var.toFloat());
    qDebug() << "Group2 - U9 (Aircraft 2):" << var.toFloat();
    
    var = param.value("est.usr.u10");
    current->setUsrU10(var.toFloat());
    qDebug() << "Group2 - U10 (Aircraft 2):" << var.toFloat();
    
    var = param.value("est.usr.u11");
    current->setUsrU11(var.toFloat());
    qDebug() << "Group2 - U11 (Aircraft 2):" << var.toFloat();
    
    var = param.value("est.usr.u12");
    current->setUsrU12(var.toFloat());
    qDebug() << "Group2 - U12 (Aircraft 2):" << var.toFloat();
    
    var = param.value("est.usr.u13");
    current->setUsrU13(var.toFloat());
    qDebug() << "Group2 - U13 (Aircraft 2):" << var.toFloat();
    
    var = param.value("est.usr.u14");
    current->setUsrU14(var.toFloat());
    qDebug() << "Group2 - U14 (Aircraft 2):" << var.toFloat();

    // Group 3
    var = param.value("est.usrw.w1");
    current->setUsrW1(var.toFloat());
    qDebug() << "Group3 - W1 (Aircraft 2):" << var.toFloat();
    
    var = param.value("est.usrw.w2");
    current->setUsrW2(var.toFloat());
    qDebug() << "Group3 - W2 (Aircraft 2):" << var.toFloat();
    
    var = param.value("est.usrw.w3");
    current->setUsrW3(var.toFloat());
    qDebug() << "Group3 - W3 (Aircraft 2):" << var.toFloat();
    
    var = param.value("est.usrw.w4");
    current->setUsrW4(var.toFloat());
    qDebug() << "Group3 - W4 (Aircraft 2):" << var.toFloat();
    
    var = param.value("est.usrw.w5");
    current->setUsrW5(var.toFloat());
    qDebug() << "Group3 - W5 (Aircraft 2):" << var.toFloat();
    
    var = param.value("est.usrw.w6");
    current->setUsrW6(var.toFloat());
    qDebug() << "Group3 - W6 (Aircraft 2):" << var.toFloat();
    
    var = param.value("est.usrw.w7");
    current->setUsrW7(var.toFloat());
    qDebug() << "Group3 - W7 (Aircraft 2):" << var.toFloat();

    // Group 4
    var = param.value("est.usrf.f1");
    current->setUsrF1(var.toFloat());
    qDebug() << "Group4 - F1 (Aircraft 2):" << var.toFloat();
    
    var = param.value("est.usrf.f2");
    current->setUsrF2(var.toFloat());
    qDebug() << "Group4 - F2 (Aircraft 2):" << var.toFloat();
    
    var = param.value("est.usrf.f3");
    current->setUsrF3(var.toFloat());
    qDebug() << "Group4 - F3 (Aircraft 2):" << var.toFloat();
    
    var = param.value("est.usrf.f4");
    current->setUsrF4(var.toFloat());
    qDebug() << "Group4 - F4 (Aircraft 2):" << var.toFloat();
    
    var = param.value("est.usrf.f5");
    current->setUsrF5(var.toFloat());
    qDebug() << "Group4 - F5 (Aircraft 2):" << var.toFloat();
    
    var = param.value("est.usrf.f6");
    current->setUsrF6(var.toFloat());
    qDebug() << "Group4 - F6 (Aircraft 2):" << var.toFloat();
    
    var = param.value("est.usrf.f7");
    current->setUsrF7(var.toFloat());
    qDebug() << "Group4 - F7 (Aircraft 2):" << var.toFloat();
    
    var = param.value("est.usrf.f8");
    current->setUsrF8(var.toFloat());
    qDebug() << "Group4 - F8 (Aircraft 2):" << var.toFloat();
    
    var = param.value("est.usrf.f9");
    current->setUsrF9(var.toFloat());
    qDebug() << "Group4 - F9 (Aircraft 2):" << var.toFloat();

    // Group 5
    var = param.value("est.usrc.c1");
    current->setUsrC1(var.toInt());
    qDebug() << "Group5 - C1 (Aircraft 2):" << var.toInt();
    
    var = param.value("est.usrc.c2");
    current->setUsrC2(var.toInt());
    qDebug() << "Group5 - C2 (Aircraft 2):" << var.toInt();
    
    var = param.value("est.usrc.c3");
    current->setUsrC3(var.toInt());
    qDebug() << "Group5 - C3 (Aircraft 2):" << var.toInt();

    // Group 6
    var = param.value("est.usrb.b1");
    bool bVal = (var.toString() == "on");
    current->setUsrB1(bVal);
    qDebug() << "Group6 - B1 (Aircraft 2):" << bVal;
    
    var = param.value("est.usrb.b2");
    bool bVal2 = (var.toString() == "on");
    current->setUsrB2(bVal2);
    qDebug() << "Group6 - B2 (Aircraft 2):" << bVal2;
    
    var = param.value("est.usrb.b3");
    bool bVal3 = (var.toString() == "on");
    current->setUsrB3(bVal3);
    qDebug() << "Group6 - B3 (Aircraft 2):" << bVal3;
    
    var = param.value("est.usrb.b4");
    bool bVal4 = (var.toString() == "on");
    current->setUsrB4(bVal4);
    qDebug() << "Group6 - B4 (Aircraft 2):" << bVal4;

    // BlackBox
    bblCnt++;
    bbrCnt++;

    var = param.value("userb_6");
    if(bblState != var.toBool()) {bblState = var.toBool(); bblCnt = 0; bblUpdate = true; }
    else if(bblCnt >= 50){bblCnt = 0; bblUpdate = false; }

    var = param.value("userb_8");
    if(bbrState != var.toBool()) {bbrState = var.toBool(); bbrCnt = 0; bbrUpdate = true; }
    else if(bbrCnt >= 50){bbrCnt = 0; bbrUpdate = false; }

    if(!m_settings.blackBoxUsed1()) bblUpdate = true;
    if(!m_settings.blackBoxUsed2()) bbrUpdate = true;

    current->setStatusBB(!(bblUpdate && bbrUpdate));

    // Clutch
    auto time = QDateTime::currentDateTime().currentSecsSinceEpoch();
    var = param.value("turret_shoot");
    if(var.toBool() && !current->servo()){
        m_servoTime = time;
        current->setServo(var.toBool());
    }
    else if(m_servoTime + m_settings.servoTimeout() < time){
            current->setServo(var.toBool());
    }

    // Gear
    if(current->rpmRotorReal() != 0){
        qreal gear = static_cast<qreal>(current->rpmEngineReal())/static_cast<qreal>(current->rpmRotorReal());
        auto flag = (gear < m_settings.gearMin() || gear > m_settings.gearMax());

        if(flag && !current->gear()){
            m_gearTime = time;
            current->setGear(flag);
        }
        else if(!flag && current->gear()){
            if(m_gearTime + m_settings.gearTimeout() < time)
                current->setGear(flag);
        }
    }
}