import QtQuick 2.0

import "../settings/colors.js" as Color

Rectangle{
    id: root

    property bool activated: true
    property color activeColor: Color.GREEN_1
    property color defColor: Color.BLACK_1
    property string textData: "TEX"
    property bool blinked: false

    width: 140
    height: 50
    color: 'transparent'
    border.width: 4
    border.color: activated ? activeColor : defColor
    radius: 6

    onActivatedChanged: root.opacity = 1

    Timer{
        repeat: true
        running: blinked & activated
        interval: 500
        onTriggered: {
            if(root.opacity == 1) root.opacity = 0.2
            else root.opacity = 1
        }
    }

    Text {
        anchors.fill: parent
        color: parent.border.color
        text: qsTr(textData)
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
        anchors.leftMargin: 2
        font.family: "Ubuntu Condensed"
        font.pixelSize:  parent.height * 0.8
        font.bold: true
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }
}
