import QtQuick 2.9
import QtQuick.Controls 2.12

import "../settings/colors.js" as Color

Item{
    property alias guage: idGuage
    property string nameScale: "scale1"
    property bool fTickVisible: true
    property bool fIntVal: false

    property bool fLowLim: false
    property bool fHighLim: true
    property double valLowLim: 30
    property double valHighLim: 80

    property double valMin: 10
    property double valMax: 100
    property double valReal: 10    

    readonly property string barColor:    ((valReal < valLowLim && fLowLim) ||
                                           (valReal > valHighLim && fHighLim)) ? Color.RED : Color.BLUE1
    readonly property string colorLblVal: ((valReal < valLowLim && fLowLim) ||
                                           (valReal > valHighLim && fHighLim)) ? Color.RED : Color.GRAY_TEXT1

    property double stepTick: 100
    property double stepTickMinor: 5

    implicitWidth: fTickVisible ? 60 : 45
    implicitHeight: 100

    Column{
        id: idLineScaleColumn
        spacing: 0
        width: parent.width
        height: parent.height
        clip: true

        Label{
            id: idNameLbl
            height: 20
            width: idGuage.indicatorWidth
            anchors{right: parent.right; rightMargin: 5}
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.family: "Ubuntu Condensed"
            font.pixelSize: 15
            font.bold: true
            text: nameScale
            color: Color.GRAY_4
        }

        Gauge{
            id: idGuage
            anchors.right: parent.right
            height: parent.height-idNameLbl.height-idLblbVal.height
            width: parent.width
            min: valMin
            value: valReal
            max: valMax
            fLimMin: fLowLim
            fLimMax: fHighLim
            limMin: valLowLim
            limMax: valHighLim
            tickInterval: stepTick
            tickStep: stepTickMinor
            visibleTicks: fTickVisible
        }

        Label{
            id: idLblbVal
            height: 20
            anchors.right: parent.right
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.family: "Ubuntu Condensed"
            font.pixelSize: 18
            font.bold: true
            text: fIntVal ? valReal : valReal.toFixed(1)
            color: colorLblVal
        }
    }
}
