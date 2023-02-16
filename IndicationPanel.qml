import QtQuick 2.0
import QtQuick.Layouts 1.14
import "./components"

import "./settings/colors.js" as Color

ItemFrame{

    nameGroup: 'Indication'

    ColumnLayout{
        anchors{fill: parent; margins: 10; topMargin: 12}
        spacing: 5

        RowLayout{
            Layout.fillWidth: true
            Layout.fillHeight: true
            spacing: parent.spacing

            LightIndication{
                Layout.fillWidth: true; Layout.fillHeight: true;
                textData: 'Gen'
                activeColor: Color.RED_TEXT
                activated: report.altRectLamp
            }
            LightIndication{
                Layout.fillWidth: true; Layout.fillHeight: true;
                textData: 'Alt'
                activeColor: Color.RED_TEXT
                activated: report.altAltLamp
            }
            LightIndication{
                Layout.fillWidth: true; Layout.fillHeight: true;
                textData: 'ERS DISARM'
                activeColor: Color.ORANGE_TEXT
                activated: report.statusErsArm
            }
            LightIndication{
                Layout.fillWidth: true; Layout.fillHeight: true;
                textData: 'Fuel press'
                activeColor: Color.RED_TEXT
                activated: report.engineFuelPress > settings.engineFuelPressLimMax ||
                           report.engineFuelPress < settings.engineFuelPressLimMin
            }
            LightIndication{
                Layout.fillWidth: true; Layout.fillHeight: true;
                textData: 'Fuel low'
                activeColor: Color.RED_TEXT
                activated: report.engineFuel < settings.engineFuelLimMin
            }
            LightIndication{
                Layout.fillWidth: true; Layout.fillHeight: true;
                textData: 'Clutch ' + generateClutchText(report.clutchVoltage)
                activeColor: Color.RED_TEXT
                activated:  report.clutchVoltage >= 0.2
            }
            LightIndication{
                Layout.fillWidth: true; Layout.fillHeight: true;
                textData: 'Gear'
                activeColor: Color.RED_TEXT
                activated:  report.gear
            }
            LightIndication{
                Layout.fillWidth: true; Layout.fillHeight: true;
                textData: 'Servo'
                activeColor: Color.RED_TEXT
                activated:  report.servo
            }
            LightIndication{
                Layout.fillWidth: true; Layout.fillHeight: true;
                textData: 'CTR lim'
                activeColor: Color.ORANGE_TEXT
                activated: report.ctrLim
            }
        }

        RowLayout{
            Layout.fillWidth: true
            Layout.fillHeight: true
            spacing: parent.spacing


            LightIndication{
                Layout.fillWidth: true; Layout.fillHeight: true;
                textData: 'FR ERR'
                activeColor: Color.ORANGE_TEXT
                activated: report.statusBB
            }
            LightIndication{
                Layout.fillWidth: true; Layout.fillHeight: true;
                textData: 'Oil'
                activeColor: Color.RED_TEXT
                activated: report.engineOP < settings.engineOPLimMin ||
                           report.engineOP > settings.engineOPLimMax
            }
            LightIndication{
                Layout.fillWidth: true; Layout.fillHeight: true;
                textData: 'TCU'
                activeColor: Color.ORANGE_TEXT
                activated: report.tcuCaution
            }
            LightIndication{
                Layout.fillWidth: true; Layout.fillHeight: true;
                textData: 'Boost'
                activeColor: Color.ORANGE_TEXT
                activated: report.tcuWarn
            }
            LightIndication{
                Layout.fillWidth: true; Layout.fillHeight: true;
                textData: 'Coolant'
                activeColor: Color.ORANGE_TEXT
                activated: report.coolLvl
            }
            LightIndication{
                Layout.fillWidth: true; Layout.fillHeight: true;
                textData: 'Frame'
                activeColor: Color.ORANGE_TEXT
                activated: report.statusFramePrs
            }
            LightIndication{
                Layout.fillWidth: true; Layout.fillHeight: true;
                textData: 'Reserve RPM'
                activeColor: Color.ORANGE_TEXT
                activated: report.reserveRpm
            }
            LightIndication{
                Layout.fillWidth: true; Layout.fillHeight: true;
                textData: 'AR mode'
                activeColor: Color.ORANGE_TEXT
                activated: report.gMode
            }
            LightIndication{
                Layout.fillWidth: true; Layout.fillHeight: true;
                textData: 'Chip'
                activeColor: Color.ORANGE_TEXT
                activated: report.chipDetector
            }
        }
    }

    function generateClutchText(value){
        if(value < 0.2) return ''
        else if(value > 6.0) return '>-<'
        else if(value >= 0.2 && value <= 6.0) return '<->'
    }
}
