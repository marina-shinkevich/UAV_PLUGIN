import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import "./settings/colors.js" as Color
import "./components"


//  BLOCK 3: ERS SYSTEM
    Rectangle {
        id: egtRoot
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
                text: "EGT"
                color: "#6a8a9a"
                font.bold: true
                font.pixelSize: 17
                Layout.alignment: Qt.AlignHCenter
                Layout.topMargin: 12
            }

            GridLayout {
                Layout.fillWidth: true
                Layout.fillHeight: true
                columns: 4
                columnSpacing: 5
                rowSpacing: 2

                LineScale {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    
                    nameScale: "1"
                    fTickVisible: true
                    
                    valMin: 500
                    valMax: 1000
                    valLowLim: 1000
                    valHighLim: 950
                    fLowLim: false
                    fHighLim: true
                    stepTick: 100
                    stepTickMinor: 5
                    valReal: egtRoot.dataReport ? egtRoot.dataReport.usrW4.toFixed(1) : 500
                }

               
                LineScale {
                    Layout.fillWidth: true
                    Layout.fillHeight: true 
                    nameScale: "2"
                    fTickVisible: false
                 
                    valMin: 500
                    valMax: 1000
                    valLowLim: 1000
                    valHighLim: 950
                    fLowLim: false
                    fHighLim: true
                    stepTick: 100
                    stepTickMinor: 5
                    valReal: egtRoot.dataReport ? egtRoot.dataReport.usrW5 : 500
                }

                LineScale {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    
                    nameScale: "3"
                    fTickVisible: false
                   valMin: 500
                    valMax: 1000
                    valLowLim: 1000
                    valHighLim: 950
                    fLowLim: false
                    fHighLim: true
                    stepTick: 100
                    stepTickMinor: 5
                    valReal: egtRoot.dataReport ? egtRoot.dataReport.usrW6 : 500
                }
                LineScale {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    
                    nameScale: "4"
                    fTickVisible: false
                    
                    valMin: 500
                    valMax: 1000
                    valLowLim: 1000
                    valHighLim: 950
                    fLowLim: false
                    fHighLim: true
                    stepTick: 100
                    stepTickMinor: 5
                    valReal: egtRoot.dataReport ? egtRoot.dataReport.usrW7 : 500
                }
            }
        }
    }