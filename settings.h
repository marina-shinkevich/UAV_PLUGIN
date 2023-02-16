#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>

class Settings : public QObject
{
    Q_OBJECT

    Q_PROPERTY(qreal engineOTMin READ engineOTMin CONSTANT)
    Q_PROPERTY(qreal engineOTLimMin READ engineOTLimMin CONSTANT)
    Q_PROPERTY(qreal engineOTLimMax READ engineOTLimMax CONSTANT)
    Q_PROPERTY(qreal engineOTMax READ engineOTMax CONSTANT)

    Q_PROPERTY(qreal engineFuelPressMin READ engineFuelPressMin CONSTANT)
    Q_PROPERTY(qreal engineFuelPressLimMin READ engineFuelPressLimMin CONSTANT)
    Q_PROPERTY(qreal engineFuelPressLimMax READ engineFuelPressLimMax CONSTANT)
    Q_PROPERTY(qreal engineFuelPressMax READ engineFuelPressMax CONSTANT)

    Q_PROPERTY(qreal firstFFSensorMin READ firstFFSensorMin CONSTANT)
    Q_PROPERTY(qreal firstFFSensorLimMin READ firstFFSensorLimMin CONSTANT)
    Q_PROPERTY(qreal firstFFSensorMax READ firstFFSensorMax CONSTANT)
    Q_PROPERTY(qreal firstFFSensorLimMax READ firstFFSensorLimMax CONSTANT)

    Q_PROPERTY(qreal secondFFSensorMin READ secondFFSensorMin CONSTANT)
    Q_PROPERTY(qreal secondFFSensorLimMin READ secondFFSensorLimMin CONSTANT)
    Q_PROPERTY(qreal secondFFSensorMax READ secondFFSensorMax CONSTANT)
    Q_PROPERTY(qreal secondFFSensorLimMax READ secondFFSensorLimMax CONSTANT)

    Q_PROPERTY(int engineGearBoxTempMin READ engineGearBoxTempMin CONSTANT)
    Q_PROPERTY(int engineGearBoxTempLimMin READ engineGearBoxTempLimMin CONSTANT)
    Q_PROPERTY(int engineGearBoxTempLimMax READ engineGearBoxTempLimMax CONSTANT)
    Q_PROPERTY(int engineGearBoxTempMax READ engineGearBoxTempMax CONSTANT)

    Q_PROPERTY(qreal engineOPMin READ engineOPMin CONSTANT)
    Q_PROPERTY(qreal engineOPLimMin READ engineOPLimMin CONSTANT)
    Q_PROPERTY(qreal engineOPLimMax READ engineOPLimMax CONSTANT)
    Q_PROPERTY(qreal engineOPMax READ engineOPMax CONSTANT)

    Q_PROPERTY(int engineETMin READ engineETMin CONSTANT)
    Q_PROPERTY(int engineETLimMin READ engineETLimMin CONSTANT)
    Q_PROPERTY(int engineETLimMax READ engineETLimMax CONSTANT)
    Q_PROPERTY(int engineETMax READ engineETMax CONSTANT)

    Q_PROPERTY(qreal engineFuelMin READ engineFuelMin CONSTANT)
    Q_PROPERTY(qreal engineFuelLimMin READ engineFuelLimMin CONSTANT)
    Q_PROPERTY(qreal engineFuelLimMax READ engineFuelLimMax CONSTANT)
    Q_PROPERTY(qreal engineFuelMax READ engineFuelMax CONSTANT)

    Q_PROPERTY(int egtMin READ egtMin CONSTANT)
    Q_PROPERTY(int egtLimMin READ egtLimMin CONSTANT)
    Q_PROPERTY(int egtLimMax READ egtLimMax CONSTANT)
    Q_PROPERTY(int egtMax READ egtMax CONSTANT)

