import QtQuick 2.9
import QtQuick.Controls 2.12
import QtGraphicalEffects 1.0

import "../settings/colors.js" as Color

Rectangle {

    property int status: 1  //0 - ok; 1 - warning; 2 - alarm; 3 - disabled
    property string textData: "text"
    property string textColor: Color.GRAY_4

    radius: 3
    color: Color.BLACK_2
    width: 90
    height: 18
    clip: true

    Rectangle {
        id: idIndicator
        anchors.left: parent.left
        anchors.leftMargin: 2
        anchors.verticalCenter: parent.verticalCenter
        height: 12//parent.height/1.6
        width: 18//30   10
        radius: 2//3    5
        color: toColor(status) //status === 0 ? Color.GREEN_1 : (status === 1 ? Color.YELLOW_TEXT : Color.RED)
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
    Label{
        anchors.right: parent.right
        anchors.rightMargin: 2
        anchors.verticalCenter: parent.verticalCenter
        color: textColor
        text: textData
        font.bold: true
        font.family: "Ubuntu Condensed"
        font.pixelSize: 18
        opacity: parent.enabled ? 1 : 0.3
    }

    function toColor(status){
        switch(status){
        case 0: return Color.GREEN_1;
        case 1: return Color.YELLOW_TEXT;
        case 2: return Color.RED;
        default: return Color.BLACK_2
        }
    }
}

