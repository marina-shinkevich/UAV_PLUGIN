#include "mandalavalues.h"
#include <QDebug>
MandalaValues::MandalaValues(QObject *parent) :
    QObject(parent),
    m_limit {0},
    // Init Group 1
    m_batVoltage(0.0),
    m_batCurrent(0.0),
    m_agiRadio(0.0),
    m_fuelPressureSensor(0.0),
    m_gboxRpm(0.0),
    m_engTemp(0.0),
    m_engVoltage(0.0),
    m_engCurrent(0.0),
    m_engRpm(0.0),
    m_aglRadio(0.0),
    m_ersBlock(0.0),
    m_ersLaunch(0.0),
    m_ersStatus(0.0),
    // Init Group 2
    m_usrU1(0.0),
    m_usrU2(0.0),
    m_usrU3(0.0),
    m_usrU4(0.0),
    m_usrU5(0.0),
    m_usrU6(0.0),
    m_usrU7(0.0),
    m_usrU8(0.0),
    m_usrU9(0.0),
    m_usrU10(0.0),
    m_usrU11(0.0),
    m_usrU12(0.0),
    m_usrU13(0.0),
    m_usrU14(0.0),
    //3
    m_usrW1(0.0),
    m_usrW2(0.0),
    m_usrW3(0.0),
    m_usrW4(0.0),
    m_usrW5(0.0),
    m_usrW6(0.0),
    m_usrW7(0.0),
    // 4
    m_usrF1(0.0),
    m_usrF2(0.0),
    m_usrF3(0.0),
    m_usrF4(0.0),
    m_usrF5(0.0),
    m_usrF6(0.0),
    m_usrF7(0.0),
    m_usrF8(0.0),
    m_usrF9(0.0),
    //5
    m_usrC1(0),
    m_usrC2(0),
    m_usrC3(0),
    // 6
    m_usrB1(false),
    m_usrB2(false),
    m_usrB3(false),
    m_usrB4(false)
{
    m_mapFlag.insert((uint64_t)(&m_altRectLamp), LimitFlag::Ok);
    m_mapFlag.insert((uint64_t)(&m_altAltLamp), LimitFlag::Ok);
    m_mapFlag.insert((uint64_t)(&m_statusErsArm), LimitFlag::Ok);
    m_mapFlag.insert((uint64_t)(&m_engineFuelPress), LimitFlag::Ok);
    m_mapFlag.insert((uint64_t)(&m_engineFuel), LimitFlag::Ok);
    m_mapFlag.insert((uint64_t)(&m_clutchVoltage), LimitFlag::Ok);
    m_mapFlag.insert((uint64_t)(&m_gear), LimitFlag::Ok);
    m_mapFlag.insert((uint64_t)(&m_servo), LimitFlag::Ok);
    m_mapFlag.insert((uint64_t)(&m_ctrLim), LimitFlag::Ok);
    m_mapFlag.insert((uint64_t)(&m_statusBB), LimitFlag::Ok);
    m_mapFlag.insert((uint64_t)(&m_engineOP), LimitFlag::Ok);
    m_mapFlag.insert((uint64_t)(&m_tcuCaution), LimitFlag::Ok);
    m_mapFlag.insert((uint64_t)(&m_tcuWarn), LimitFlag::Ok);
    m_mapFlag.insert((uint64_t)(&m_coolLvl), LimitFlag::Ok);
    m_mapFlag.insert((uint64_t)(&m_statusFramePrs), LimitFlag::Ok);
    m_mapFlag.insert((uint64_t)(&m_reserveRpm), LimitFlag::Ok);
    m_mapFlag.insert((uint64_t)(&m_gMode), LimitFlag::Ok);
    m_mapFlag.insert((uint64_t)(&m_chipDetector), LimitFlag::Ok);
}

void MandalaValues::muteLimitMap()
{
    for(LimitFlag &flag : m_mapFlag){
        if(flag != LimitFlag::Ok)
            flag = LimitFlag::Disable;
    }
}

void MandalaValues::updateLimitFlag()
{
    int currentLimit = 0;
    for(LimitFlag &flag : m_mapFlag){
        if(flag == LimitFlag::Warning)
            currentLimit = 1;
        else if(flag == LimitFlag::Alarm){
            currentLimit = 2;
            break;
        }
    }

    if(currentLimit != m_limit){
        m_limit = currentLimit;
        emit limitChanged();
    }
}

void MandalaValues::updateMap(uint64_t key, bool flag, LimitFlag limOut)
{
    if(m_mapFlag.contains(key)){
        if(flag && m_mapFlag.value(key) == LimitFlag::Ok){
            m_mapFlag[key] = limOut;
        }
        else if(!flag && m_mapFlag.value(key) != LimitFlag::Ok){
            m_mapFlag[key] = LimitFlag::Ok;
        }
    }
}