    Q_PROPERTY(qreal tcuMapMin READ tcuMapMin CONSTANT)
    Q_PROPERTY(qreal tcuMapLimMin READ tcuMapLimMin CONSTANT)
    Q_PROPERTY(qreal tcuMapLimMax READ tcuMapLimMax CONSTANT)
    Q_PROPERTY(qreal tcuMapMax READ tcuMapMax CONSTANT)

    Q_PROPERTY(int rpmMax READ rpmMax CONSTANT)
    Q_PROPERTY(int rpmUpRed READ rpmUpRed CONSTANT)
    Q_PROPERTY(int rpmUpYellow READ rpmUpYellow CONSTANT)
    Q_PROPERTY(int rpmDownYellow READ rpmDownYellow CONSTANT)
    Q_PROPERTY(int rpmDownRed READ rpmDownRed CONSTANT)
    Q_PROPERTY(int rpmMin READ rpmMin CONSTANT)


//    Q_PROPERTY(qreal rpmRotor100 READ rpmRotor100 CONSTANT)
//    Q_PROPERTY(qreal rpmEngine100 READ rpmEngine100 CONSTANT)
//    Q_PROPERTY(bool blackBoxUsed1 READ blackBoxUsed1 CONSTANT)
//    Q_PROPERTY(bool blackBoxUsed2 READ blackBoxUsed2 CONSTANT)

public:
    explicit Settings(QObject *parent = nullptr);

    qreal engineOTMin(){return m_engineOTMin;}
    qreal engineOTLimMin(){return m_engineOTLimMin;}
    qreal engineOTLimMax(){return m_engineOTLimMax;}
    qreal engineOTMax(){return m_engineOTMax;}

    qreal engineFuelPressMin(){return m_engineFuelPressMin;}
    qreal engineFuelPressLimMin(){return m_engineFuelPressLimMin;}
    qreal engineFuelPressLimMax(){return m_engineFuelPressLimMax;}
    qreal engineFuelPressMax(){return m_engineFuelPressMax;}

    qreal firstFFSensorMin(){return m_firstFFSensorMin;}
    qreal firstFFSensorLimMin(){return m_firstFFSensorLimMin;}
    qreal firstFFSensorMax(){return m_firstFFSensorMax;}
    qreal firstFFSensorLimMax(){return m_firstFFSensorLimMax;}

    qreal secondFFSensorMin(){return m_secondFFSensorMin;}
    qreal secondFFSensorLimMin(){return m_secondFFSensorLimMin;}
    qreal secondFFSensorMax(){return m_secondFFSensorMax;}
    qreal secondFFSensorLimMax(){return m_secondFFSensorLimMax;}


    int engineGearBoxTempMin(){return m_engineGearBoxTempMin;}
    int engineGearBoxTempLimMin(){return m_engineGearBoxTempLimMin;}
    int engineGearBoxTempLimMax(){return m_engineGearBoxTempLimMax;}
    int engineGearBoxTempMax(){return m_engineGearBoxTempMax;}

    qreal engineOPMin(){return m_engineOPMin;}
    qreal engineOPLimMin(){return m_engineOPLimMin;}
    qreal engineOPLimMax(){return m_engineOPLimMax;}
    qreal engineOPMax(){return m_engineOPMax;}

    int engineETMin(){return m_engineETMin;}
    int engineETLimMin(){return m_engineETLimMin;}
    int engineETLimMax(){return m_engineETLimMax;}
    int engineETMax(){return m_engineETMax;}

    qreal engineFuelMin(){return m_engineFuelMin;}
    qreal engineFuelLimMin(){return m_engineFuelLimMin;}
    qreal engineFuelLimMax(){return m_engineFuelLimMax;}
    qreal engineFuelMax(){return m_engineFuelMax;}

    int egtMin(){return m_egtMin;}
    int egtLimMin(){return m_egtLimMin;}
    int egtLimMax(){return m_egtLimMax;}
    int egtMax(){return m_egtMax;}

