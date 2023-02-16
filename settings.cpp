#include "settings.h"
#include <QStandardPaths>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDir>
#include <QFile>
#include <QDebug>

Settings::Settings(QObject *parent) : QObject(parent)
{
    initialization();
}

void Settings::initialization()
{
    QString path = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/UAVOS/Configs/";
    QDir dir(path);
    if(!dir.exists()) dir.mkdir(path);

    path += "ecam.json";
    QFile file(path);

    if(!file.exists()){
        create(path);
    }

    if(!read(path))
        create(path);
}

bool Settings::read(QString path)
{
    QFile file(path);
    bool status = true;

    if(file.open(QIODevice::ReadOnly)){
        QJsonObject json = QJsonDocument::fromJson(file.readAll()).object();

        m_engineOTMin = json.value(Field::engineOTMin).toObject().value(Field::value).toDouble();
        m_engineOTLimMin = json.value(Field::engineOTLimMin).toObject().value(Field::value).toDouble();
        m_engineOTLimMax = json.value(Field::engineOTLimMax).toObject().value(Field::value).toDouble();
        m_engineOTMax = json.value(Field::engineOTMax).toObject().value(Field::value).toDouble();

        m_engineFuelPressMin = json.value(Field::engineFuelPressMin).toObject().value(Field::value).toDouble();
        m_engineFuelPressLimMin = json.value(Field::engineFuelPressLimMin).toObject().value(Field::value).toDouble();
        m_engineFuelPressLimMax = json.value(Field::engineFuelPressLimMax).toObject().value(Field::value).toDouble();
        m_engineFuelPressMax = json.value(Field::engineFuelPressMax).toObject().value(Field::value).toDouble();

        m_firstFFSensorMin = json.value(Field::firstFFSensorMin).toObject().value(Field::value).toDouble();
        m_firstFFSensorLimMin = json.value(Field::firstFFSensorLimMin).toObject().value(Field::value).toDouble();
        m_firstFFSensorMax = json.value(Field::firstFFSensorMax).toObject().value(Field::value).toDouble();
        m_firstFFSensorLimMax = json.value(Field::firstFFSensorLimMax).toObject().value(Field::value).toDouble();

        m_secondFFSensorMin = json.value(Field::secondFFSensorMin).toObject().value(Field::value).toDouble();
        m_secondFFSensorLimMin = json.value(Field::secondFFSensorLimMin).toObject().value(Field::value).toDouble();
        m_secondFFSensorMax = json.value(Field::secondFFSensorMax).toObject().value(Field::value).toDouble();
        m_secondFFSensorLimMax = json.value(Field::secondFFSensorLimMax).toObject().value(Field::value).toDouble();


        m_engineGearBoxTempMin = json.value(Field::engineGearBoxTempMin).toObject().value(Field::value).toInt();
        m_engineGearBoxTempLimMin = json.value(Field::engineGearBoxTempLimMin).toObject().value(Field::value).toInt();
        m_engineGearBoxTempLimMax = json.value(Field::engineGearBoxTempLimMax).toObject().value(Field::value).toInt();
        m_engineGearBoxTempMax = json.value(Field::engineGearBoxTempMax).toObject().value(Field::value).toInt();

        m_engineOPMin = json.value(Field::engineOPMin).toObject().value(Field::value).toDouble();
        m_engineOPLimMin = json.value(Field::engineOPLimMin).toObject().value(Field::value).toDouble();
        m_engineOPLimMax = json.value(Field::engineOPLimMax).toObject().value(Field::value).toDouble();
        m_engineOPMax = json.value(Field::engineOPMax).toObject().value(Field::value).toDouble();

        m_engineETMin = json.value(Field::engineETMin).toObject().value(Field::value).toInt();
        m_engineETLimMin = json.value(Field::engineETLimMin).toObject().value(Field::value).toInt();
        m_engineETLimMax = json.value(Field::engineETLimMax).toObject().value(Field::value).toInt();
        m_engineETMax = json.value(Field::engineETMax).toObject().value(Field::value).toInt();

        m_engineFuelMin = json.value(Field::engineFuelMin).toObject().value(Field::value).toDouble();
        m_engineFuelLimMin = json.value(Field::engineFuelLimMin).toObject().value(Field::value).toDouble();
        m_engineFuelLimMax = json.value(Field::engineFuelLimMax).toObject().value(Field::value).toDouble();
        m_engineFuelMax = json.value(Field::engineFuelMax).toObject().value(Field::value).toDouble();

        m_egtMin = json.value(Field::egtMin).toObject().value(Field::value).toInt();
        m_egtLimMin = json.value(Field::egtLimMin).toObject().value(Field::value).toInt();
        m_egtLimMax = json.value(Field::egtLimMax).toObject().value(Field::value).toInt();
        m_egtMax = json.value(Field::egtMax).toObject().value(Field::value).toInt();

        m_tcuMapMin = json.value(Field::tcuMapMin).toObject().value(Field::value).toDouble();
        m_tcuMapLimMin = json.value(Field::tcuMapLimMin).toObject().value(Field::value).toDouble();
        m_tcuMapLimMax = json.value(Field::tcuMapLimMax).toObject().value(Field::value).toDouble();
        m_tcuMapMax = json.value(Field::tcuMapMax).toObject().value(Field::value).toDouble();

        m_rpmRotor100 = json.value(Field::rpmRotor100).toObject().value(Field::value).toDouble();
        m_rpmEngine100 = json.value(Field::rpmEngine100).toObject().value(Field::value).toDouble();

        m_blackBoxUsed1 = json.value(Field::blackBoxUsed1).toObject().value(Field::value).toBool();
        m_blackBoxUsed2 = json.value(Field::blackBoxUsed2).toObject().value(Field::value).toBool();

        m_gearMin = json.value(Field::gearMin).toObject().value(Field::value).toDouble();
        m_gearMax = json.value(Field::gearMax).toObject().value(Field::value).toDouble();
        m_gearTimeout = json.value(Field::gearTimeout).toObject().value(Field::value).toInt();
        m_servoTimeout = json.value(Field::servoTimeout).toObject().value(Field::value).toInt();

        if(json.contains(Field::rpmMax))
            m_rpmMax = json.value(Field::rpmMax).toObject().value(Field::value).toInt();
        if(json.contains(Field::rpmUpRed))
            m_rpmUpRed = json.value(Field::rpmUpRed).toObject().value(Field::value).toInt();
        if(json.contains(Field::rpmUpYellow))
            m_rpmUpYellow = json.value(Field::rpmUpYellow).toObject().value(Field::value).toInt();
        if(json.contains(Field::rpmDownYellow))
            m_rpmDownYellow = json.value(Field::rpmDownYellow).toObject().value(Field::value).toInt();
        if(json.contains(Field::rpmDownRed))
            m_rpmDownRed = json.value(Field::rpmDownRed).toObject().value(Field::value).toInt();
        if(json.contains(Field::rpmMin))
            m_rpmMin = json.value(Field::rpmMin).toObject().value(Field::value).toInt();

        if(!json.contains(Field::rpmMax) || !json.contains(Field::rpmMin) ||
           !json.contains(Field::rpmUpRed) || !json.contains(Field::rpmUpYellow) ||
           !json.contains(Field::rpmDownYellow) || !json.contains(Field::rpmDownRed)){
            status = false;
        }

    }
    return status;
}

