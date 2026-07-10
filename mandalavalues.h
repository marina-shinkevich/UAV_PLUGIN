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

    // for Group 1
    Q_PROPERTY(qreal batVoltage READ batVoltage NOTIFY batVoltageChanged)
    Q_PROPERTY(qreal batCurrent READ batCurrent NOTIFY batCurrentChanged)
     Q_PROPERTY(qreal agiRadio READ agiRadio NOTIFY agiRadioChanged)
    Q_PROPERTY(qreal fuelPressureSensor READ fuelPressureSensor NOTIFY fuelPressureSensorChanged)
    Q_PROPERTY(qreal gboxRpm READ gboxRpm NOTIFY gboxRpmChanged)
    Q_PROPERTY(qreal engTemp READ engTemp NOTIFY engTempChanged)
    Q_PROPERTY(qreal engVoltage READ engVoltage NOTIFY engVoltageChanged)
    Q_PROPERTY(qreal engCurrent READ engCurrent NOTIFY engCurrentChanged)
    Q_PROPERTY(qreal engRpm READ engRpm NOTIFY engRpmChanged)
    Q_PROPERTY(qreal aglRadio READ aglRadio NOTIFY aglRadioChanged)
    Q_PROPERTY(qreal ersBlock READ ersBlock NOTIFY ersBlockChanged)
    Q_PROPERTY(qreal ersLaunch READ ersLaunch NOTIFY ersLaunchChanged)
    Q_PROPERTY(qreal ersStatus READ ersStatus NOTIFY ersStatusChanged)
    Q_PROPERTY(qreal ctrEngThr READ ctrEngThr NOTIFY ctrEngThrChanged)

    // Group 2
    Q_PROPERTY(qreal usrU1 READ usrU1 NOTIFY usrU1Changed)
    Q_PROPERTY(qreal usrU2 READ usrU2 NOTIFY usrU2Changed)
    Q_PROPERTY(qreal usrU3 READ usrU3 NOTIFY usrU3Changed)
    Q_PROPERTY(qreal usrU4 READ usrU4 NOTIFY usrU4Changed)
    Q_PROPERTY(qreal usrU5 READ usrU5 NOTIFY usrU5Changed)
    Q_PROPERTY(qreal usrU6 READ usrU6 NOTIFY usrU6Changed)
    Q_PROPERTY(qreal usrU7 READ usrU7 NOTIFY usrU7Changed)
    Q_PROPERTY(qreal usrU8 READ usrU8 NOTIFY usrU8Changed)
    Q_PROPERTY(qreal usrU9 READ usrU9 NOTIFY usrU9Changed)
    Q_PROPERTY(qreal usrU10 READ usrU10 NOTIFY usrU10Changed)
    Q_PROPERTY(qreal usrU11 READ usrU11 NOTIFY usrU11Changed)
    Q_PROPERTY(qreal usrU12 READ usrU12 NOTIFY usrU12Changed)
    Q_PROPERTY(qreal usrU13 READ usrU13 NOTIFY usrU13Changed)
    Q_PROPERTY(qreal usrU14 READ usrU14 NOTIFY usrU14Changed)

    // Group 3
    Q_PROPERTY(int usrW1 READ usrW1 NOTIFY usrW1Changed)
    Q_PROPERTY(int usrW2 READ usrW2 NOTIFY usrW2Changed)
    Q_PROPERTY(int usrW3 READ usrW3 NOTIFY usrW3Changed)
    Q_PROPERTY(int usrW4 READ usrW4 NOTIFY usrW4Changed)
    Q_PROPERTY(int usrW5 READ usrW5 NOTIFY usrW5Changed)
    Q_PROPERTY(int usrW6 READ usrW6 NOTIFY usrW6Changed)
    Q_PROPERTY(int usrW7 READ usrW7 NOTIFY usrW7Changed)

    // Group 4
    Q_PROPERTY(qreal usrF1 READ usrF1 NOTIFY usrF1Changed)
    Q_PROPERTY(qreal usrF2 READ usrF2 NOTIFY usrF2Changed)
    Q_PROPERTY(qreal usrF3 READ usrF3 NOTIFY usrF3Changed)
    Q_PROPERTY(qreal usrF4 READ usrF4 NOTIFY usrF4Changed)
    Q_PROPERTY(qreal usrF5 READ usrF5 NOTIFY usrF5Changed)
    Q_PROPERTY(qreal usrF6 READ usrF6 NOTIFY usrF6Changed)
    Q_PROPERTY(qreal usrF7 READ usrF7 NOTIFY usrF7Changed)
    Q_PROPERTY(qreal usrF8 READ usrF8 NOTIFY usrF8Changed)
    Q_PROPERTY(qreal usrF9 READ usrF9 NOTIFY usrF9Changed)

    // Group 5
    Q_PROPERTY(int usrC1 READ usrC1 NOTIFY usrC1Changed)
    Q_PROPERTY(int usrC2 READ usrC2 NOTIFY usrC2Changed)
    Q_PROPERTY(int usrC3 READ usrC3 NOTIFY usrC3Changed)

    // Group 6
    Q_PROPERTY(bool usrB1 READ usrB1 NOTIFY usrB1Changed)
    Q_PROPERTY(bool usrB2 READ usrB2 NOTIFY usrB2Changed)
    Q_PROPERTY(bool usrB3 READ usrB3 NOTIFY usrB3Changed)
    Q_PROPERTY(bool usrB4 READ usrB4 NOTIFY usrB4Changed)

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

    // New get for Group 1
    qreal batVoltage() { return m_batVoltage; }
    qreal batCurrent() { return m_batCurrent; }
    qreal agiRadio() { return m_agiRadio; }
    qreal fuelPressureSensor() { return m_fuelPressureSensor; }
    qreal gboxRpm() { return m_gboxRpm; }
    
    // Additional variables from new list
    qreal engTemp() { return m_engTemp; }
    qreal engVoltage() { return m_engVoltage; }
    qreal engCurrent() { return m_engCurrent; }
    qreal engRpm() { return m_engRpm; }
    qreal aglRadio() { return m_aglRadio; }
    qreal ersBlock() { return m_ersBlock; }
    qreal ersLaunch() { return m_ersLaunch; }
    qreal ersStatus() { return m_ersStatus; }
    qreal ctrEngThr() { return m_ctrEngThr; }

    // Group 2 - User inputs
    qreal usrU1() { return m_usrU1; }
    qreal usrU2() { return m_usrU2; }
    qreal usrU3() { return m_usrU3; }
    qreal usrU4() { return m_usrU4; }
    qreal usrU5() { return m_usrU5; }
    qreal usrU6() { return m_usrU6; }
    qreal usrU7() { return m_usrU7; }
    qreal usrU8() { return m_usrU8; }
    qreal usrU9() { return m_usrU9; }
    qreal usrU10() { return m_usrU10; }
    qreal usrU11() { return m_usrU11; }
    qreal usrU12() { return m_usrU12; }
    qreal usrU13() { return m_usrU13; }
    qreal usrU14() { return m_usrU14; }

    // Group 3 - User weights
    qreal usrW1() { return m_usrW1; }
    qreal usrW2() { return m_usrW2; }
    qreal usrW3() { return m_usrW3; }
    qreal usrW4() { return m_usrW4; }
    qreal usrW5() { return m_usrW5; }
    qreal usrW6() { return m_usrW6; }
    qreal usrW7() { return m_usrW7; }

    // Group 4 - User flags
    qreal usrF1() { return m_usrF1; }
    qreal usrF2() { return m_usrF2; }
    qreal usrF3() { return m_usrF3; }
    qreal usrF4() { return m_usrF4; }
    qreal usrF5() { return m_usrF5; }
    qreal usrF6() { return m_usrF6; }
    qreal usrF7() { return m_usrF7; }
    qreal usrF8() { return m_usrF8; }
    qreal usrF9() { return m_usrF9; }

    // Group 5 - User counters
    int usrC1() { return m_usrC1; }
    int usrC2() { return m_usrC2; }
    int usrC3() { return m_usrC3; }

    // Group 6 - User booleans
    bool usrB1() { return m_usrB1; }
    bool usrB2() { return m_usrB2; }
    bool usrB3() { return m_usrB3; }
    bool usrB4() { return m_usrB4; }

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

    // New
    void setBatVoltage(qreal val)  {m_batVoltage = val; emit batVoltageChanged();}
    void setBatCurrent(qreal val)  { m_batCurrent = val; emit batCurrentChanged(); }
    void setAgiRadio(qreal val) { m_agiRadio = val; emit agiRadioChanged(); }
    void setFuelPressureSensor(qreal val) { m_fuelPressureSensor = val; emit fuelPressureSensorChanged(); }
    void setGboxRpm(qreal val) { m_gboxRpm = val; emit gboxRpmChanged(); }
    void setEngTemp(qreal val) { m_engTemp = val; emit engTempChanged(); }
    void setEngVoltage(qreal val) { m_engVoltage = val; emit engVoltageChanged(); }
    void setEngCurrent(qreal val) { m_engCurrent = val; emit engCurrentChanged(); }
    void setEngRpm(qreal val) { m_engRpm = val; emit engRpmChanged(); }
    void setAglRadio(qreal val) { m_aglRadio = val; emit aglRadioChanged(); }
    void setErsBlock(qreal val) { m_ersBlock = val; emit ersBlockChanged(); }
    void setErsLaunch(qreal val) { m_ersLaunch = val; emit ersLaunchChanged(); }
    void setErsStatus(qreal val) { m_ersStatus = val; emit ersStatusChanged(); }
    void setCtrEngThr(qreal val) { m_ctrEngThr = val; emit ctrEngThrChanged(); }

    // Group 2 
    void setUsrU1(qreal val) { m_usrU1 = val; emit usrU1Changed(); }
    void setUsrU2(qreal val) { m_usrU2 = val; emit usrU2Changed(); }
    void setUsrU3(qreal val) { m_usrU3 = val; emit usrU3Changed(); }
    void setUsrU4(qreal val) { m_usrU4 = val; emit usrU4Changed(); }
    void setUsrU5(qreal val) { m_usrU5 = val; emit usrU5Changed(); }
    void setUsrU6(qreal val) { m_usrU6 = val; emit usrU6Changed(); }
    void setUsrU7(qreal val) { m_usrU7 = val; emit usrU7Changed(); }
    void setUsrU8(qreal val) { m_usrU8 = val; emit usrU8Changed(); }
    void setUsrU9(qreal val) { m_usrU9 = val; emit usrU9Changed(); }
    void setUsrU10(qreal val) { m_usrU10 = val; emit usrU10Changed(); }
    void setUsrU11(qreal val) { m_usrU11 = val; emit usrU11Changed(); }
    void setUsrU12(qreal val) { m_usrU12 = val; emit usrU12Changed(); }
    void setUsrU13(qreal val) { m_usrU13 = val; emit usrU13Changed(); }
    void setUsrU14(qreal val) { m_usrU14 = val; emit usrU14Changed(); }

    // Group 3 
    void setUsrW1(int val) {m_usrW1= val; emit usrW1Changed(); }
    void setUsrW2(int val) { m_usrW2 = val; emit usrW2Changed(); }
    void setUsrW3(int val) { m_usrW3 = val; emit usrW3Changed(); }
    void setUsrW4(int val) { m_usrW4 = val; emit usrW4Changed(); }
    void setUsrW5(int val) { m_usrW5 = val; emit usrW5Changed(); }
    void setUsrW6(int val) { m_usrW6 = val; emit usrW6Changed(); }
    void setUsrW7(int val) { m_usrW7 = val; emit usrW7Changed(); }

    // Group 4 
    void setUsrF1(qreal val) { m_usrF1 = val; emit usrF1Changed(); }
    void setUsrF2(qreal val) { m_usrF2 = val; emit usrF2Changed(); }
    void setUsrF3(qreal val) { m_usrF3 = val; emit usrF3Changed(); }
    void setUsrF4(qreal val) { m_usrF4 = val; emit usrF4Changed(); }
    void setUsrF5(qreal val) { m_usrF5 = val; emit usrF5Changed(); }
    void setUsrF6(qreal val) { m_usrF6 = val; emit usrF6Changed(); }
    void setUsrF7(qreal val) { m_usrF7 = val; emit usrF7Changed(); }
    void setUsrF8(qreal val) { m_usrF8 = val; emit usrF8Changed(); }
    void setUsrF9(qreal val) { m_usrF9 = val; emit usrF9Changed(); }

    // Group 5
    void setUsrC1(int val) { m_usrC1 = val; emit usrC1Changed(); }
    void setUsrC2(int val) { m_usrC2 = val; emit usrC2Changed(); }
    void setUsrC3(int val) { m_usrC3 = val; emit usrC3Changed(); }

    // Group 6
    void setUsrB1(bool val) { m_usrB1 = val; emit usrB1Changed(); }
    void setUsrB2(bool val) { m_usrB2 = val; emit usrB2Changed(); }
    void setUsrB3(bool val) { m_usrB3 = val; emit usrB3Changed(); }
    void setUsrB4(bool val) { m_usrB4 = val; emit usrB4Changed(); }

    Q_INVOKABLE void muteLimitMap();
    void updateLimitFlag();