    qreal tcuMapMin(){return m_tcuMapMin;}
    qreal tcuMapLimMin(){return m_tcuMapLimMin;}
    qreal tcuMapLimMax(){return m_tcuMapLimMax;}
    qreal tcuMapMax(){return m_tcuMapMax;}

    qreal rpmRotor100(){return m_rpmRotor100;}
    qreal rpmEngine100(){return m_rpmEngine100;}

    bool blackBoxUsed1(){return m_blackBoxUsed1;}
    bool blackBoxUsed2(){return m_blackBoxUsed2;}

    qreal gearMin(){return m_gearMin;}
    qreal gearMax(){return m_gearMax;}
    int gearTimeout(){return m_gearTimeout;}
    int servoTimeout(){return m_servoTimeout;}

    int rpmMax(){return m_rpmMax;}
    int rpmUpRed(){return m_rpmUpRed;}
    int rpmUpYellow(){return m_rpmUpYellow;}
    int rpmDownYellow(){return m_rpmDownYellow;}
    int rpmDownRed(){return m_rpmDownRed;}
    int rpmMin(){return m_rpmMin;}


signals:

private:
    class Field{
        public:
        static constexpr const char *description = "description";
        static constexpr const char *value = "value";

        static constexpr const char *engineOTMin = "engineOTMin";
        static constexpr const char *engineOTLimMin = "engineOTLimMin";
        static constexpr const char *engineOTLimMax = "engineOTLimMax";
        static constexpr const char *engineOTMax = "engineOTMax";

        static constexpr const char *engineFuelPressMin = "engineFuelPressMin";
        static constexpr const char *engineFuelPressLimMin = "engineFuelPressLimMin";
        static constexpr const char *engineFuelPressLimMax = "engineFuelPressLimMax";
        static constexpr const char *engineFuelPressMax = "engineFuelPressMax";

        static constexpr const char *firstFFSensorMin = "firstFFSensorMin";
        static constexpr const char *firstFFSensorLimMin = "firstFFSensorLimMin";
        static constexpr const char *firstFFSensorMax = "firstFFSensorMax";
        static constexpr const char *firstFFSensorLimMax = "firstFFSensorLimMax";

        static constexpr const char *secondFFSensorMin = "secondFFSensorMin";
        static constexpr const char *secondFFSensorLimMin = "secondFFSensorLimMin";
        static constexpr const char *secondFFSensorMax = "secondFFSensorMax";
        static constexpr const char *secondFFSensorLimMax = "secondFFSensorLimMax";

        static constexpr const char *engineGearBoxTempMin = "engineGearBoxTempMin";
        static constexpr const char *engineGearBoxTempLimMin = "engineGearBoxTempLimMin";
        static constexpr const char *engineGearBoxTempLimMax = "engineGearBoxTempLimMax";
        static constexpr const char *engineGearBoxTempMax = "engineGearBoxTempMax";

        static constexpr const char *engineOPMin = "engineOPMin";
        static constexpr const char *engineOPLimMin = "engineOPLimMin";
        static constexpr const char *engineOPLimMax = "engineOPLimMax";
        static constexpr const char *engineOPMax = "engineOPMax";

        static constexpr const char *engineETMin = "engineETMin";
        static constexpr const char *engineETLimMin = "engineETLimMin";
        static constexpr const char *engineETLimMax = "engineETLimMax";
        static constexpr const char *engineETMax = "engineETMax";

        static constexpr const char *engineFuelMin = "engineFuelMin";
        static constexpr const char *engineFuelLimMin = "engineFuelLimMin";
        static constexpr const char *engineFuelLimMax = "engineFuelLimMax";
        static constexpr const char *engineFuelMax = "engineFuelMax";

        static constexpr const char *egtMin = "egtMin";
        static constexpr const char *egtLimMin = "egtLimMin";
        static constexpr const char *egtLimMax = "egtLimMax";
        static constexpr const char *egtMax = "egtMax";

