#include "mandalavalues.h"
#include <QDebug>
MandalaValues::MandalaValues(QObject *parent) :
    QObject(parent),
    m_limit {0}
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