void Settings::create(QString path)
{
    QJsonObject settingsObject;
    QJsonObject jsonProp;

    jsonProp.insert(Field::value, m_engineOTMin); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::engineOTMin, jsonProp);
    jsonProp.insert(Field::value, m_engineOTLimMin); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::engineOTLimMin, jsonProp);
    jsonProp.insert(Field::value, m_engineOTLimMax); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::engineOTLimMax, jsonProp);
    jsonProp.insert(Field::value, m_engineOTMax); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::engineOTMax, jsonProp);

    jsonProp.insert(Field::value, m_engineFuelPressMin); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::engineFuelPressMin, jsonProp);
    jsonProp.insert(Field::value, m_engineFuelPressLimMin); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::engineFuelPressLimMin, jsonProp);
    jsonProp.insert(Field::value, m_engineFuelPressLimMax); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::engineFuelPressLimMax, jsonProp);
    jsonProp.insert(Field::value, m_engineFuelPressMax); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::engineFuelPressMax, jsonProp);

    jsonProp.insert(Field::value, m_firstFFSensorMin); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::firstFFSensorMin, jsonProp);
    jsonProp.insert(Field::value, m_firstFFSensorLimMin); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::firstFFSensorLimMin, jsonProp);
    jsonProp.insert(Field::value, m_firstFFSensorMax); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::firstFFSensorMax, jsonProp);
    jsonProp.insert(Field::value, m_firstFFSensorLimMax); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::firstFFSensorLimMax, jsonProp);

    jsonProp.insert(Field::value, m_secondFFSensorMin); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::secondFFSensorMin, jsonProp);
    jsonProp.insert(Field::value, m_secondFFSensorLimMin); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::secondFFSensorLimMin, jsonProp);
    jsonProp.insert(Field::value, m_secondFFSensorMax); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::secondFFSensorMax, jsonProp);
    jsonProp.insert(Field::value, m_secondFFSensorLimMax); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::secondFFSensorLimMax, jsonProp);

    jsonProp.insert(Field::value, m_engineGearBoxTempMin); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::engineGearBoxTempMin, jsonProp);
    jsonProp.insert(Field::value, m_engineGearBoxTempLimMin); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::engineGearBoxTempLimMin, jsonProp);
    jsonProp.insert(Field::value, m_engineGearBoxTempLimMax); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::engineGearBoxTempLimMax, jsonProp);
    jsonProp.insert(Field::value, m_engineGearBoxTempMax); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::engineGearBoxTempMax, jsonProp);

    jsonProp.insert(Field::value, m_engineOPMin); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::engineOPMin, jsonProp);
    jsonProp.insert(Field::value, m_engineOPLimMin); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::engineOPLimMin, jsonProp);
    jsonProp.insert(Field::value, m_engineOPLimMax); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::engineOPLimMax, jsonProp);
    jsonProp.insert(Field::value, m_engineOPMax); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::engineOPMax, jsonProp);

    jsonProp.insert(Field::value, m_engineETMin); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::engineETMin, jsonProp);
    jsonProp.insert(Field::value, m_engineETLimMin); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::engineETLimMin, jsonProp);
    jsonProp.insert(Field::value, m_engineETLimMax); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::engineETLimMax, jsonProp);
    jsonProp.insert(Field::value, m_engineETMax); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::engineETMax, jsonProp);

    jsonProp.insert(Field::value, m_engineFuelMin); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::engineFuelMin, jsonProp);
    jsonProp.insert(Field::value, m_engineFuelLimMin); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::engineFuelLimMin, jsonProp);
    jsonProp.insert(Field::value, m_engineFuelLimMax); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::engineFuelLimMax, jsonProp);
    jsonProp.insert(Field::value, m_engineFuelMax); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::engineFuelMax, jsonProp);

    jsonProp.insert(Field::value, m_egtMin); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::egtMin, jsonProp);
    jsonProp.insert(Field::value, m_egtLimMin); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::egtLimMin, jsonProp);
    jsonProp.insert(Field::value, m_egtLimMax); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::egtLimMax, jsonProp);
    jsonProp.insert(Field::value, m_egtMax); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::egtMax, jsonProp);

    jsonProp.insert(Field::value, m_tcuMapMin); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::tcuMapMin, jsonProp);
    jsonProp.insert(Field::value, m_tcuMapLimMin); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::tcuMapLimMin, jsonProp);
    jsonProp.insert(Field::value, m_tcuMapLimMax); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::tcuMapLimMax, jsonProp);
    jsonProp.insert(Field::value, m_tcuMapMax); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::tcuMapMax, jsonProp);

    jsonProp.insert(Field::value, m_rpmRotor100); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::rpmRotor100, jsonProp);
    jsonProp.insert(Field::value, m_rpmEngine100); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::rpmEngine100, jsonProp);

    jsonProp.insert(Field::value, m_blackBoxUsed1); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::blackBoxUsed1, jsonProp);
    jsonProp.insert(Field::value, m_blackBoxUsed2); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::blackBoxUsed2, jsonProp);

    jsonProp.insert(Field::value, m_gearMin); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::gearMin, jsonProp);
    jsonProp.insert(Field::value, m_gearMax); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::gearMax, jsonProp);
    jsonProp.insert(Field::value, m_gearTimeout); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::gearTimeout, jsonProp);
    jsonProp.insert(Field::value, m_servoTimeout); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::servoTimeout, jsonProp);

    jsonProp.insert(Field::value, m_rpmMax); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::rpmMax, jsonProp);
    jsonProp.insert(Field::value, m_rpmUpRed); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::rpmUpRed, jsonProp);
    jsonProp.insert(Field::value, m_rpmUpYellow); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::rpmUpYellow, jsonProp);
    jsonProp.insert(Field::value, m_rpmDownYellow); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::rpmDownYellow, jsonProp);
    jsonProp.insert(Field::value, m_rpmDownRed); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::rpmDownRed, jsonProp);
    jsonProp.insert(Field::value, m_rpmMin); jsonProp.insert(Field::description, "");
    settingsObject.insert(Field::rpmMin, jsonProp);

    QFile saveFile(path);
    if (saveFile.open(QIODevice::WriteOnly)) {
        QJsonDocument saveDoc(settingsObject);
        saveFile.write(saveDoc.toJson());
    }
}














