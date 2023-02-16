import QtQuick 2.0
import QtQuick.Layouts 1.0

import "./components"


ItemFrame{

    nameGroup: 'EGT'

    RowLayout{
        anchors.centerIn: parent
        height: parent.height - 25
        spacing: 2

        LineScale{
            id: idEGT1
            Layout.fillHeight: true
            Layout.fillWidth: true
            nameScale: "1"
            fTickVisible: true
            fLowLim: false
            fHighLim: true
            valLowLim: settings.egtLimMin; valHighLim: settings.egtLimMax
            valMin: settings.egtMin; valMax: settings.egtMax
            stepTick: 100
            fIntVal: true
            valReal: report.egt1.toFixed(1)
        }
        LineScale{
            id: idEGT2
            Layout.fillHeight: true
            Layout.fillWidth: true
            nameScale: "2"
            fTickVisible: false
            fLowLim: false
            fHighLim: true
            valLowLim: settings.egtLimMin; valHighLim: settings.egtLimMax
            valMin: settings.egtMin; valMax: settings.egtMax
            stepTick: 100
            fIntVal: true
            valReal: report.egt2.toFixed(1)
        }
        LineScale{
            id: idEGT3
            Layout.fillHeight: true
            Layout.fillWidth: true
            nameScale: "3"
            fTickVisible: false
            fLowLim: false
            fHighLim: true
            valLowLim: settings.egtLimMin; valHighLim: settings.egtLimMax
            valMin: settings.egtMin; valMax: settings.egtMax
            stepTick: 100
            fIntVal: true
            valReal: report.egt3.toFixed(1)
        }
        LineScale{
            id: idEGT4
            Layout.fillHeight: true
            Layout.fillWidth: true
            nameScale: "4"
            fTickVisible: false
            fLowLim: false
            fHighLim: true
            valLowLim: settings.egtLimMin; valHighLim: settings.egtLimMax
            valMin: settings.egtMin; valMax: settings.egtMax
            stepTick: 100
            fIntVal: true
            valReal: report.egt4.toFixed(1)
        }
    }
}
