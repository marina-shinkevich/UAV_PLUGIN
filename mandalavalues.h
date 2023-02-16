#ifndef MANDALAVALUES_H
#define MANDALAVALUES_H

#include <QObject>
#include <QMap>

class MandalaValues : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool statusULanding READ statusULanding NOTIFY statusULandingChanged)
    Q_PROPERTY(bool statusErsArm READ statusErsArm NOTIFY statusErsArmChanged)
    Q_PROPERTY(bool statusFramePrs READ statusFramePrs NOTIFY statusFramePrsChanged)
    Q_PROPERTY(bool statusErsPyro READ statusErsPyro NOTIFY statusErsPyroChanged)
    Q_PROPERTY(bool statusBB READ statusBB NOTIFY statusBBChanged)

    Q_PROPERTY(bool fanAuto READ fanAuto NOTIFY fanAutoChanged)
    Q_PROPERTY(bool fan1 READ fan1 NOTIFY fan1Changed)
    Q_PROPERTY(bool fan2 READ fan2 NOTIFY fan2Changed)
    Q_PROPERTY(bool coolLvl READ coolLvl NOTIFY coolLvlChanged)

    Q_PROPERTY(qreal engineOT READ engineOT NOTIFY engineOTChanged)
    Q_PROPERTY(qreal engineFuelPress READ engineFuelPress NOTIFY engineFuelPressChanged)
    Q_PROPERTY(qreal firstFFSensor READ firstFFSensor NOTIFY firstFFSensorChanged)
    Q_PROPERTY(qreal secondFFSensor READ secondFFSensor NOTIFY secondFFSensorChanged)
    Q_PROPERTY(int engineGearBoxTemp READ engineGearBoxTemp NOTIFY engineGearBoxTempChanged)
    Q_PROPERTY(qreal engineOP READ engineOP NOTIFY engineOPChanged)
    Q_PROPERTY(int engineET READ engineET NOTIFY engineETChanged)
    Q_PROPERTY(qreal engineFuel READ engineFuel NOTIFY engineFuelChanged)

    Q_PROPERTY(int egt1 READ egt1 NOTIFY egt1Changed)
    Q_PROPERTY(int egt2 READ egt2 NOTIFY egt2Changed)
    Q_PROPERTY(int egt3 READ egt3 NOTIFY egt3Changed)
    Q_PROPERTY(int egt4 READ egt4 NOTIFY egt4Changed)

    Q_PROPERTY(qreal rpmRotor READ rpmRotor NOTIFY rpmRotorChanged)
    Q_PROPERTY(qreal rpmEngine READ rpmEngine NOTIFY rpmEngineChanged)
    Q_PROPERTY(int rpmRotorReal READ rpmRotorReal NOTIFY rpmRotorRealChanged)
    Q_PROPERTY(int rpmEngineReal READ rpmEngineReal NOTIFY rpmEngineRealChanged)

    Q_PROPERTY(bool rpmEngineWorked READ rpmEngineWorked NOTIFY rpmEngineWorkedChanged)
    Q_PROPERTY(qreal rpmThrottle READ rpmThrottle NOTIFY rpmThrottleChanged)
    Q_PROPERTY(qreal rcThrottle READ rcThrottle NOTIFY rcThrottleChanged)
    Q_PROPERTY(qreal tcuMap READ tcuMap NOTIFY tcuMapChanged)
    Q_PROPERTY(bool tcuWarn READ tcuWarn NOTIFY tcuWarnChanged)
    Q_PROPERTY(bool tcuCaution READ tcuCaution NOTIFY tcuCautionChanged)
    Q_PROPERTY(qreal clutchVoltage READ clutchVoltage NOTIFY clutchVoltageChanged)
    Q_PROPERTY(qreal clutchCtrl READ clutchCtrl NOTIFY clutchCtrlChanged)
    Q_PROPERTY(bool clutchState READ clutchState NOTIFY clutchStateChanged)
    Q_PROPERTY(bool clutchFuse READ clutchFuse NOTIFY clutchFuseChanged)
    Q_PROPERTY(bool servo READ servo NOTIFY servoChanged)
    Q_PROPERTY(bool gear READ gear NOTIFY gearChanged)
    Q_PROPERTY(qreal altSrvVolt READ altSrvVolt NOTIFY altSrvVoltChanged)
    Q_PROPERTY(qreal altBat12v1 READ altBat12v1 NOTIFY altBat12v1Changed)
    Q_PROPERTY(qreal altBat12v2 READ altBat12v2 NOTIFY altBat12v2Changed)
    Q_PROPERTY(bool altRectLamp READ altRectLamp NOTIFY altRectLampChanged)
    Q_PROPERTY(bool altAltLamp READ altAltLamp NOTIFY altAltLampChanged)
    Q_PROPERTY(qreal ign1 READ ign1 NOTIFY ign1Changed)
    Q_PROPERTY(qreal ign2 READ ign2 NOTIFY ign2Changed)
    Q_PROPERTY(bool ignStarter READ ignStarter NOTIFY ignStarterChanged)
    Q_PROPERTY(qreal ignChoke READ ignChoke NOTIFY ignChokeChanged)
    Q_PROPERTY(qreal ignFp READ ignFp NOTIFY ignFpChanged)
    Q_PROPERTY(bool lightTaxi READ lightTaxi NOTIFY lightTaxiChanged)
    Q_PROPERTY(bool lightNav READ lightNav NOTIFY lightNavChanged)
    Q_PROPERTY(bool reserveRpm READ reserveRpm NOTIFY reserveRpmChanged)

    Q_PROPERTY(bool chipDetector READ chipDetector NOTIFY chipDetectorChanged)
    Q_PROPERTY(bool gMode READ gMode NOTIFY gModeChanged)
    Q_PROPERTY(bool ctrLim READ ctrLim NOTIFY ctrLimChanged)

    Q_PROPERTY(int limit READ limit NOTIFY limitChanged)
