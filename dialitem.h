#ifndef DIALITEM_H
#define DIALITEM_H

#include <QQuickPaintedItem>

class DialItem : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(int startAngle READ getStartAngle WRITE setStartAngle NOTIFY startAngleChanged)
    Q_PROPERTY(qreal spanAngle READ getSpanAngle WRITE setSpanAngle NOTIFY spanAngleChanged)
    Q_PROPERTY(double minValue READ getMinValue WRITE setMinValue NOTIFY minValueChanged)  //
    Q_PROPERTY(double maxValue READ getMaxValue WRITE setMaxValue NOTIFY maxValueChanged)  //
    Q_PROPERTY(double tickPrescaler READ getTickPrescaler WRITE setTickPrescaler NOTIFY tickPrescalerChanged)
    Q_PROPERTY(int dialWidth READ getDialWidth WRITE setDialWidth NOTIFY dialWidthChanged)
    Q_PROPERTY(QColor dialColor READ getDialColor WRITE setDialColor NOTIFY dialColorChanged)
    Q_PROPERTY(QColor warnColor READ getWarnColor WRITE setWarnColor NOTIFY warnColorChanged)
    Q_PROPERTY(QColor alarmColor READ getAlarmColor WRITE setAlarmColor NOTIFY alarmColorChanged)
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor NOTIFY textColorChanged)
    Q_PROPERTY(QColor backgroundColor READ getBackgroundColor WRITE setBackgroundColor NOTIFY backgroundColorChanged)

    Q_PROPERTY(bool minLimFlag READ getMinLimFlag WRITE setMinLimFlag NOTIFY minLimFlagChanged)
    Q_PROPERTY(bool maxLimFlag READ getMaxLimFlag WRITE setMaxLimFlag NOTIFY maxLimFlagChanged)
    Q_PROPERTY(bool minAlarmFlag READ getMinAlarmFlag WRITE setMinAlarmFlag NOTIFY minAlarmFlagChanged)
    Q_PROPERTY(bool maxAlarmFlag READ getMaxAlarmFlag WRITE setMaxAlarmFlag NOTIFY maxAlarmFlagChanged)
    Q_PROPERTY(double minLimValue READ getMinLimValue WRITE setMinLimValue NOTIFY minLimValueChanged)
    Q_PROPERTY(double maxLimValue READ getMaxLimValue WRITE setMaxLimValue NOTIFY maxLimValueChanged)
    Q_PROPERTY(double minAlarm READ getMinAlarm WRITE setMinAlarm NOTIFY minAlarmChanged)
    Q_PROPERTY(double maxAlarm READ getMaxAlarm WRITE setMaxAlarm NOTIFY maxAlarmChanged)

    Q_PROPERTY(bool fMirrorText READ getfMirrorText WRITE setfMirrorText)

public:
    DialItem(QQuickItem *parent = nullptr);
    void paint(QPainter *painter);
    int getStartAngle() {return m_StartAngle;}
    qreal getSpanAngle() {return m_SpanAngle;}
    double getMinValue() {return m_MinValue;}
    double getMaxValue() {return m_MaxValue;}
    double getTickPrescaler() {return m_TickPrescaler;}
    int getDialWidth() {return m_DialWidth;}
    QColor getDialColor() {return m_DialColor;}
    QColor getWarnColor() {return m_WarnColor;}
    QColor getAlarmColor() {return m_AlarmColor;}
    QColor getTextColor() {return m_TextColor;}
    QColor getBackgroundColor() {return m_BackgroundColor;}
    bool getMinLimFlag() {return m_MinLimFlag;}
    bool getMaxLimFlag() {return m_MaxLimFlag;}
    bool getMinAlarmFlag() {return m_MinAlarmFlag;}
    bool getMaxAlarmFlag() {return m_MaxAlarmFlag;}
    double getMinLimValue() {return m_MinLimValue;}
    double getMaxLimValue() {return m_MaxLimValue;}
    double getMinAlarm() {return m_MinAlarm;}
    double getMaxAlarm() {return m_MaxAlarm;}
    bool getfMirrorText() {return m_fMirrorText;}

    void setStartAngle(int angle) {m_StartAngle = angle; this->update();}
    void setSpanAngle(qreal angle) {m_SpanAngle = angle; this->update();}
    void setMinValue(double value) {m_MinValue = value; this->update();}
    void setMaxValue(double value) {m_MaxValue = value; this->update();}
    void setTickPrescaler(double value) {m_TickPrescaler = value; this->update();}
    void setDialWidth(int angle) {m_DialWidth = angle; this->update();}
    void setDialColor(QColor color) {m_DialColor = color; this->update();}
    void setWarnColor(QColor color) {m_WarnColor = color; this->update();}
    void setAlarmColor(QColor color) {m_AlarmColor = color; this->update();}
    void setTextColor(QColor color) {m_TextColor = color; this->update();}
    void setBackgroundColor(QColor color) {m_BackgroundColor = color; this->update();}
    void setMinLimFlag(bool flag) {m_MinLimFlag = flag; this->update();}
    void setMaxLimFlag(bool flag) {m_MaxLimFlag = flag; this->update();}
    void setMinAlarmFlag(bool flag) {m_MinAlarmFlag = flag; this->update();}
    void setMaxAlarmFlag(bool flag) {m_MaxAlarmFlag = flag; this->update();}
    void setMinLimValue(double value) {m_MinLimValue = value; this->update();}
    void setMaxLimValue(double value) {m_MaxLimValue = value; this->update();}
    void setMinAlarm(double value) {m_MinAlarm = value; this->update();}
    void setMaxAlarm(double value) {m_MaxAlarm = value; this->update();}
    void setfMirrorText(bool value) {m_fMirrorText = value; this->update();}

signals:
    void startAngleChanged();
    void spanAngleChanged();
    void minValueChanged();
    void maxValueChanged();
    void tickPrescalerChanged();
    void dialWidthChanged();
    void dialColorChanged();
    void warnColorChanged();
    void alarmColorChanged();
    void textColorChanged();
    void backgroundColorChanged();
    void minLimFlagChanged();
    void maxLimFlagChanged();
    void minAlarmFlagChanged();
    void maxAlarmFlagChanged();
    void minLimValueChanged();
    void maxLimValueChanged();
    void minAlarmChanged();
    void maxAlarmChanged();

private:
    int m_StartAngle;
    qreal m_SpanAngle;
    double m_MinValue;     //min value of measuring parameter
    double m_MaxValue;     //max value of measuring parameter
    int m_DialWidth;
    double m_TickPrescaler;
    QColor m_DialColor;
    QColor m_WarnColor;
    QColor m_AlarmColor;
    QColor m_TextColor;
    QColor m_BackgroundColor;

    bool m_MinLimFlag;
    bool m_MaxLimFlag;
    double m_MinLimValue;
    double m_MaxLimValue;

    bool m_MinAlarmFlag;
    bool m_MaxAlarmFlag;
    double m_MinAlarm;
    double m_MaxAlarm;

    bool m_fMirrorText;
};

#endif // DIALITEM_H