        static constexpr const char *tcuMapMin = "tcuMapMin";
        static constexpr const char *tcuMapLimMin = "tcuMapLimMin";
        static constexpr const char *tcuMapLimMax = "tcuMapLimMax";
        static constexpr const char *tcuMapMax = "tcuMapMax";

        static constexpr const char *rpmRotor100 = "rpmRotor100";
        static constexpr const char *rpmEngine100 = "rpmEngine100";

        static constexpr const char *blackBoxUsed1 = "blackBoxUsed1";
        static constexpr const char *blackBoxUsed2 = "blackBoxUsed2";

        static constexpr const char *gearMin = "gearMin";
        static constexpr const char *gearMax = "gearMax";
        static constexpr const char *gearTimeout = "gearTimeout";
        static constexpr const char *servoTimeout = "servoTimeout";

        static constexpr const char *rpmMin = "rpmMin";
        static constexpr const char *rpmUpRed = "rpmUpRed";
        static constexpr const char *rpmUpYellow = "rpmUpYellow";
        static constexpr const char *rpmDownYellow = "rpmDownYellow";
        static constexpr const char *rpmDownRed = "rpmDownRed";
        static constexpr const char *rpmMax = "rpmMax";


    };

    qreal m_engineOTMin = 50;
    qreal m_engineOTLimMin = 90;
    qreal m_engineOTLimMax = 110;
    qreal m_engineOTMax = 130;

    qreal m_engineFuelPressMin = 2;
    qreal m_engineFuelPressLimMin = 2.5;
    qreal m_engineFuelPressLimMax = 3.2;
    qreal m_engineFuelPressMax = 3.5;

    qreal m_firstFFSensorMin = 40;
    qreal m_firstFFSensorLimMin = 47;
    qreal m_firstFFSensorMax = 60;
    qreal m_firstFFSensorLimMax = 53;

    qreal m_secondFFSensorMin = 40;
    qreal m_secondFFSensorLimMin = 47;
    qreal m_secondFFSensorMax = 60;
    qreal m_secondFFSensorLimMax = 53;


    int m_engineGearBoxTempMin = 80;
    int m_engineGearBoxTempLimMin = 90;
    int m_engineGearBoxTempLimMax = 110;
    int m_engineGearBoxTempMax = 130;

    qreal m_engineOPMin = 1;
    qreal m_engineOPLimMin = 1.5;
    qreal m_engineOPLimMax = 6;
    qreal m_engineOPMax = 7;

    int m_engineETMin = 70;
    int m_engineETLimMin = 75;
    int m_engineETLimMax = 110;
    int m_engineETMax = 120;

    qreal m_engineFuelMin = 0;
    qreal m_engineFuelLimMin = 10;
    qreal m_engineFuelLimMax = 95;
    qreal m_engineFuelMax = 190;

    int m_egtMin = 500;
    int m_egtLimMin = 510;
    int m_egtLimMax = 950;
    int m_egtMax = 1000;

    qreal m_tcuMapMin = 40;
    qreal m_tcuMapLimMin = 50;
    qreal m_tcuMapLimMax = 135;
    qreal m_tcuMapMax = 140;

    qreal m_rpmRotor100 = 555;
    qreal m_rpmEngine100 = 5272;

    bool m_blackBoxUsed1 = true;
    bool m_blackBoxUsed2 = false;

    qreal m_gearMin = 9;
    qreal m_gearMax = 10;
    int m_gearTimeout = 1;
    int m_servoTimeout = 2;

    void initialization();
    bool read(QString path);
    void create(QString path);

    int m_rpmMax = 112;
    int m_rpmUpRed = 110;
    int m_rpmUpYellow = 104;
    int m_rpmDownYellow = 96;
    int m_rpmDownRed = 90;
    int m_rpmMin = 88;
};

#endif // SETTINGS_H
