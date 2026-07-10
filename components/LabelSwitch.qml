import QtQuick 2.9
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.1

import "../settings/colors.js" as Color

Rectangle{

    property string keyText: "RC"
    property bool value: false
    property int lblTextSize: 15
    property bool disableColorActive: false

    signal valueTriggered(bool flag)

    radius: 3
    color: Color.BLACK_2
    width: 150
    height: 25
    clip: true

    Text {
        color: Color.WHITE
        text: qsTr(keyText)
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
        anchors.leftMargin: 2
        font.bold: true
        font.family: "Ubuntu Condensed"
        font.pixelSize: lblTextSize
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }

    Switch{
        id: idSwitch
        Material.accent: Color.GREEN_1;
        anchors{right: parent.right; verticalCenter: parent.verticalCenter; rightMargin: -8}
        checked: value
        focusPolicy: Qt.NoFocus
        background: Item {
            visible: disableColorActive
            Rectangle{
                anchors{fill: parent; topMargin: 17; bottomMargin: 17; leftMargin: 12; rightMargin: 12}
                radius: height/2
                opacity: (idSwitch.checked || !enabled) ? 0 : 1
                color: "red"
            }
        }
    }

    MouseArea{
        anchors.fill: parent
        onClicked: valueTriggered(!value)
    }
}

