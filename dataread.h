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
public:
    explicit DataRead(QObject *parent = nullptr);
    QStringList datalist;

    QUrl url;
    void startRequest(const QUrl &request);
    QMap<QString,QString> param;

private:
    QQuickView viewer;
    QQmlApplicationEngine engine;
    QUrl source;
    QNetworkAccessManager manager;
    QNetworkReply *reply = nullptr;
    MandalaValues m_report;
    Settings m_settings;
    QTimer tmrRequest;
    QString data;

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

signals:

};

#endif // DATAREAD_H
