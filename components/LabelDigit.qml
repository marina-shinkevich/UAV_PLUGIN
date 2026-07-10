import QtQuick 2.9
import QtQuick.Controls 2.12

import "../settings/colors.js" as Color

Rectangle{

    property string keyText: "RC"
    property string valueText: "0.0"
    property int lblTextSize: 15

    radius: 3
    color: Color.BLACK_2
    implicitHeight: 10
    implicitWidth: 30

    Text {
        color: Color.GRAY_TEXT
        text: qsTr(keyText)
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
        anchors.leftMargin: 2
        font.family: "Ubuntu Condensed"
        font.pixelSize: lblTextSize
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }

    Text {
        color: Color.WHITE
        text: valueText
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        anchors.rightMargin: 2
        font.bold: true
        font.family: "Ubuntu Condensed"
        font.pixelSize: lblTextSize+4
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }
}
