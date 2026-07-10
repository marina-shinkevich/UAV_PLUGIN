import QtQuick 2.12
import QtQuick.Layouts 1.12
import "./settings/colors.js" as Color

GridLayout {
    id: root
    columns: 3
    columnSpacing: 15
    rowSpacing: 15

    property var dataReport


    // BLOCK 1: POWER 
   
    Rectangle {
        Layout.fillWidth: true
        Layout.fillHeight: true
        color: "#1a2332"
        radius: 10
        border.color: "#2a3a4a"
        border.width: 1

        ColumnLayout {
            anchors.fill: parent
            anchors.margins: 15
            spacing: 8

            Text {
                text: "POWER"
                color: "#6a8a9a"
                font.bold: true
                font.pixelSize: 11
            }

            RowLayout {
                Layout.fillWidth: true
                spacing: 10

                Rectangle {
                    width: 40
                    height: 40
                    radius: 20
                    color: "#4fc3f7"
                    opacity: 0.2

                    Text {
                        anchors.centerIn: parent
                        text: "B"
                        font.pixelSize: 20
                        color: "#4fc3f7"
                    }
                }

                ColumnLayout {
                    Layout.fillWidth: true
                    spacing: 2

                    Text {
                        text: (root.dataReport ? root.dataReport.batVoltage.toFixed(1) : "0.0") + " V"
                        color: "#4fc3f7"
                        font.pixelSize: 22
                        font.bold: true
                    }
                    Text {
                        text: "Battery Voltage"
                        color: "#8a9aaa"
                        font.pixelSize: 10
                    }
                }
            }

            GridLayout {
                Layout.fillWidth: true
                columns: 2
                columnSpacing: 20
                rowSpacing: 5

                Text {
                    text: "Battery Current:"
                    color: "#8a9aaa"
                    font.pixelSize: 11
                }
                Text {
                    text: (root.dataReport ? root.dataReport.batCurrent.toFixed(1) : "0.0") + " A"
                    color: "#b0c4d9"
                    font.pixelSize: 14
                    font.bold: true
                }

                Text {
                    text: "Engine Voltage:"
                    color: "#8a9aaa"
                    font.pixelSize: 11
                }
                Text {
                    text: (root.dataReport ? root.dataReport.engVoltage.toFixed(1) : "0.0") + " V"
                    color: "#b0c4d9"
                    font.pixelSize: 14
                    font.bold: true
                }
            }
        }
    }

    // BLOCK 2

    Rectangle {
        Layout.fillWidth: true
        Layout.fillHeight: true
        color: "#1a2332"
        radius: 10
        border.color: "#2a3a4a"
        border.width: 1

        ColumnLayout {
            anchors.fill: parent
            anchors.margins: 15
            spacing: 8

            Text {
                text: "TEMP"
                color: "#6a8a9a"
                font.bold: true
                font.pixelSize: 11
                
            }

            RowLayout {
                Layout.fillWidth: true
                spacing: 10

                Rectangle {
                    width: 40
                    height: 40
                    radius: 20
                    color: "#ffd54f"
                    opacity: 0.2

                    Text {
                        anchors.centerIn: parent
                        text: "R"
                        font.pixelSize: 20
                        color: "#ffd54f"
                    }
                }

                ColumnLayout {
                    Layout.fillWidth: true
                    spacing: 2

                    Text {
                        text: (root.dataReport ? root.dataReport.engRpm.toFixed(0) : "0") + " RPM"
                        color: "#ffd54f"
                        font.pixelSize: 22
                        font.bold: true
                    }
                    Text {
                        text: "Engine RPM"
                        color: "#8a9aaa"
                        font.pixelSize: 10
                    }
                }
            }

            GridLayout {
                Layout.fillWidth: true
                columns: 2
                columnSpacing: 20
                rowSpacing: 5

                Text {
                    text: "Engine Temperature:"
                    color: "#8a9aaa"
                    font.pixelSize: 11
                }
                Text {
                    text: (root.dataReport ? root.dataReport.engTemp.toFixed(1) : "0.0") + " °C"
                    color: root.dataReport && root.dataReport.engTemp > 95 ? "#ff5252" : "#b0c4d9"
                    font.pixelSize: 14
                    font.bold: true
                }

                Text {
                    text: "Gear Box Temperature:"
                    color: "#8a9aaa"
                    font.pixelSize: 11
                }
                Text {
                    text: (root.dataReport ? root.dataReport.engineGearBoxTemp.toFixed(1) : "0.0") + " °C"
                    color: root.dataReport && root.dataReport.engineGearBoxTemp > 80 ? "#ff5252" : "#b0c4d9"
                    font.pixelSize: 14
                    font.bold: true
                }
            }
        }
    }


    // BLOCK 3: ERS

    Rectangle {
        Layout.fillWidth: true
        Layout.fillHeight: true
        color: "#1a2332"
        radius: 10
        border.color: "#2a3a4a"
        border.width: 1

        ColumnLayout {
            anchors.fill: parent
            anchors.margins: 15
            spacing: 8

            Text {
                text: "ERS"
                color: "#6a8a9a"
                font.bold: true
                font.pixelSize: 11
               
            }

            RowLayout {
                Layout.fillWidth: true
                spacing: 10

                Rectangle {
                    width: 40
                    height: 40
                    radius: 20
                    color: root.dataReport && root.dataReport.ersLaunch > 0 ? "#ff5252" : "#4fc3f7"
                    opacity: 0.3

                    Text {
                        anchors.centerIn: parent
                        text: root.dataReport && root.dataReport.ersLaunch > 0 ? "!" : "E"
                        font.pixelSize: 20
                        color: root.dataReport && root.dataReport.ersLaunch > 0 ? "#ff5252" : "#4fc3f7"
                    }
                }

                ColumnLayout {
                    Layout.fillWidth: true
                    spacing: 2

                    Text {
                        text: (root.dataReport ? root.dataReport.ersLaunch.toFixed(1) : "0.0")
                        color: "#4fc3f7"
                        font.pixelSize: 18
                        font.bold: true
                    }
                    Text {
                        text: "ERS Launch Control"
                        color: "#8a9aaa"
                        font.pixelSize: 10
                    }
                }
            }

            GridLayout {
                Layout.fillWidth: true
                columns: 2
                columnSpacing: 20
                rowSpacing: 5

                Text {
                    text: "ERS Status:"
                    color: "#8a9aaa"
                    font.pixelSize: 11
                }
                Text {
                    text: root.dataReport ? root.dataReport.ersStatus.toFixed(0) : "0"
                    color: "#b0c4d9"
                    font.pixelSize: 14
                    font.bold: true
                }

                Text {
                    text: "ERS Block:"
                    color: "#8a9aaa"
                    font.pixelSize: 11
                }
                Text {
                    text: root.dataReport ? root.dataReport.ersBlock.toFixed(0) : "0"
                    color: "#b0c4d9"
                    font.pixelSize: 14
                    font.bold: true
                }
            }
        }
    }

    // BLOCK 4: RADIO
  
    Rectangle {
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
            spacing: 8

            Text {
                text: "RADIO"
                color: "#6a8a9a"
                font.bold: true
                font.pixelSize: 11
              
            }

            Rectangle {
                Layout.fillWidth: true
                height: 50
                color: "#0d1520"
                radius: 6

                ColumnLayout {
                    anchors.fill: parent
                    anchors.margins: 10
                    spacing: 2

                    Text {
                        text: "AGI Radio"
                        color: "#6a8a9a"
                        font.pixelSize: 10
                        font.bold: true
                    }
                    Text {
                        text: (root.dataReport ? root.dataReport.agiRadio.toFixed(1) : "0.0")
                        color: "#4fc3f7"
                        font.pixelSize: 18
                        font.bold: true
                    }
                }
            }

            Rectangle {
                Layout.fillWidth: true
                height: 50
                color: "#0d1520"
                radius: 6

                ColumnLayout {
                    anchors.fill: parent
                    anchors.margins: 10
                    spacing: 2

                    Text {
                        text: "AGL Radio"
                        color: "#6a8a9a"
                        font.pixelSize: 10
                        font.bold: true
                    }
                    Text {
                        text: (root.dataReport ? root.dataReport.aglRadio.toFixed(1) : "0.0")
                        color: "#4fc3f7"
                        font.pixelSize: 18
                        font.bold: true
                    }
                }
            }
        }
    }

    // BLOCK 5: U1-U5

    Rectangle {
        Layout.fillWidth: true
        Layout.fillHeight: true
        Layout.columnSpan: 2
        color: "#1a2332"
        radius: 10
        border.color: "#2a3a4a"
        border.width: 1

        ColumnLayout {
            anchors.fill: parent
            anchors.margins: 15
            spacing: 12

            Text {
                text: "U1-U5"
                color: "#6a8a9a"
                font.bold: true
                font.pixelSize: 11
                
            }

            GridLayout {
                Layout.fillWidth: true
                Layout.fillHeight: true
                columns: 3
                rowSpacing: 8
                columnSpacing: 10

                Rectangle {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    color: "#0d1520"
                    radius: 6

                    ColumnLayout {
                        anchors.fill: parent
                        anchors.margins: 8
                        spacing: 2

                        Text {
                            text: "U1"
                            color: "#6a8a9a"
                            font.pixelSize: 10
                            font.bold: true
                        }
                        Text {
                            text: root.dataReport ? root.dataReport.usrU1.toFixed(2) : "0.00"
                            color: "#4fc3f7"
                            font.pixelSize: 20
                            font.bold: true
                        }
                    }
                }

                Rectangle {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    color: "#0d1520"
                    radius: 6

                    ColumnLayout {
                        anchors.fill: parent
                        anchors.margins: 8
                        spacing: 2

                        Text {
                            text: "U2"
                            color: "#6a8a9a"
                            font.pixelSize: 10
                            font.bold: true
                        }
                        Text {
                            text: root.dataReport ? root.dataReport.usrU2.toFixed(2) : "0.00"
                            color: "#4fc3f7"
                            font.pixelSize: 20
                            font.bold: true
                        }
                    }
                }

                Rectangle {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    color: "#0d1520"
                    radius: 6

                    ColumnLayout {
                        anchors.fill: parent
                        anchors.margins: 8
                        spacing: 2

                        Text {
                            text: "U3"
                            color: "#6a8a9a"
                            font.pixelSize: 10
                            font.bold: true
                        }
                        Text {
                            text: root.dataReport ? root.dataReport.usrU3.toFixed(2) : "0.00"
                            color: "#4fc3f7"
                            font.pixelSize: 20
                            font.bold: true
                        }
                    }
                }

                Rectangle {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    color: "#0d1520"
                    radius: 6

                    ColumnLayout {
                        anchors.fill: parent
                        anchors.margins: 8
                        spacing: 2

                        Text {
                            text: "U4"
                            color: "#6a8a9a"
                            font.pixelSize: 10
                            font.bold: true
                        }
                        Text {
                            text: root.dataReport ? root.dataReport.usrU4.toFixed(2) : "0.00"
                            color: "#4fc3f7"
                            font.pixelSize: 20
                            font.bold: true
                        }
                    }
                }

                Rectangle {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    color: "#0d1520"
                    radius: 6

                    ColumnLayout {
                        anchors.fill: parent
                        anchors.margins: 8
                        spacing: 2

                        Text {
                            text: "U5"
                            color: "#6a8a9a"
                            font.pixelSize: 10
                            font.bold: true
                        }
                        Text {
                            text: root.dataReport ? root.dataReport.usrU5.toFixed(2) : "0.00"
                            color: "#4fc3f7"
                            font.pixelSize: 20
                            font.bold: true
                        }
                    }
                }

                Item {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                }
            }
        }
    }
}