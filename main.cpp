#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "dataread.h"
#include <QQuickStyle>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQuickStyle::setStyle("Material");
    DataRead *pb = new DataRead();
    pb->onClickReportTarget();


    return app.exec();
}