public:
    explicit MandalaValues(QObject *parent = nullptr);
    enum LimitFlag {Ok = 1, Warning = 2, Alarm = 3, Disable = 4};

    bool statusULanding(){return m_statusULanding;}
    bool statusErsArm(){return m_statusErsArm;}
    bool statusFramePrs(){return m_statusFramePrs;}
    bool statusErsPyro(){return m_statusErsPyro;}
    bool statusBB(){return m_statusBB;}

    bool fanAuto(){return m_fanAuto;}
    bool fan1(){return m_fan1;}
    bool fan2(){return m_fan2;}
    bool coolLvl(){return m_coolLvl;}

    qreal engineOT(){return m_engineOT;}
    qreal engineFuelPress(){return m_engineFuelPress;}
    qreal firstFFSensor(){return m_firstFFSensor;}
    qreal secondFFSensor(){return m_secondFFSensor;}
    int engineGearBoxTemp(){return m_engineGearBoxTemp;}
    qreal engineOP(){return m_engineOP;}
    int engineET(){return m_engineET;}
    qreal engineFuel(){return m_engineFuel;}

    int egt1(){return m_egt1;}
    int egt2(){return m_egt2;}
    int egt3(){return m_egt3;}
    int egt4(){return m_egt4;}

    qreal rpmRotor(){return m_rpmRotor;}
    qreal rpmEngine(){return m_rpmEngine;}
    int rpmRotorReal(){return m_rpmRotorReal;}
    int rpmEngineReal(){return m_rpmEngineReal;}

    bool rpmEngineWorked(){return m_rpmEngineWorked;}
    qreal rpmThrottle(){return m_rpmThrottle;}
    qreal rcThrottle(){return m_rcThrottle;}
    qreal tcuMap(){return m_tcuMap;}
    bool tcuWarn(){return m_tcuWarn;}
    bool tcuCaution(){return m_tcuCaution;}
    qreal clutchVoltage(){return m_clutchVoltage;}
    qreal clutchCtrl(){return m_clutchCtrl;}
    bool clutchState(){return m_clutchState;}
    bool clutchFuse(){return m_clutchFuse;}
    bool servo(){return m_servo;}
    bool gear(){return m_gear;}
    qreal altSrvVolt(){return m_altSrvVolt;}
    qreal altBat12v1(){return m_altBat12v1;}
    qreal altBat12v2(){return m_altBat12v2;}
    bool altRectLamp(){return m_altRectLamp;}
    bool altAltLamp(){return m_altAltLamp;}
    qreal ign1(){return m_ign1;}
    qreal ign2(){return m_ign2;}
    bool ignStarter(){return m_ignStarter;}
    qreal ignChoke(){return m_ignChoke;}
    qreal ignFp(){return m_ignFp;}
    bool lightTaxi(){return m_lightTaxi;}
    bool lightNav(){return m_lightNav;}
    bool reserveRpm(){return m_reserveRpm;}

    bool chipDetector() { return m_chipDetector; }
    bool gMode() { return m_gMode; }
    bool ctrLim() { return m_ctrLim; }

    int limit() { return m_limit; }

    void setStatusULanding(bool val){ m_statusULanding = val; emit statusULandingChanged(); }
    void setStatusErsArm(bool val){
        m_statusErsArm = val;
        updateMap((uint64_t)(&m_statusErsArm), m_statusErsArm, LimitFlag::Warning);
        emit statusErsArmChanged();
    }
    void setStatusFramePrs(bool val){
        m_statusFramePrs = val;
        updateMap((uint64_t)(&m_statusFramePrs), m_statusFramePrs, LimitFlag::Warning);
        emit statusFramePrsChanged();
    }
    void setStatusErsPyro(bool val){ m_statusErsPyro = val; emit statusErsPyroChanged(); }
    void setStatusBB(bool val){
        m_statusBB = val;
        updateMap((uint64_t)(&m_statusBB), m_statusBB, LimitFlag::Warning);
        emit statusBBChanged();
    }
    void setFanAuto(bool val){ m_fanAuto = val; emit fanAutoChanged(); }
    void setFan1(bool val){ m_fan1 = val; emit fan1Changed(); }
    void setFan2(bool val){ m_fan2 = val; emit fan2Changed(); }
    void setCoolLvl(bool val){
        m_coolLvl = val;
        updateMap((uint64_t)(&m_coolLvl), m_coolLvl, LimitFlag::Warning);
        emit coolLvlChanged();
    }
    void setEngineOT(qreal val){ m_engineOT = val; emit engineOTChanged(); }
    void setEngineFuelPress(qreal val, qreal min, qreal max){
        m_engineFuelPress = val;
        updateMap((uint64_t)(&m_engineFuelPress), val > max || val < min, LimitFlag::Alarm);
        emit engineFuelPressChanged();
    }
    void setfirstFFSensor(qreal val, qreal min, qreal max){
        m_firstFFSensor = val;
        updateMap((uint64_t)(&m_firstFFSensor), val > max || val < min, LimitFlag::Alarm);
        emit firstFFSensorChanged();
    }
    void setsecondFFSensor(qreal val, qreal min, qreal max){
        m_secondFFSensor = val;
        updateMap((uint64_t)(&m_secondFFSensor), val > max || val < min, LimitFlag::Alarm);
        emit secondFFSensorChanged();
    }
    void setEngineGearBoxTemp(int val){ m_engineGearBoxTemp = val; emit engineGearBoxTempChanged(); }
    void setEngineOP(qreal val, qreal min, qreal max){
        m_engineOP = val;
        updateMap((uint64_t)(&m_engineOP), val > max || val < min, LimitFlag::Alarm);
        emit engineOPChanged();
    }
    void setEngineET(int val){ m_engineET = val; emit engineETChanged(); }
    void setEngineFuel(qreal val, qreal min, qreal max){
        m_engineFuel = val;
        updateMap((uint64_t)(&m_engineFuel), val > max || val < min, LimitFlag::Alarm);
        emit engineFuelChanged();
    }
    void setEgt1(int val){ m_egt1 = val; emit egt1Changed(); }
    void setEgt2(int val){ m_egt2 = val; emit egt2Changed(); }
    void setEgt3(int val){ m_egt3 = val; emit egt3Changed(); }
    void setEgt4(int val){ m_egt4 = val; emit egt4Changed(); }
    void setRpmRotor(qreal val){ m_rpmRotor = val; emit rpmRotorChanged(); }
    void setRpmEngine(qreal val){ m_rpmEngine = val; emit rpmEngineChanged(); }
    void setRpmRotorReal(int val){ m_rpmRotorReal = val; emit rpmRotorRealChanged(); }
    void setRpmEngineReal(int val){ m_rpmEngineReal = val; emit rpmEngineRealChanged(); }
    void setRpmEngineWorked(bool val){ m_rpmEngineWorked = val; emit rpmEngineWorkedChanged(); }
    void setRpmThrottle(qreal val){ m_rpmThrottle = val; emit rpmThrottleChanged(); }
    void setRcThrottle(qreal val){ m_rcThrottle = val; emit rcThrottleChanged(); }
    void setTcuMap(qreal val){ m_tcuMap = val; emit tcuMapChanged(); }
    void setTcuWarn(bool val){
        m_tcuWarn = val;
        updateMap((uint64_t)(&m_tcuWarn), m_tcuWarn, LimitFlag::Warning);
        emit tcuWarnChanged();
    }
    void setTcuCaution(bool val){
        m_tcuCaution = val;
        updateMap((uint64_t)(&m_tcuCaution), m_tcuCaution, LimitFlag::Warning);
        emit tcuCautionChanged();
    }
    void setClutchVoltage(qreal val){
        m_clutchVoltage = val;
        updateMap((uint64_t)(&m_clutchVoltage), m_clutchVoltage >= 0.2, LimitFlag::Alarm);
        emit clutchVoltageChanged();
    }
    void setClutchCtrl(qreal val){ m_clutchCtrl = val; emit clutchCtrlChanged(); }
    void setClutchState(bool val){ m_clutchState = val; emit clutchStateChanged(); }
    void setClutchFuse(bool val){ m_clutchFuse = val; emit clutchFuseChanged(); }
    void setServo(bool val){
        m_servo = val;
        updateMap((uint64_t)(&m_servo), m_servo, LimitFlag::Alarm);
        emit servoChanged();
    }
    void setGear(bool val){
        m_gear = val;
        updateMap((uint64_t)(&m_gear), m_gear, LimitFlag::Alarm);
        emit gearChanged();
    }
    void setAltSrvVolt(qreal val){ m_altSrvVolt = val; emit altSrvVoltChanged(); }
    void setAltBat12v1(qreal val){ m_altBat12v1 = val; emit altBat12v1Changed(); }
    void setAltBat12v2(qreal val){ m_altBat12v2 = val; emit altBat12v2Changed(); }
    void setAltRectLamp(bool val){
        m_altRectLamp = val;
        updateMap((uint64_t)(&m_altRectLamp), m_altRectLamp, LimitFlag::Alarm);
        emit altRectLampChanged();
    }
    void setAltAltLamp(bool val){
        m_altAltLamp = val;
        updateMap((uint64_t)(&m_altAltLamp), m_altAltLamp, LimitFlag::Alarm);
        emit altAltLampChanged();
    }
    void setIgn1(qreal val){ m_ign1 = val; emit ign1Changed(); }
    void setIgn2(qreal val){ m_ign2 = val; emit ign2Changed(); }
    void setIgnStarter(bool val){ m_ignStarter = val; emit ignStarterChanged(); }
    void setIgnChoke(qreal val){ m_ignChoke = val; emit ignChokeChanged(); }
    void setIgnFp(qreal val){ m_ignFp = val; emit ignFpChanged(); }
    void setLightTaxi(bool val){ m_lightTaxi = val; emit lightTaxiChanged(); }
    void setLightNav(bool val){ m_lightNav = val; emit lightNavChanged(); }
    void setReserveRpm(bool val){
        m_reserveRpm = val;
        updateMap((uint64_t)(&m_reserveRpm), m_reserveRpm, LimitFlag::Warning);
        emit reserveRpmChanged();
    }
    void setChipDetector(bool val) {
        m_chipDetector = val;
        updateMap((uint64_t)(&m_chipDetector), m_chipDetector, LimitFlag::Warning);
        emit chipDetectorChanged();
    }
    void setGMode(bool val) {
        m_gMode = val;
        updateMap((uint64_t)(&m_gMode), m_gMode, LimitFlag::Warning);
        emit gModeChanged();
    }
    void setCtrLim(bool val) {
        m_ctrLim = val;
        updateMap((uint64_t)(&m_ctrLim), m_ctrLim, LimitFlag::Warning);
        emit ctrLimChanged();
    }

    Q_INVOKABLE void muteLimitMap();
    void updateLimitFlag();
