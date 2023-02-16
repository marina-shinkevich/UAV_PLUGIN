#include "dialitem.h"

#include <QTime>
#include <QPainter>
#include "math.h"

#define PI 3.14159265

DialItem::DialItem(QQuickItem *parent) : QQuickPaintedItem(parent)
{
    m_StartAngle = 0;
    m_SpanAngle = 180;
    m_MinValue = 0;
    m_MaxValue = 50;
    m_TickPrescaler = 10;
    m_DialWidth = 4;
    m_DialColor = QColor(0, 0, 0);
    m_WarnColor = QColor(0, 0, 0);
    m_AlarmColor = QColor(0, 0, 0);
    m_TextColor = QColor(0, 0, 0);

    m_MinLimFlag = false;
    m_MinLimValue = 10;
    m_MaxLimFlag = false;
    m_MaxLimValue = 40;

    m_fMirrorText = false;

    connect(this, SIGNAL(startAngleChanged()), this, SLOT(update()));
    connect(this, SIGNAL(spanAngleChanged()), this, SLOT(update()));
    connect(this, SIGNAL(minValueChanged()), this, SLOT(update()));
    connect(this, SIGNAL(maxValueChanged()), this, SLOT(update()));
    connect(this, SIGNAL(dialWidthChanged()), this, SLOT(update()));
    connect(this, SIGNAL(dialColorChanged()), this, SLOT(update()));
}

//=======================================================================

