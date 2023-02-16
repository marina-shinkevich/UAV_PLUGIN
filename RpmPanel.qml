import QtQuick 2.0
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.0
import "./components"
import "./settings/colors.js" as Color

ItemFrame{

    signal updateThrottle(string name, real val)    
    signal updateValue(string name, int val)

    nameGroup: 'RPM'

    RowLayout{
        anchors{fill: parent; leftMargin: 30; rightMargin: 30; bottomMargin: 20}
        spacing: 5

        Item{
            Layout.fillHeight: true
            Layout.fillWidth: true
            implicitHeight: parent.height
            implicitWidth: implicitHeight * 0.35

            ColumnLayout{
                height: parent.height - 20
                width: 50
                anchors.centerIn: parent
                spacing: 5

                Button{
                    Layout.preferredHeight: 30
                    Layout.fillWidth: true
                    text: '+'
                    focusPolicy: Qt.NoFocus
                    onClicked: {
                        if(Number(report.rcThrottle+0.01).toFixed(2) <= 1)
                            updateThrottle("rc_throttle", Number(report.rcThrottle+0.01).toFixed(2))
                    }
                }
                LineScale{
                    id: idRPMThrottle
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    nameScale: "% Thr"
                    fTickVisible: true
                    fLowLim: false
                    fHighLim: false
                    valLowLim: 10; valHighLim: 90
                    valMin: 0; valMax: 100
                    stepTick: 25
                    fIntVal: true
                    guage.indicatorWidth: 22
                    valReal: report.rpmThrottle.toFixed(1)
                }
                Button{
                    Layout.preferredHeight: 30
                    Layout.fillWidth: true
                    text: '-'
                    focusPolicy: Qt.NoFocus
                    onClicked: {
                        if(Number(report.rcThrottle-0.01).toFixed(2) >= 0)
                            updateThrottle("rc_throttle", Number(report.rcThrottle-0.01).toFixed(2))
                    }
                }
            }
        }

        RoundScaleSmall{
            id: idRPMEngine
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.topMargin: 15
            Layout.bottomMargin: 5
            nameScale: "% Engine"; colorOK: Color.GREEN_1
            descriptionScale: report.rpmEngineReal
            fIntVal: true
            fLowAlarm: true; fHighAlarm: true
            fLowLim: true;
            valMax: settings.rpmMax;
            valMaxAlarm: settings.rpmUpRed;
            valHighLim: settings.rpmUpYellow;
            valLowLim: settings.rpmDownYellow;
            valMinAlarm: settings.rpmDownRed;
            valMin: settings.rpmMin;
            tickPrs: 4
            fMirror: true
            valReal: report.rpmEngine.toFixed(1)
        }
        RoundScaleSmall{
            id: idMainRotor
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.topMargin: 15
            Layout.bottomMargin: 5
            nameScale: "% Rotor"; colorOK: Color.GREEN_1
            descriptionScale: report.rpmRotorReal
            fIntVal: true
            fLowAlarm: true; fHighAlarm: true
            fLowLim: true;
            valMax: settings.rpmMax;
            valMaxAlarm: settings.rpmUpRed;
            valHighLim: settings.rpmUpYellow;
            valLowLim: settings.rpmDownYellow;
            valMinAlarm: settings.rpmDownRed;
            valMin: settings.rpmMin;
            tickPrs: 4
            valReal: report.rpmRotor.toFixed(1)
        }
    }

    LabelSwitch{
        id: idLightHead
        anchors{right: parent.right; bottom: parent.bottom; margins: 13}
        width: 100
        height: 25
        keyText: qsTr("Reserve")
        value: report.reserveRpm
        onValueTriggered: updateValue("sw_sw4", flag)
    }
}
