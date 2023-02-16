import QtQuick 2.0
import "./components"


ItemFrame{

    nameGroup: 'TCU'

    RoundScaleSmall{
        id: idTCUMap
        height: parent.height * 0.9
        anchors{centerIn: parent; horizontalCenterOffset: -15}
        nameScale: "MAP"
        fLowLim: false; valLowLim: settings.tcuMapLimMin; valMin: settings.tcuMapMin;
        fHighLim: true; valHighLim: settings.tcuMapLimMax; valMax: settings.tcuMapMax;
        valReal: report.tcuMap.toFixed(1)
    }

}
