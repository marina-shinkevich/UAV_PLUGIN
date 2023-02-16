import QtQuick 2.9
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.1

import "../settings/colors.js" as Color

Rectangle{

    property string keyText: "RC"
    property int lblTextSize: 15

    property double val: 0
    property double valFrom: 0
    property double valTo: 100
    property double valStep: 5
    property int signCnt: 0
    property int widthText: 150

    signal clickValue(double val)
    signal moveValue(double val)

    radius: 3
    color: Color.BLACK_2
    width: 150
    height: 25
    clip: true

    Row{
        id: idRow1
        height: parent.height
        anchors{left:parent.left; leftMargin:2; top:parent.top; bottom:parent.bottom}
        spacing: 2

        Text {
            color: Color.GRAY_TEXT
            text: qsTr(keyText)
            font.family: "Ubuntu Condensed"
            font.pixelSize: lblTextSize
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }
        Button{
            height: parent.height
            width: height
            text: '-'
            focusPolicy: Qt.NoFocus
            onClicked: {idSlider.decrease()}
        }
    }

    Slider{
        id: idSlider
        anchors{left: idRow1.right; right: idRow2.left; verticalCenter: parent.verticalCenter;}
        focusPolicy: Qt.NoFocus

        value: val
        from: valFrom
        to: valTo
        stepSize: valStep

        onPressedChanged: { if(!pressed && value.toFixed(1)!=val.toFixed(1)){val = value; clickValue(val)} }
        onMoved: {if(value.toFixed(1)!=val.toFixed(1)){val = value; moveValue(val)} }
        onValueChanged: {if(value.toFixed(1)!=val.toFixed(1)){val = value; moveValue(val)} }
    }

    Row{
        id: idRow2
        height: parent.height
        anchors{right:parent.right; rightMargin:2; top:parent.top; bottom:parent.bottom}
        spacing: 2

        Button{
            height: parent.height
            width: height
            text: '+'
            focusPolicy: Qt.NoFocus
            onClicked: {idSlider.increase();}
        }
        Text {
            color: Color.WHITE
            height: parent.height
            width: 30
            text: idSlider.value.toFixed(signCnt)
            font.bold: true
            font.family: "Ubuntu Condensed"
            font.pixelSize: lblTextSize+4
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignRight
        }
    }
}

