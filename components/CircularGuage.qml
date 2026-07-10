import QtQuick 2.9
import QtQuick.Controls 2.12
import IGControls 2.0

import "../settings/image.js" as Img
import "../settings/colors.js" as Color

DialItem{
    property double valueReal: 0

    id: idDial
    width: parent.width
    height: width
    anchors.centerIn: parent
    startAngle: 30
    spanAngle: 300
    tickPrescaler: 10
    minLimFlag: false
    minLimValue: 2200
    maxLimFlag: false
    maxLimValue: 3800
    dialWidth: 4
    dialColor: Color.GRAY_4
    warnColor: Color.GRAY_4
    alarmColor: Color.GRAY_4
    textColor: Color.GRAY_4
    backgroundColor: Color.BLACK

    Image {
        width: parent.width/1.2
        height: width
        source: Img.needle
        anchors.centerIn: parent
        rotation: valueReal > idDial.maxValue ? idDial.spanAngle+69 : ( valueReal < idDial.minValue ? 69 : 39+startAngle + (idDial.spanAngle/(idDial.maxValue -idDial.minValue )*(valueReal - idDial.minValue)))
        Behavior on rotation { SpringAnimation { spring: 3; damping: 0.8 } }
    }
}