void DialItem::paint(QPainter *painter)
{
    QRectF rect = this->boundingRect();
    painter->setRenderHint(QPainter::Antialiasing);
    QPen pen = painter->pen();
    pen.setColor(Qt::black);

    double startAngle = -90 - m_StartAngle;
    double spanAngle = 0 - m_SpanAngle;    //поиск лимита и преобразование

    qreal offset = m_DialWidth / 2;
    pen.setWidth(m_DialWidth-1);
    pen.setColor(m_AlarmColor);
    painter->setPen(pen);

    double minAngle = 0;
    double maxAngle = 0;
    double minLimAngle = 0;
    double maxLimAngle = 0;

    if(m_MinLimFlag){
        minAngle = 0 - (m_MinAlarm-m_MinValue)*(m_SpanAngle-m_StartAngle+30)/(m_MaxValue - m_MinValue);
        minLimAngle = 0 - (m_MinLimValue-m_MinValue)*(m_SpanAngle-m_StartAngle+30)/(m_MaxValue - m_MinValue);
        //Draw outer dial limit
        painter->save();
        painter->drawArc(rect.adjusted(offset, offset, -offset, -offset), startAngle*16, minAngle*16);
        painter->restore();
    }
    if(m_MaxLimFlag){
        maxAngle =  -(m_SpanAngle-m_StartAngle+30) + (m_MaxAlarm-m_MinValue)*(m_SpanAngle-m_StartAngle+30)/(m_MaxValue - m_MinValue);
        maxLimAngle = -(m_SpanAngle-m_StartAngle+30) + (m_MaxLimValue-m_MinValue)*(m_SpanAngle-m_StartAngle+30)/(m_MaxValue - m_MinValue);
        painter->save();
        painter->drawArc(rect.adjusted(offset, offset, -offset, -offset), (-120+spanAngle)*16, -maxAngle*16);
        painter->restore();
    }

    qreal majorTicksRotate = 90+m_StartAngle;
    qreal minorTicksRotate = 90+m_StartAngle;

    //Draw major ticks
    painter->save();
    pen.setWidth(m_DialWidth-1);
    painter->translate(width() / 2, height() / 2);
    painter->rotate(majorTicksRotate);
    qreal angleStep = (m_SpanAngle-m_StartAngle+30) / m_TickPrescaler;

    //преобразуем в положительные углы относительно начала отсчёта
    minAngle = m_StartAngle-minAngle;
    maxAngle = m_SpanAngle+maxAngle+30;
    minLimAngle = m_StartAngle-minLimAngle;
    maxLimAngle = m_SpanAngle+maxLimAngle+30;

    majorTicksRotate = m_StartAngle;

    for(int i = 0; i <= m_TickPrescaler; ++i)
    {
        if((m_MinLimFlag && majorTicksRotate<=minAngle) || (m_MaxLimFlag && majorTicksRotate>=maxAngle))
            pen.setColor(m_AlarmColor);
        else if((m_MinAlarmFlag && majorTicksRotate<=minLimAngle) || (m_MaxAlarmFlag && majorTicksRotate>=maxLimAngle))
            pen.setColor(m_WarnColor);
        else pen.setColor(m_DialColor);

        painter->setPen(pen);
        painter->drawLine(rect.width()/2 - 10, 0, rect.width()/2 - 2, 0);
        painter->rotate(angleStep);
        majorTicksRotate += angleStep;
    }
    painter->translate(-width() / 2, -height() / 2);
    painter->restore();

    //Draw minor ticks
    painter->save();
    pen.setWidth(m_DialWidth/2);
    painter->translate(width() / 2, height() / 2);
    painter->rotate(minorTicksRotate);
    pen.setColor(m_DialColor);
    painter->setPen(pen);
    minorTicksRotate = m_StartAngle;
    int minorTicks = 5 * m_TickPrescaler;
    qreal angleStepMin = (m_SpanAngle-m_StartAngle+30)/minorTicks;
    for(int i = 0; i < minorTicks; ++i)
    {
        if((m_MinLimFlag && minorTicksRotate<=minAngle) ||  (m_MaxLimFlag && minorTicksRotate>=maxAngle)){
            pen.setColor(m_AlarmColor);
//            painter->rotate(angleStepMin);
//            minorTicksRotate += angleStepMin;
//            continue;
        }
        else if((m_MinAlarmFlag && minorTicksRotate<=minLimAngle) ||  (m_MaxAlarmFlag && minorTicksRotate>=maxLimAngle))
            pen.setColor(m_WarnColor);
        else pen.setColor(m_DialColor);

        painter->setPen(pen);
        painter->drawLine(rect.width()/2 - 7, 0, rect.width()/2 - 4, 0);
        painter->rotate(angleStepMin);
        minorTicksRotate += angleStepMin;
    }
    painter->translate(-width() / 2, -height() / 2);
    painter->restore();

    //Draw numbers
    painter->save();
    pen.setColor(m_TextColor);
    painter->setPen(pen);
    const int radius = rect.width()/2.6;
    QFontMetrics fontMat(painter->font());
    QString numbr;
    QFont font = QFont("Ubuntu Condensed", rect.width()/23);
    font.setPixelSize(20);

    double val = m_MinValue;

    if(m_fMirrorText){
        painter->scale(-1,1);
        painter->translate(-width(), 0);
    }

    QVector<double> vAngl;
    if(m_fMirrorText){
        for (double i = 300+m_StartAngle-30; i >= 300-m_SpanAngle; i -= (m_SpanAngle-m_StartAngle+30)/m_TickPrescaler)
            vAngl.append(i);
    }
    else{
        for (double i = m_StartAngle-30; i <= m_SpanAngle; i += (m_SpanAngle-m_StartAngle+30)/m_TickPrescaler)
            vAngl.append(i);
    }

    foreach (double i, vAngl){
        pen.setColor(m_TextColor);
        painter->setPen(pen);
        painter->setFont(font);
        numbr = QString::number(val);
        val += (m_MaxValue - m_MinValue)/m_TickPrescaler;
        QRect bound = fontMat.boundingRect(numbr);

        QPoint p(rect.center().x()-bound.width()/2.0 + radius * cos(-90.05-i * PI / 180.0),
                 rect.center().y() - radius * sin(-90.05-i * PI / 180.0));
        painter->drawText(QPointF((p.x()), (p.y() + bound.height()/2)), numbr);
    }
    painter->restore();
}