signals:
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

    // signals for Group 1
    void batVoltageChanged();
    void batCurrentChanged();
    void agiRadioChanged();
    void fuelPressureSensorChanged();
    void gboxRpmChanged();
    
    void engTempChanged();
    void engVoltageChanged();
    void engCurrentChanged();
    void engRpmChanged();
    void aglRadioChanged();
    void ersBlockChanged();
    void ersLaunchChanged();
    void ersStatusChanged();
    void ctrEngThrChanged();

    // Group 2
    void usrU1Changed();
    void usrU2Changed();
    void usrU3Changed();
    void usrU4Changed();
    void usrU5Changed();
    void usrU6Changed();
    void usrU7Changed();
    void usrU8Changed();
    void usrU9Changed();
    void usrU10Changed();
    void usrU11Changed();
    void usrU12Changed();
    void usrU13Changed();
    void usrU14Changed();

    // Group 3
    void usrW1Changed();
    void usrW2Changed();
    void usrW3Changed();
    void usrW4Changed();
    void usrW5Changed();
    void usrW6Changed();
    void usrW7Changed();

    // Group 4 
    void usrF1Changed();
    void usrF2Changed();
    void usrF3Changed();
    void usrF4Changed();
    void usrF5Changed();
    void usrF6Changed();
    void usrF7Changed();
    void usrF8Changed();
    void usrF9Changed();

    // Group 5
    void usrC1Changed();
    void usrC2Changed();
    void usrC3Changed();

    // Group 6
    void usrB1Changed();
    void usrB2Changed();
    void usrB3Changed();
    void usrB4Changed();

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

    // New for Group 1
    qreal m_batVoltage;
    qreal m_batCurrent;
    qreal m_agiRadio;
    qreal m_fuelPressureSensor;
    qreal m_gboxRpm;
    qreal m_engTemp;
    qreal m_engVoltage;
    qreal m_engCurrent;
    qreal m_engRpm;
    qreal m_aglRadio;
    qreal m_ersBlock;
    qreal m_ersLaunch;
    qreal m_ersStatus;
    qreal m_ctrEngThr;

    // Group 2
    qreal m_usrU1;
    qreal m_usrU2;
    qreal m_usrU3;
    qreal m_usrU4;
    qreal m_usrU5;
    qreal m_usrU6;
    qreal m_usrU7;
    qreal m_usrU8;
    qreal m_usrU9;
    qreal m_usrU10;
    qreal m_usrU11;
    qreal m_usrU12;
    qreal m_usrU13;
    qreal m_usrU14;

    // Group 3
    int m_usrW1;
    int m_usrW2;
    int m_usrW3;
    int m_usrW4;
    int m_usrW5;
    int m_usrW6;
    int m_usrW7;

    // Group 4
    qreal m_usrF1;
    qreal m_usrF2;
    qreal m_usrF3;
    qreal m_usrF4;
    qreal m_usrF5;
    qreal m_usrF6;
    qreal m_usrF7;
    qreal m_usrF8;
    qreal m_usrF9;

    // Group 5
    int m_usrC1;
    int m_usrC2;
    int m_usrC3;

    // Group 6
    bool m_usrB1;
    bool m_usrB2;
    bool m_usrB3;
    bool m_usrB4;

    int m_limit; //0: ok; 1: warning; 2: alarm
    QMap<uint64_t, LimitFlag> m_mapFlag;

    void updateMap(uint64_t key, bool flag, LimitFlag limOut);

};

#endif // MANDALAVALUES_H
