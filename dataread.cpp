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

DataRead::DataRead(QObject *parent) : QObject(parent)
{
    engine.rootContext()->setContextProperty("pb", this);
    engine.rootContext()->setContextProperty("settings", &m_settings);
    engine.rootContext()->setContextProperty("report", &m_report);
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
    url = QUrl("http://127.0.0.1:9080/mandala");
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

    // Mandala Variables Editing
    // ******* Group 1 - Engine *******
    var = param.value("OT");                            //Engine OT
    m_report.setEngineOT(var.toFloat());

    var = param.value("user3");                         //Engine Fuel pressure
    m_report.setEngineFuelPress(var.toFloat(), m_settings.engineFuelPressLimMin(), m_settings.engineFuelPressLimMax());

    var = param.value("ls_roll");                       // first fuel flow sensor
    m_report.setfirstFFSensor(var.toFloat(),m_settings.firstFFSensorLimMin(),m_settings.firstFFSensorLimMax());

    var = param.value("rs_roll");                       // second fuel flow sensor
    m_report.setsecondFFSensor(var.toFloat(),m_settings.secondFFSensorLimMin(),m_settings.secondFFSensorLimMax());

    var = param.value("user1");                         //Engine Gear box temp
    m_report.setEngineGearBoxTemp(var.toFloat());

    var = param.value("OP");                            //Engine OP
    m_report.setEngineOP(var.toFloat(), m_settings.engineOPLimMin(), m_settings.engineOPLimMax());

    var = param.value("ET");                            //Engine ET
    m_report.setEngineET(var.toFloat());

    var = param.value("fuel");                          //Engine_Fuel
    m_report.setEngineFuel(var.toFloat(), m_settings.engineFuelLimMin(), m_settings.engineFuelLimMax());

    //******* Group 2 - EGT *******
    var =  param.value("radar_dx");                     //EGT1
    m_report.setEgt1(var.toInt());

    var =  param.value("user4");                        //EGT2
    m_report.setEgt2(var.toInt());

    var =  param.value("radar_dy");                     //EGT3
    m_report.setEgt3(var.toInt());

    var =  param.value("user5");                        //EGT4
    m_report.setEgt4(var.toInt());

    //******* Group 3 - RPM *******
    var = param.value("rpm");                           //RPM_Rotor  1% - 7.5 RPM; 100% - 510 RPM;
    if(var.toFloat() < 0) var = 0;
    m_report.setRpmRotorReal(var.toInt());
    var = var.toFloat() * 100 / m_settings.rpmRotor100();
    m_report.setRpmRotor(var.toInt());

    var = param.value("user6");                         //RPM_Engine 1% - 75; 100% - 5200;
    if(var.toFloat() < 0) var = 0;
    m_report.setRpmEngineReal(var.toInt());
    var = var.toFloat() * 100 / m_settings.rpmEngine100();
    m_report.setRpmEngine(var.toInt());

    m_report.setRpmEngineWorked(var > 500 ? true : false);

    var = param.value("ctr_throttle");  //RPM_Throttle
    m_report.setRpmThrottle(var.toFloat()*100.0);

    var = param.value("rc_throttle");
    m_report.setRcThrottle(var.toFloat());

    //******* Group 4 - TCU *******
    var = param.value("radar_Vx");                      //TCU_Map
    m_report.setTcuMap(var.toFloat());

    var = param.value("userb_4");                       //TCU_Warn
    m_report.setTcuWarn(var.toBool());

    var = param.value("userb_5");                       //TCU_Caution
    m_report.setTcuCaution(var.toBool());

    //******* Group 5 - Status *******
    var = param.value("radar_Vz");                      //Status_AGL_ERR
    m_report.setStatusULanding(var.toBool());

    var = param.value("userb_3");                       //Status_ERS_ARM
    m_report.setStatusErsArm(!var.toBool());

    var = param.value("turret_sw2");                    //Status_Frame_PRS
    m_report.setStatusFramePrs(!var.toBool());

    var = param.value("ctrb_ers");                      //Status_ERS_PYRO
    m_report.setStatusErsPyro(var.toBool());

    //******* BlackBox *******
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

    m_report.setStatusBB(!(bblUpdate && bbrUpdate));

    //******* Group 6 - Coolling *******
    var = param.value("Ip");                            //Coolling_FAN_AUTO - 0bit; FAN1 - 1bit; FAN2 - 2bit;
    m_report.setFanAuto(var.toInt() & 0x01);
    m_report.setFan1(var.toInt() & (0x01<<1));
    m_report.setFan2(var.toInt() & (0x01<<2));

    var = param.value("turret_sw3");                    //Coolling_level
    m_report.setCoolLvl(!var.toBool());

    //******* Group 7 - Clutch *******
    var = param.value("user2");                         //Clutch_state
    m_report.setClutchVoltage(var.toFloat());

    var = param.value("sw_sw3");                        //Clutch_Control
    m_report.setClutchCtrl(var.toBool());

    var = param.value("userb_7");                       //Clutch_state
    m_report.setClutchState(var.toBool());

    var = param.value("turret_sw1");                    //Clutch_fuse
    m_report.setClutchFuse(var.toBool());

    auto time = QDateTime::currentDateTime().currentSecsSinceEpoch();
    var = param.value("turret_shoot");                  //Servo
    if(var.toBool() && !m_report.servo()){
        m_servoTime = time;
        m_report.setServo(var.toBool());
    }
    else if(m_servoTime + m_settings.servoTimeout() < time){
            m_report.setServo(var.toBool());
    }

    //******* Gear *******
    if(m_report.rpmRotorReal() != 0){
        qreal gear = static_cast<qreal>(m_report.rpmEngineReal())/static_cast<qreal>(m_report.rpmRotorReal());
        auto flag = (gear < m_settings.gearMin() || gear > m_settings.gearMax());

        if(flag && !m_report.gear()){
            m_gearTime = time;
            m_report.setGear(flag);
        }
        else if(!flag && m_report.gear()){
            if(m_gearTime + m_settings.gearTimeout() < time)
                m_report.setGear(flag);
        }
    }
    //******* Group 8 - Alternator *******
    var = param.value("Vs");                                //Alternator_Servo_voltage
    m_report.setAltSrvVolt(var.toFloat());

    var = param.value("Vp");                                //Alternator_Bat_12V_1
    m_report.setAltBat12v1(var.toFloat());

    var = param.value("Vm");                                //Alternator_Bat_12V_2
    m_report.setAltBat12v2(var.toFloat());

    var = param.value("userb_1");                           //Alternator_RECT_LAMP
    m_report.setAltRectLamp(var.toBool());

    var = param.value("userb_2");                           //Alternator_ALT_LAMP

    m_report.setAltAltLamp(var.toBool());

    //******* Group 9 - Ignition *******
    var = param.value("power_ignition");                    //Ignition_ignition1
    m_report.setIgn1(var.toFloat());

    var = param.value("sw_sw1");                            //Ignition_ignition2
    m_report.setIgn2(var.toFloat());

    bool starterFlag;
    var = param.value("ctrb_starter");                      //Ignition_starter
    starterFlag = var.toBool();
    var = param.value("sw_starter");                        //Ignition_starter
    starterFlag |= var.toBool();
    m_report.setIgnStarter(starterFlag);

    var = param.value("ctr_mixture");                       //Ignition_Choke
    m_report.setIgnChoke(var.toFloat());

    var = param.value("sw_sw2");                            //Ignition_FP
    m_report.setIgnFp(var.toFloat());

    //******* Group 10 - Lights *******
    var = param.value("sw_taxi");                           //Lights_Taxi
    m_report.setLightTaxi(var.toBool());

    var = param.value("sw_lights");                         //Lights_Navigation
    m_report.setLightNav(var.toBool());

    var = param.value("radar_dz");                          //reserverpm
    m_report.setReserveRpm(var.toInt() == 3);

    //******* Group 10 - Other *******
    var = param.value("turret_sw4");
    m_report.setChipDetector(!var.toBool());

    var = param.value("ctrb_gear");
    m_report.setGMode(var.toBool());

    double trottle = param.value("ctr_throttle").toDouble();
    double ailerons = param.value("ctr_ailerons").toDouble();
    double elevator = param.value("ctr_elevator").toDouble();
    double rudder = param.value("ctr_rudder").toDouble();

    if(trottle < 0 || trottle > 0.95 || ailerons < -0.95 || ailerons > 0.95 ||
       elevator < -0.95 || elevator > 0.95 || rudder < -0.95 || rudder > 0.95)
        m_report.setCtrLim(true);
    else
        m_report.setCtrLim(false);

    m_report.updateLimitFlag();

}

void DataRead::slotAuthenticationRequired(QNetworkReply *, QAuthenticator *authenticator)
{

}

void DataRead::updateVariables(QString name, QVariant state)
{
    qDebug() << "updateVariables" << name << state;
    QString reqURL = "http://127.0.0.1:9080/mandala";
    QString reqParam = name;
    QVariant temp = state;
    QString reqValue = temp.toString();

    QString reqFull = reqURL +"?"+ reqParam + "=" + reqValue;
    qDebug() << reqFull;
    reply = manager.get(QNetworkRequest(reqFull));

}