signals:
//    void srvChokeChanged();
//    void srvRightChanged();
//    void srvLeftChanged();
//    void srvTmpChokeChanged();
//    void srvTmpRightChanged();
//    void srvTmpLeftChanged();
    void statusULandingChanged();
    void statusErsArmChanged();
    void statusFramePrsChanged();
    void statusErsPyroChanged();
    void statusBBChanged();
    void fanAutoChanged();
    void fan1Changed();
    void fan2Changed();
    void coolLvlChanged();
    void engineOTChanged();
    void engineFuelPressChanged();
    void firstFFSensorChanged();
    void secondFFSensorChanged();
    void engineGearBoxTempChanged();
    void engineOPChanged();
    void engineETChanged();
    void engineFuelChanged();
    void egt1Changed();
    void egt2Changed();
    void egt3Changed();
    void egt4Changed();
    void rpmRotorChanged();
    void rpmEngineChanged();
    void rpmRotorRealChanged();
    void rpmEngineRealChanged();
    void rpmEngineWorkedChanged();
    void rpmThrottleChanged();
    void rcThrottleChanged();
    void tcuMapChanged();
    void tcuWarnChanged();
    void tcuCautionChanged();
    void clutchVoltageChanged();
    void clutchCtrlChanged();
    void clutchStateChanged();
    void clutchFuseChanged();
    void servoChanged();
    void gearChanged();
    void altSrvVoltChanged();
    void altBat12v1Changed();
    void altBat12v2Changed();
    void altRectLampChanged();
    void altAltLampChanged();
    void ign1Changed();
    void ign2Changed();
    void ignStarterChanged();
    void ignChokeChanged();
    void ignFpChanged();
    void lightTaxiChanged();
    void lightNavChanged();
    void reserveRpmChanged();
    bool chipDetectorChanged();
    bool gModeChanged();
    bool ctrLimChanged();
    bool limitChanged();

