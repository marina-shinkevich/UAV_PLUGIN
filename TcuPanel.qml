import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import "./settings/colors.js" as Color
import "./components"

// BLOCK 2: TCU
    Rectangle {
        id: tcuRoot
        property var dataReport
        Layout.fillWidth: true
        Layout.fillHeight: true
        Layout.columnSpan: 1
        color: "#1a2332"
        radius: 10
        border.color: "#2a3a4a"
        border.width: 1

        ColumnLayout {
            anchors.fill: parent
            anchors.margins: 15
            spacing: 5

            Text {
                text: "TCU"
                color: "#6a8a9a"
                font.bold: true
                font.pixelSize: 17
                anchors.top: parent.top
                anchors.topMargin: 12

                anchors.horizontalCenter: parent.horizontalCenter
            }

            RowLayout {
                Layout.fillWidth: true
                spacing: 15

                
            }

            RoundScaleSmall {  //TCU
            Layout.fillHeight: true
            Layout.fillWidth: false 
            Layout.minimumWidth: 160
            Layout.leftMargin:30

            nameScale: "MAP"
            valMin: 40
            valMax: 140
            valReal: tcuRoot.dataReport ? tcuRoot.dataReport.usrF4 : 40.0
        
    
            valMinAlarm: 140
            valMaxAlarm: 135

           
            colorAlarm: Color.RED
            fIntVal: true
            tickPrs: 5

            fMirror: true
            visibleIndicator: false
        }
        }
    }