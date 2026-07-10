import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import "./settings/colors.js" as Color
import "./components"

GridLayout {
    id: root
    columns: 4
    columnSpacing: 15
    rowSpacing: 15

    property var dataReport

    signal updateThrottle(string name, real val)

    // БЛОК 1
    RpmPanel {
        dataReport: root.dataReport
        onThrottleChanged: function(name, val) {
            root.updateThrottle(name, val)
        }
    }

    // BLOCK 2: TCU
    TcuPanel {
        dataReport: root.dataReport
    }

    //  BLOCK 3: ERS SYSTEM
   EgtPanel {
        dataReport: root.dataReport
    }

    // BLOCK 4: RADIO / ALTITUDE
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

            ColumnLayout {
                Layout.fillWidth: true
                Layout.fillHeight: true
                spacing: 5

                Rectangle {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    color: "#0d1520"
                    radius: 6

                    ColumnLayout {
                        anchors.fill: parent
                        anchors.margins: 10
                        spacing: 2

                        Text {
                            text: "AGI Radio";
                            color: "#6a8a9a";
                            font.pixelSize: 10;
                            font.bold: true }
                        Text { text: (root.dataReport ? root.dataReport.agiRadio.toFixed(1) : "0.0");
                            color: "#4fc3f7";
                            font.pixelSize: 24;
                            font.bold: true }
                    }
                }

                Rectangle {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    color: "#0d1520"
                    radius: 6

                    ColumnLayout {
                        anchors.fill: parent
                        anchors.margins: 10
                        spacing: 2

                        Text {
                            text: "AGL Radio";
                            color: "#6a8a9a";
                            font.pixelSize: 10;
                            font.bold: true }
                        Text {
                            text: (root.dataReport ? root.dataReport.aglRadio.toFixed(1) : "0.0");
                            color: "#4fc3f7";
                            font.pixelSize: 24;
                            font.bold: true }
                    }
                }
            }
        }
    }

    // BLOCK 5: U1-U5
    Rectangle {
        Layout.fillWidth: true
        Layout.fillHeight: true
        Layout.columnSpan: 3
        color: "#1a2332"
        radius: 10
        border.color: "#2a3a4a"
        border.width: 1

        ColumnLayout {
            anchors.fill: parent
            anchors.margins: 15
            spacing: 10

            Text {
                text: "U1-U5"
                color: "#6a8a9a"
                font.bold: true
                font.pixelSize: 11
            }

            RowLayout {
                Layout.fillWidth: true
                Layout.fillHeight: true
                spacing: 10

                Rectangle {
                    Layout.fillWidth: true; Layout.fillHeight: true; color: "#0d1520"; radius: 6
                    ColumnLayout {
                        anchors.fill: parent; anchors.margins: 8; spacing: 2
                        Text {
                            text: "U1";
                            color: "#6a8a9a";
                            font.pixelSize: 10;
                            font.bold: true }
                        Text {
                            text: root.dataReport ? root.dataReport.usrU1.toFixed(2) : "0.00";
                            color: "#4fc3f7";
                            font.pixelSize: 20;
                            font.bold: true }
                    }
                }
                Rectangle {
                    Layout.fillWidth: true; Layout.fillHeight: true; color: "#0d1520"; radius: 6
                    ColumnLayout {
                        anchors.fill: parent; anchors.margins: 8; spacing: 2
                        Text {
                            text: "U2";
                            color: "#6a8a9a";
                            font.pixelSize: 10;
                            font.bold: true }
                        Text {
                            text: root.dataReport ? root.dataReport.usrU2.toFixed(2) : "0.00";
                            color: "#4fc3f7";
                            font.pixelSize: 20;
                            font.bold: true }
                    }
                }
                Rectangle {
                    Layout.fillWidth: true; Layout.fillHeight: true; color: "#0d1520"; radius: 6
                    ColumnLayout {
                        anchors.fill: parent; anchors.margins: 8; spacing: 2
                        Text {
                            text: "U3";
                            color: "#6a8a9a";
                            font.pixelSize: 10;
                            font.bold: true }
                        Text {
                            text: root.dataReport ? root.dataReport.usrU3.toFixed(2) : "0.00";
                            color: "#4fc3f7";
                            font.pixelSize: 20;
                            font.bold: true }
                    }
                }
                Rectangle {
                    Layout.fillWidth: true; Layout.fillHeight: true; color: "#0d1520"; radius: 6
                    ColumnLayout {
                        anchors.fill: parent; anchors.margins: 8; spacing: 2
                        Text {
                            text: "U4";
                            color: "#6a8a9a";
                            font.pixelSize: 10;
                            font.bold: true }
                        Text {
                            text: root.dataReport ? root.dataReport.usrU4.toFixed(2) : "0.00"; color: "#4fc3f7"; font.pixelSize: 20; font.bold: true }
                    }
                }
                Rectangle {
                    Layout.fillWidth: true; Layout.fillHeight: true; color: "#0d1520"; radius: 6
                    ColumnLayout {
                        anchors.fill: parent; anchors.margins: 8; spacing: 2
                        Text { text: "U5"; color: "#6a8a9a"; font.pixelSize: 10; font.bold: true }
                        Text { text: root.dataReport ? root.dataReport.usrU5.toFixed(2) : "0.00"; color: "#4fc3f7"; font.pixelSize: 20; font.bold: true }
                    }
                }
            }
        }
    }
}