private:

    bool m_statusULanding;
    bool m_statusErsArm;
    bool m_statusFramePrs;
    bool m_statusErsPyro;
    bool m_statusBB;

    bool m_fanAuto;
    bool m_fan1;
    bool m_fan2;
    bool m_coolLvl;

    qreal m_engineOT;
    qreal m_engineFuelPress;
    qreal m_firstFFSensor;
    qreal m_secondFFSensor;
    int m_engineGearBoxTemp;
    qreal m_engineOP;
    int m_engineET;
    qreal m_engineFuel;

    int m_egt1;
    int m_egt2;
    int m_egt3;
    int m_egt4;

    qreal m_rpmRotor;
    qreal m_rpmEngine;
    int m_rpmRotorReal;
    int m_rpmEngineReal;
    bool m_rpmEngineWorked;
    qreal m_rpmThrottle;
    qreal m_rcThrottle;

    qreal m_tcuMap;
    bool m_tcuWarn;
    bool m_tcuCaution;

    qreal m_clutchVoltage;
    qreal m_clutchCtrl;
    bool m_clutchState;
    bool m_clutchFuse;

    bool m_servo;
    bool m_gear;

    qreal m_altSrvVolt;
    qreal m_altBat12v1;
    qreal m_altBat12v2;
    bool m_altRectLamp;
    bool m_altAltLamp;

    qreal m_ign1;
    qreal m_ign2;
    bool m_ignStarter;
    qreal m_ignChoke;
    qreal m_ignFp;

    bool m_lightTaxi;
    bool m_lightNav;
    bool m_reserveRpm;

    bool m_chipDetector;
    bool m_gMode;
    bool m_ctrLim;

    int m_limit; //0: ok; 1: warning; 2: alarm
    QMap<uint64_t, LimitFlag> m_mapFlag;

    void updateMap(uint64_t key, bool flag, LimitFlag limOut);

};

#endif // MANDALAVALUES_H
