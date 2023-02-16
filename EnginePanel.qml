import QtQuick 2.0
import QtQuick.Layouts 1.14
import "./components"

ItemFrame{

    nameGroup: 'Engine'

    RowLayout{
        anchors{fill: parent; margins: 20}
        spacing: 5

        LineScale{
            id: idFuelLevel
            Layout.fillWidth: true
            Layout.fillHeight: true
            nameScale: "Fuel"
            fTickVisible: true
            fLowLim: true
            fHighLim: false
            stepTick: 30
            valMin: settings.engineFuelMin; valLowLim: settings.engineFuelLimMin
            valMax: settings.engineFuelMax; valHighLim: settings.engineFuelLimMax
            valReal: report.engineFuel
        }

        LineScale{
            id: idFFLevel_1
            Layout.fillWidth: true
            Layout.fillHeight: true
            nameScale: "FF-1"
            fTickVisible: true
            fLowLim: true
            fHighLim: true
            stepTick: 10
            valMin: settings.firstFFSensorMin; valLowLim: settings.firstFFSensorLimMin
            valMax: settings.firstFFSensorMax; valHighLim: settings.firstFFSensorLimMax
            valReal: report.firstFFSensor
        }
        LineScale{
            id: idFFLevel_2
            Layout.fillWidth: true
            Layout.fillHeight: true
            nameScale: "FF-2"
            fTickVisible: true
            fLowLim: true
            fHighLim: true
            stepTick: 10
            valMin: settings.secondFFSensorMin; valLowLim: settings.secondFFSensorLimMin
            valMax: settings.secondFFSensorMax; valHighLim: settings.secondFFSensorLimMax
            valReal: report.secondFFSensor
        }
        RoundScale{
            id: idEngOilTemp;
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.margins: 12
            nameScale: "Oil temp";
            fLowLim: true; valMin: settings.engineOTMin; valLowLim: settings.engineOTLimMin;
            fHighLim: true; valHighLim: settings.engineOTLimMax; valMax: settings.engineOTMax;
            valReal: report.engineOT
        }
        RoundScale{
            id: idCHT1;
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.margins: 12
            nameScale: "CHT1";
            fLowLim: true; valMin: settings.engineETMin; valLowLim: settings.engineETLimMin;
            fHighLim: true; valHighLim: settings.engineETLimMax; valMax: settings.engineETMax;
            fIntVal: true
            valReal: report.engineET
        }

        RoundScaleSmall{
            id: idFuelPress
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.margins: 12
            nameScale: "Fuel pressure";
            fLowLim: true;
            valLowLim: settings.engineFuelPressLimMin;
            valMin: settings.engineFuelPressMin
            fHighLim: true;
            valHighLim: settings.engineFuelPressLimMax;
            valMax: settings.engineFuelPressMax
            valReal: report.engineFuelPress
        }
        RoundScaleSmall{
            id: idOilPress
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.margins: 12
            nameScale: "Oil pressure";
            fLowLim: true; valLowLim: settings.engineOPLimMin; valMin: settings.engineOPMin;
            fHighLim: true; valHighLim: settings.engineOPLimMax; valMax: settings.engineOPMax;
            valReal: report.engineOP
        }
        RoundScale{
            id: idGearBoxTemp;
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.margins: 12
            nameScale: "Gear box temp";
            fLowLim: true; valMin: settings.engineGearBoxTempMin; valLowLim: settings.engineGearBoxTempLimMin;
            fHighLim: true; valMax: settings.engineGearBoxTempMax; valHighLim: settings.engineGearBoxTempLimMax;
            fIntVal: true
            valReal: report.engineGearBoxTemp
        }
    }
}
