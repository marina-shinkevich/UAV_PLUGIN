import QtQuick 2.9
import QtQuick.Controls 2.12

import "../settings/colors.js" as Color

Item {

    property string backGroundColor: Color.BLACK_1

    property string name1: "1"
    property string name2: "2"
    property string name3: "3"
    property string name4: "4"

    property double valReal1: 10
    property double valReal2: 10
    property double valReal3: 10
    property double valReal4: 10

    property double valGroupMin: 0
    property double valGroupMax: 1200

    property double valGroupLowLim: 10
    property double valGroupHighLim: 100

    property bool fGroupLowLim: false
    property bool fGroupHighLim: true

    property double valGroupStepTick: 200

//    function update(_val1, _val2, _val3, _val4){
//        valReal1 = _val1
//        valReal2 = _val2
//        valReal3 = _val3
//        valReal4 = _val4
//        idLineScale1.update(valReal1)
//        idLineScale2.update(valReal2)
//        idLineScale3.update(valReal3)
//        idLineScale4.update(valReal4)
//    }

    height: 250
    width: idRowLinearScale.width

    Row{
        id: idRowLinearScale
        height: parent.height
        anchors.centerIn: parent
        anchors.horizontalCenterOffset: 10
        spacing: 0

        LineScale{
            id: idLineScale1
            height: parent.height
            nameScale: name1
            fTickVisible: true
            fLowLim: fGroupLowLim
            fHighLim: fGroupHighLim
            valLowLim: valGroupLowLim
            valHighLim: valGroupHighLim
            valMin: valGroupMin
            valMax: valGroupMax
            stepTick: valGroupStepTick
            valReal: valReal1
        }
        LineScale{
            id: idLineScale2
            height: parent.height
            nameScale: name2
            fTickVisible: false
            fLowLim: fGroupLowLim
            fHighLim: fGroupHighLim
            valLowLim: valGroupLowLim
            valHighLim: valGroupHighLim
            valMin: valGroupMin
            valMax: valGroupMax
            stepTick: valGroupStepTick
            valReal: valReal2
        }
        LineScale{
            id: idLineScale3
            height: parent.height
            nameScale: name3
            fTickVisible: false
            fLowLim: fGroupLowLim
            fHighLim: fGroupHighLim
            valLowLim: valGroupLowLim
            valHighLim: valGroupHighLim
            valMin: valGroupMin
            valMax: valGroupMax
            stepTick: valGroupStepTick
            valReal: valReal3
        }
        LineScale{
            id: idLineScale4
            height: parent.height
            nameScale: name4
            fTickVisible: false
            fLowLim: fGroupLowLim
            fHighLim: fGroupHighLim
            valLowLim: valGroupLowLim
            valHighLim: valGroupHighLim
            valMin: valGroupMin
            valMax: valGroupMax
            stepTick: valGroupStepTick
            valReal: valReal4
        }
    }


}
