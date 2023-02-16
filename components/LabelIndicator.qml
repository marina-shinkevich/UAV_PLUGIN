
import QtQuick 2.9
import QtQuick.Controls 2.12
import QtGraphicalEffects 1.0

import "../settings/colors.js" as Color

Rectangle {

    property bool status: true  //0 - ok; 1 - warning; 2 - alarm; 3 - disabled
    property string keyText: "text"
    property int lblTextSize: 15

    radius: 3
    color: Color.BLACK_2
    width: 150
    height: 25
    clip: true

    Text {
        color: Color.GRAY_TEXT
        text: qsTr(keyText)
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
        anchors.leftMargin: 3
        font.bold: true
        font.family: "Ubuntu Condensed"
        font.pixelSize: lblTextSize
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }

    Rectangle {
        id: idIndicator
        anchors.right: parent.right
        anchors.rightMargin: 3
        anchors.verticalCenter: parent.verticalCenter
        height: 12//parent.height/1.6
        width: 18//30   10
        radius: 2//3    5
        color: status ? Color.GREEN_1 : Color.RED
        clip: true
        opacity: parent.enabled ? 1 : 0.3

        RadialGradient {
            width: parent.width*4
            height: parent.height*4
            anchors.centerIn: parent
            opacity: 0.2
            anchors.verticalCenterOffset: parent.height
            gradient: Gradient {
                GradientStop { position: 0.0; color: "white" }
                GradientStop { position: 0.4; color: "black"}
            }
        }
    }
}

