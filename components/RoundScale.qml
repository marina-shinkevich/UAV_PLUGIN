import QtQuick 2.9
import QtQuick.Controls 2.12

import "../settings/colors.js" as Color

Item {

    property string nameScale: "scale1"
    property string descriptionScale: ""
    property bool fIntVal: false

    property bool fLowLim: false
    property bool fHighLim: true
    property bool fLowAlarm: false
    property bool fHighAlarm: false
    property double valLowLim: 30
    property double valHighLim: 80
    property double valMaxAlarm: valHighLim
    property double valMinAlarm: valLowLim

    property double valMin: 10
    property double valMax: 100
    property double valReal: 10.0
    property string colorOK: Color.GRAY_4
    property string colorWarn: Color.YELLOW_TEXT
    property string colorAlarm: Color.RED
    readonly property string colorLblVal: ((valReal < valLowLim && fLowLim) ||
                                           (valReal > valHighLim && fHighLim)) ? colorAlarm : Color.GRAY_TEXT1

    property double tickPrs: 10

    implicitHeight: parent.height
    implicitWidth: implicitHeight

    CircularGuage{
        id: idGuage
        width: height
        height: parent.height * 0.95
        anchors.centerIn: parent
        minValue: valMin
        maxValue: valMax
        tickPrescaler: tickPrs
        minLimFlag: fLowLim
        maxLimFlag: fHighLim
        minAlarmFlag: fLowAlarm
        maxAlarmFlag: fHighAlarm
        minLimValue: valLowLim
        maxLimValue: valHighLim
        minAlarm: valMinAlarm
        maxAlarm: valMaxAlarm
        valueReal: valReal
        dialColor: colorOK
        warnColor: colorWarn
        alarmColor: colorAlarm
    }

    Column{
        anchors{horizontalCenter: parent.horizontalCenter; top:parent.verticalCenter; topMargin:parent.height/8}
        width: parent.width/2
        spacing: 2
        z:-1

        Label{
            width: parent.width
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.family: "Ubuntu Condensed"
            font.pixelSize: 15
            font.bold: true
            text: nameScale
            color: Color.GRAY_4
        }
        Label{
            width: parent.width
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.family: "Ubuntu Condensed"
            font.pixelSize: 15
            font.bold: true
            text: descriptionScale
            color: Color.GRAY_4
        }
    }

    Label{
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.bottom
        anchors.topMargin: -40
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.family: "Ubuntu Condensed"
        font.pixelSize: 25
        font.bold: true
        text: fIntVal ? parseInt(valReal) : valReal.toFixed(1)
        color: colorLblVal
        z:-1
    }
}

