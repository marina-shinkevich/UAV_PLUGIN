import QtQuick 2.0
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.14
import QtMultimedia 5.14
import "./components"

import "./settings/Strings.js" as Str
import "./settings/logic.js" as Logic
import "./settings/colors.js" as Clr

Item{
    id: root

    property string mandalaName: ''
    property int mandalaValue: 0

    readonly property bool engineWorked: true
    property string clutchStatus: '(-)'

    signal updateValue(string name, int val)

    DialogPopUp{
        id: dialog
        offset: parent.width - width
        onClickOk: {console.log('update', mandalaName, mandalaValue); updateValue(mandalaName, mandalaValue)}
    }

    ColumnLayout {
        anchors.fill: parent
        spacing: 2

        RowLayout{
            Layout.fillWidth: true
            Layout.preferredHeight: 100
            spacing: 2

            ItemFrame{
                id: ignition
                Layout.fillWidth: true
                Layout.preferredHeight: 100
                nameGroup: 'Engine'

                ColumnLayout{
                    anchors{fill: parent; margins: 10; topMargin: 15}
                    spacing: 2

                    LabelSwitch{
                        id: idIgnition1
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        keyText: qsTr("#1")
                        value: report.ign1
                        onValueTriggered:{
                            if(flag) updateValue("power_ignition", flag)
                            else{
                                mandalaName = "power_ignition"; mandalaValue = flag
                                dialog.show(idIgnition1, Str.CHANGE + ignition.nameGroup +" "+ keyText +"?");
                            }
                        }
                    }
                    LabelSwitch{
                        id: idIgnition2
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        keyText: qsTr("#2")
                        value: report.ign2
                        onValueTriggered:{
                            if(flag) updateValue("sw_sw1", flag)
                            else{
                                mandalaName = "sw_sw1"; mandalaValue = flag
                                dialog.show(idIgnition2, Str.CHANGE + ignition.nameGroup +" "+ keyText +"?");
                            }
                        }
                    }                    
                    LabelSwitch{
                        id: idIgnitionFP
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        keyText: qsTr("Fuel pump2")
                        value: report.ignFp
                        onValueTriggered:{
                            if(flag) updateValue("sw_sw2", flag)
                            else{
                                mandalaName = "sw_sw2"; mandalaValue = flag
                                dialog.show(idIgnitionFP, Str.CHANGE + engine.nameGroup +" "+ keyText +"?");
                            }
                        }
                    }
                }
            }

            ItemFrame{
                Layout.fillWidth: true
                Layout.preferredHeight: 100
                nameGroup: 'Alternator'

                ColumnLayout{
                    anchors{fill: parent; margins: 10; topMargin: 15}
                    spacing: 2
                    LabelDigit{
                        id: idAltSrvVoltage;
                        Layout.fillWidth: true; Layout.fillHeight: true;
                        keyText: "Servo voltage"
                        valueText: report.altSrvVolt.toFixed(1)
                    }
                    LabelDigit{
                        id: idAltBat12V1
                        Layout.fillWidth: true; Layout.fillHeight: true
                        keyText: "Bat 12V_1"
                        valueText: report.altBat12v1.toFixed(1)
                    }
                    LabelDigit{
                        id: idAltBat12V2
                        Layout.fillWidth: true; Layout.fillHeight: true
                        keyText: "Bat 12V_2"
                        valueText: report.altBat12v2.toFixed(1)
                    }
                }
            }
        }

        ItemFrame{
            id: clutch
            Layout.fillWidth: true
            Layout.preferredHeight: 50
            nameGroup: 'Clutch'

            RowLayout{
                anchors{fill: parent; margins: 10; topMargin: 15}
                spacing: 2

                LabelSwitch{
                    id: idClutchControl

                    property int clutch_sec: 0

                    Layout.fillWidth: true; Layout.fillHeight: true
                    keyText: qsTr("Ctr ") + clutchStatus
                    value: report.clutchCtrl
                    disableColorActive: true

                    onValueTriggered:{
                        if(flag) updateValue("sw_sw3", flag)
                        else{
                            mandalaName = "sw_sw3"; mandalaValue = flag
                            dialog.show(idClutchControl, Str.CHANGE + clutch.nameGroup +" "+ keyText +"?");
                        }
                    }
                    onValueChanged: {
                        clutch_sec = 0
                        idTimerClutchChange.start()
                    }

                    Timer{
                        id: idTimerClutchChange
                        interval: 1000; running: false; repeat: true
                        onTriggered:{
                            idClutchControl.clutch_sec++
                            if(report.clutchState !== idClutchControl.value && idClutchControl.clutch_sec < 150){
                                clutchStatus = '('+idClutchControl.clutch_sec+')'
                            }
                            else{
                                idTimerClutchChange.stop()
                            }
                        }
                    }
                }

                LabelIndicator{
                    id: idClutchState
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    keyText: qsTr("Status")
                    status: report.clutchState
                }

                LabelSwitch{
                    id: idClutchFuse
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    keyText: qsTr("Fuse")
                    value: report.clutchFuse
                    onValueTriggered: { updateValue("turret_sw1", flag) }
                }
            }
        }

        ItemFrame{
            Layout.fillWidth: true
            Layout.preferredHeight: 50
            nameGroup: 'Engine Choke'
            visible: false

            LabelSlider{
                id: idIgnitionChoke
                height: 25
                anchors{fill: parent; margins: 10; topMargin: 15}
                widthText: 40; keyText: ""
                val: report.ignChoke.toFixed(2)*100
                onMoveValue: updateValue("ctr_mixture", val)
            }
        }

        ItemFrame{
            Layout.fillWidth: true
            Layout.preferredHeight: 50
            nameGroup: 'Colling'

            RowLayout{
                anchors{fill: parent; margins: 10; topMargin: 15}
                spacing: 2
                LabelSwitch{
                    id: idFanAuto
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    keyText: qsTr("AUTO")
                    value: report.fanAuto
                    onValueTriggered:{
                        updateValue("Ip", Logic.setFanState(flag, idFan1.value, idFan2.value))
                    }
                }
                LabelSwitch{
                    id: idFan1
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    keyText: qsTr("FAN1")
                    enabled: !idFanAuto.value
                    value: report.fan1
                    onValueTriggered:{
                        updateValue("Ip", Logic.setFanState(idFanAuto.value, flag, idFan2.value))
                    }
                }
                LabelSwitch{
                    id: idFan2
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    keyText: qsTr("FAN2")
                    enabled: !idFanAuto.value
                    value: report.fan2
                    onValueTriggered:{
                        updateValue("Ip", Logic.setFanState(idFanAuto.value, idFan1.value, flag))
                    }
                }
            }
        }

        ItemFrame{
            Layout.fillWidth: true
            Layout.preferredHeight: 50
            nameGroup: 'Lights'

            RowLayout{
                anchors{fill: parent; margins: 10; topMargin: 15}
                spacing: 2

                LabelSwitch{
                    id: idLightTaxi
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    keyText: qsTr("Taxi")
                    value: report.lightTaxi
                    onValueTriggered: updateValue("sw_taxi", flag)
                }
                LabelSwitch{
                    id: idLightNav
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    keyText: qsTr("Nav")
                    value: report.lightNav
                    onValueTriggered: updateValue("sw_lights", flag)
                }
            }
        }

        Item{
            Layout.minimumHeight: 2
            Layout.fillWidth: true
            Layout.fillHeight: true
        }
        Item{
            Layout.fillWidth: true
            Layout.preferredHeight: 40
            Button{
                anchors{fill: parent; leftMargin: 10; rightMargin: 10}
                text: report.limit === 0 ? "Ok" : (report.limit === 1 ? "Warning" : "Alarm")
                clip: true
                onClicked: report.muteLimitMap()

                Rectangle{
                    anchors{fill: parent; topMargin: 5; bottomMargin: 5}
                    opacity: 0.5
                    color: report.limit === 0 ? Clr.BLACK_2 : (report.limit === 1 ? Clr.ORANGE_TEXT : Clr.RED_TEXT)
                    radius: 2
                }
            }
        }

        ItemFrame{
            Layout.fillWidth: true
            Layout.preferredHeight: 55
            nameGroup: 'Starter'

            RowLayout{
                anchors{fill: parent; margins: 10; topMargin: 10}
                spacing: 2

                LabelSwitch{
                    id: idForceStart
                    Layout.fillWidth: true
                    Layout.preferredHeight: 30
                    keyText: qsTr("Force start")
                    onValueTriggered:{ value = flag }
                }

                DelayButton{
                    id: idIgnitionStarter
                    Layout.preferredWidth: parent.width/2 - parent.spacing/2
                    Layout.preferredHeight: 40
                    delay: !idForceStart.value ? 3000 : 1
                    text: qsTr("Start ") + ((progress != 0 && !checked && !idForceStart.value) ?
                                             Number(delay*progress / 1000).toFixed(0) : "")
                    font.pixelSize: 14
                    checked: report.ignStarter
                    onActivated: {
                        if(!idForceStart.value) updateValue("ctrb_starter", true)
                        else updateValue("sw_starter", true)
                    }
                }
            }
        }
    }


    SoundEffect{
        id: beep
        loops: SoundEffect.Infinite
        source: report.limit === 0 ? "" : (report.limit === 1 ? "../audio/warning.wav" : "../audio/alarm.wav")
        onSourceChanged: {
            if(report.limit === 0) beep.stop()
            else beep.play()
        }
    }
}
