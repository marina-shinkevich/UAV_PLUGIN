import QtQuick 2.9
import QtQuick.Controls 2.12

import "../settings/colors.js" as Color

Item {

    property string nameScale: "scale1"
    property string descriptionScale: ""
    property bool fIntVal: false
    property bool fMirror: false

    property bool visibleIndicator: false
    property int indicatorStatus: 0

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
    property double valReal: 1
    property string colorOK: Color.GRAY_4
    property string colorWarn: Color.YELLOW_TEXT
    property string colorAlarm: Color.RED
    readonly property string colorLblVal: ((valReal < valLowLim && fLowLim) ||
                                           (valReal > valHighLim && fHighLim)) ? colorAlarm : Color.GRAY_TEXT1

    property int minAngle: 30
    property int maxAngle: 150
    property double tickPrs: 5

    implicitHeight: parent.height
    implicitWidth: implicitHeight/1.6
    transform:[ Scale{ xScale: fMirror ? -1 : 1 },
                Translate{x: fMirror ? width : 0; y:0} ]

    Item {
        anchors{centerIn:parent; horizontalCenterOffset:width/3.4}
        width: parent.width/0.85
        height: parent.height * 0.95
        Component.onCompleted: {
            if(fMirror){
                anchors.right = parent.left
                anchors.margins = -parent.width/3
            }
            else{
                anchors.left = parent.left
                anchors.margins = parent.width/3
            }
        }

        CircularGuage{
            id: idGuage
            height: parent.height
            width: height
            anchors.left: parent.left
            anchors.leftMargin: 40
            minValue: valMin
            maxValue: valMax
            tickPrescaler: tickPrs
            minLimFlag: fLowLim
            maxLimFlag: fHighLim
            minLimValue: valLowLim
            maxLimValue: valHighLim
            valueReal: valReal
            spanAngle: maxAngle
            startAngle: minAngle
            minAlarmFlag: fLowAlarm
            maxAlarmFlag: fHighAlarm
            minAlarm: valMinAlarm
            maxAlarm: valMaxAlarm
            dialColor: colorOK
            warnColor: colorWarn
            alarmColor: colorAlarm
            fMirrorText: fMirror
            z:1
        }

        Indicator{
            visible: visibleIndicator
            anchors{horizontalCenter:parent.horizontalCenter; bottom:parent.verticalCenter; bottomMargin:parent.height/8;
                    horizontalCenterOffset: fMirror ? width : 0; }
            textData: ""; width: 22;
            status: indicatorStatus
            z:-1
        }

        Column{
            width: idLblNameScale.contentWidth
            anchors{horizontalCenter: parent.horizontalCenter; top: parent.verticalCenter; topMargin: parent.height/8;
                    horizontalCenterOffset: fMirror ? width : 0; }
            spacing: 5
            Label{
                id: idLblNameScale
                width: contentWidth
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.family: "Ubuntu Condensed"
                font.pixelSize: 15
                font.bold: true
                text: nameScale
                color: Color.GRAY_4
                z:-1
                transform: Scale{ xScale: fMirror ? -1 : 1 }
            }
            Label{
                width: parent.width
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.family: "Ubuntu Condensed"
                font.pixelSize: 15
                font.bold: true
                text: descriptionScale
                color: Color.GRAY_TEXT1
                z:-1
                transform: Scale{ xScale: fMirror ? -1 : 1 }
            }
        }

        Label{
            width: parent.width
            anchors.horizontalCenterOffset: fMirror ? width : 0
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
            transform: Scale{ xScale: fMirror ? -1 : 1 }
        }
    }
}


