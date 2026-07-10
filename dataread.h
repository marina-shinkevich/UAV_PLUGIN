#ifndef DATAREAD_H
#define DATAREAD_H

#include <QObject>
#include <QNetworkReply>
#include <QStringList>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QtNetwork>
#include <QUrl>
#include <QVariantMap>

#include <QQmlContext>
#include <QtQuick/QQuickView>
#include <QtQml/QQmlEngine>
#include <QQmlApplicationEngine>

#include "mandalavalues.h"
#include "settings.h"
class DataRead : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int aircraftSelection READ aircraftSelection WRITE setAircraftSelection NOTIFY aircraftSelectionChanged)
    Q_PROPERTY(QString currentAircraftName READ currentAircraftName NOTIFY aircraftSelectionChanged)
    
public:
    explicit DataRead(QObject *parent = nullptr);
    QStringList datalist;

    QUrl url;
    void startRequest(const QUrl &request);
    QMap<QString,QString> param;
    
    // Property getters
    int aircraftSelection() const { return m_aircraftSelection; }
    QString currentAircraftName() const { return m_aircraftSelection == 1 ? "UVH_VT_170" : "VT_25V1"; }

private:
    QQuickView viewer;
    QQmlApplicationEngine engine;
    QUrl source;
    QNetworkAccessManager manager;
    QNetworkReply *reply = nullptr;
    MandalaValues m_report;
    MandalaValues m_report2;  // Второй самолет
    int m_aircraftSelection = 1;  // 1 - первый самолет, 2 - второй самолет
    Settings m_settings;
    QTimer tmrRequest;
    QString data;
    QString lastXmlData;

    bool f_openMsgView = false;
    bool httpRequestAborted;



    //For Black Box
    bool bblUpdate = false;
    bool bbrUpdate = false;
    bool bblState = false;
    bool bbrState = false;
    int bblCnt = 0;
    int bbrCnt = 0;

    //Time
    uint32_t m_servoTime;
    uint32_t m_gearTime;

private slots:
    void refreshConnection();

public slots:
    void httpFinished();
    void httpReadyRead();
    void slotAuthenticationRequired(QNetworkReply *, QAuthenticator *authenticator);
    void onClickReportTarget(void);
    void openReportMsgView(void);
    void closeReportMsgView(void);
    void updateVariables(QString name, QVariant state);

    // переключения между самолетами
    void setAircraftSelection(int aircraft);
    MandalaValues* currentReport(); 

    // обработка данных для каждого 
    void UVH_VT_170();
    void VT_25V1();
    
    //  для принудительного обновления интерфейса
    void refreshInterface();

signals:
    void aircraftSelectionChanged();

};

#endif // DATAREAD_H
