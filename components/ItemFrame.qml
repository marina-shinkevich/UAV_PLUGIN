import QtQuick 2.9
import QtQuick.Controls 2.12

import "../settings/colors.js" as Color

Item {

    property string backGroundColorGroup: Color.BLACK
    property string nameGroup: "Group"

    height: 400
    width: 300

    Rectangle{
        id: idGroupRec
        anchors.centerIn: parent
        width: parent.width-10
        height: parent.height-10
        radius: 6
        color: "transparent"
        border.width: 1
        border.color: Color.GRAY_TEXT1
    }

    Rectangle{
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: idGroupRec.top
        anchors.topMargin: -1
        color: backGroundColorGroup
        height: idGroupRec.border.width+2
        width: idGroupLbl.width+15

        Label{
            id: idGroupLbl
            anchors.centerIn: parent
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.family: "Ubuntu Condensed"
            font.pixelSize: 15
            font.bold: true
            text: nameGroup
            color: Color.GRAY_TEXT1
        }
    }
}
