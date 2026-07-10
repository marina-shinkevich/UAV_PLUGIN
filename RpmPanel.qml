import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import "./settings/colors.js" as Color
import "./components"

Rectangle {
    id: rpmRoot
    
    property var dataReport
    signal throttleChanged(string name, real val)

    Layout.fillWidth: true
    Layout.fillHeight: true
    Layout.columnSpan: 2
    color: "#1a2332"
    radius: 10
    border.color: "#2a3a4a"
    border.width: 1

    Text {
        id: headerText
        text: "RPM"
        color: "#6a8a9a"
        font.bold: true
        font.pixelSize: 17
        anchors.top: parent.top
        anchors.topMargin: 12
        anchors.horizontalCenter: parent.horizontalCenter
    }

    RowLayout {
        anchors.top: headerText.bottom
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: 15
        spacing: 100

        // ПАНЕЛЬ 1:
        ColumnLayout {
            Layout.fillHeight: true
            Layout.preferredWidth: 50
            spacing: 10

            Text {
                text: "% Th"
                color: "#ffffff"
                font.pixelSize: 13
                Layout.alignment: Qt.AlignHCenter
            }

            Button {
                Layout.preferredHeight: 28
                Layout.preferredWidth: 60
                Layout.alignment: Qt.AlignHCenter
                text: '+'
                focusPolicy: Qt.NoFocus
                onClicked: {
                    var current = rpmRoot.dataReport ? rpmRoot.dataReport.ctrEngThr / 100.0 : 0
                    var next = Number((current + 0.01).toFixed(2))
                    if (next <= 1)
                        rpmRoot.throttleChanged("ctr.eng.thr", next) 
                }
            }

            Gauge {
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.minimumHeight: 100

                min: 0
                max: 100
                value: rpmRoot.dataReport ? rpmRoot.dataReport.ctrEngThr : 0
                limMin: 0
                limMax: 100
                indicatorMainColor: "#4fc3f7"
                tickInterval: 25
                tickStep: 2
                visibleTicks: true
            }

            Button {
                Layout.preferredHeight: 28
                Layout.preferredWidth: 60
                Layout.alignment: Qt.AlignHCenter
                text: '-'
                focusPolicy: Qt.NoFocus
                onClicked: {
                    var current = rpmRoot.dataReport ? rpmRoot.dataReport.ctrEngThr / 100.0 : 0
                    var next = Number((current - 0.01).toFixed(2))
                    if (next >= 0)
                        rpmRoot.throttleChanged("ctr.eng.thr", next)
                }
            }

            Text {
                text: (rpmRoot.dataReport ? rpmRoot.dataReport.ctrEngThr.toFixed(2) : "0.00")
                color: "#ffffff"
                font.pixelSize: 13
                font.bold: true
                Layout.alignment: Qt.AlignHCenter
            }
        }

        // ПАНЕЛЬ 2: Шкала % Engine
        RoundScaleSmall {
            Layout.fillHeight: true
            Layout.fillWidth: false 
            Layout.minimumWidth: 160

            nameScale: "% Engine"
            descriptionScale: rpmRoot.dataReport ? rpmRoot.dataReport.engRpm.toFixed(0) : "0"

            valMin: 88
            valMax: 112
            valReal: rpmRoot.dataReport ? rpmRoot.dataReport.engRpm : 88
            fLowLim: true
            fHighLim: true
            valLowLim: 96
            valHighLim: 104
            fLowAlarm: true
            fHighAlarm: true
            valMinAlarm: 90
            valMaxAlarm: 110

            colorOK: Color.GREEN
            colorWarn: Color.YELLOW_TEXT
            colorAlarm: Color.RED
            fIntVal: true
            tickPrs: 4

            fMirror: true
            visibleIndicator: false
        }

        // ПАНЕЛЬ 3: Шкала % Rotor
        RoundScaleSmall {
            Layout.fillHeight: true
            Layout.fillWidth: false
        // ПАНЕЛЬ 1:
            Layout.minimumWidth: 120

            nameScale: "% Rotor"
            descriptionScale: rpmRoot.dataReport ? rpmRoot.dataReport.gboxRpm.toFixed(0) : "0"

            valMin: 88
            valMax: 112
            valReal: rpmRoot.dataReport ? rpmRoot.dataReport.gboxRpm : 88

            fLowLim: true
            fHighLim: true
            valLowLim: 96
            valHighLim: 104
            fLowAlarm: true
            fHighAlarm: true
            valMinAlarm: 90
            valMaxAlarm: 110

            colorOK: "#42d335"
            colorWarn: Color.YELLOW_TEXT
            colorAlarm: Color.RED
            fIntVal: true
            tickPrs: 4

            fMirror: false
            visibleIndicator: false
        }
    }
}