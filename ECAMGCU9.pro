QT += quick widgets core
QT += qml quickcontrols2 xml

CONFIG += c++11

#DESTDIR= $${PWD}/AppDir

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        dataread.cpp \
        dialitem.cpp \
        main.cpp \
        mandalavalues.cpp \
        settings.cpp

RESOURCES += qml.qrc

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    dataread.h \
    dialitem.h \
    mandalavalues.h \
    settings.h
