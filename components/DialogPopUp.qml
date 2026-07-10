import QtQuick 2.9
import QtQuick.Controls 2.12

import "../settings/colors.js" as Color

Popup {
    id: root

    property int offset: 0
    signal clickOk()

    function show(item, _msg, offsetX = 0, offsetY = 0){
        var point = mapFromItem(root.parent, item.x, item.y+item.height)
        root.x = point.x + offset - 5 + offsetX
        root.y = point.y + 20 + offsetY

        idMsg.text = _msg
        root.open()
    }

    function setParentItem(_mainItem, _parentItem){
        mainItem = _mainItem
        parentItem = _parentItem
    }

    x: parent.width/2 - width/2
    y: parent.height/2 - height/2
    width: 320
    height: 120
    modal: true
    focus: true
    dim: false
    padding: 0
    background: Rectangle{
        anchors.fill: parent
        radius: 5
        color: 'black'
        border.width: 1
        border.color: Color.GRAY_TEXT1
    }
    closePolicy: Popup.CloseOnPressOutside



    Text {
        id: idMsg
        color: 'white'
        text: ""
        wrapMode: Text.WordWrap
        anchors{top: parent.top; left: parent.left; right: parent.right; bottom: idButton.top; margins:5}
        font.family: 'Arial'
        font.pixelSize: 16
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }

    Button{
        id: idButton
        width: 50
        height: 40
        anchors{horizontalCenter:parent.horizontalCenter; bottom: parent.bottom; margins:5}
        text: 'Ok'
        onClicked: {clickOk(); root.close()}
    }
}
