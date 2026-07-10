import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import "./settings/colors.js" as Color

ApplicationWindow {
    id: mainWindow
    
    visible: true
    width: 1600
    height: 1000
    title: "ECAM - Панель мониторинга"
    color: Color.DARK_BLUE
   
 
    Rectangle {
        id: topBar
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        height: 80
        color: Color.RECTANGLE_BLUE

        RowLayout {
            anchors.fill: parent
            anchors.leftMargin: 20
            anchors.rightMargin: 20
            spacing: 15

            Button {
                id: heliButton1
                text: "UVH_VT_70"
                Layout.preferredWidth: 150; Layout.preferredHeight: 45
                onClicked: pb.setAircraftSelection(1)
                background: Rectangle {
                    color: pb.aircraftSelection === 1 ? Color.WHITE : Color.NOT_ACTIVE
                    radius: 6
                }
                contentItem: Text {
                    text: parent.text
                    color: pb.aircraftSelection === 1 ? "black" : "white"
                    font.bold: pb.aircraftSelection === 1
                    horizontalAlignment: Text.AlignHCenter; verticalAlignment: Text.AlignVCenter
                }
            }

            Button {
                id: heliButton2
                text: "VT_25V1"
                Layout.preferredWidth: 150; Layout.preferredHeight: 45
                onClicked: pb.setAircraftSelection(2)
                background: Rectangle {
                    color: pb.aircraftSelection === 2 ? Color.WHITE : Color.NOT_ACTIVE
                    radius: 6
                }
                contentItem: Text {
                    text: parent.text
                    color: pb.aircraftSelection === 2 ? "black" : "white"
                    font.bold: pb.aircraftSelection === 2
                    horizontalAlignment: Text.AlignHCenter; verticalAlignment: Text.AlignVCenter
                }
            }

            Rectangle { Layout.preferredWidth: 1; Layout.preferredHeight: 30; opacity: 0.15 }

            Text {
                text: "Current Aircraft: " + pb.currentAircraftName 
                color: Color.WHITE; font.pixelSize: 16; Layout.fillWidth: true
            }
        }
    }

   
    StackLayout {
        id: stackLayout
        anchors.top: topBar.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.margins: 20

        currentIndex: pb.aircraftSelection - 1

        // Интерфейс первого вертолета
        HeliFirstInterface {
            Layout.fillWidth: true
            Layout.fillHeight: true
            dataReport: report

            onUpdateThrottle: pb.updateVariables(name, val)
        }

        // Интерфейс второго вертолета 
        HeliSecondInterface {
            dataReport: report2 
        }
    }
}