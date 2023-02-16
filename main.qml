import QtQuick.Window 2.0
import QtQuick 2.9
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Material 2.1

import "./components"
import "./settings/colors.js" as Color
import "./settings/Strings.js" as Str
import "./settings/logic.js" as Logic

ApplicationWindow {

    property double scaleKoef: minimumWidth/minimumHeight

    Material.theme: Material.Dark
    Material.accent: Color.GREEN_1

    visible: true
    width: 1490
    height: 834
    minimumWidth: 1490
    minimumHeight: 834
    title:  qsTr("ECAM - Alpin (v1.1.9)")
    color: Color.BLACK

    Component.onCompleted: {
        pb.openReportMsgView()

        x = Screen.width / 2 - width / 2
        y = Screen.height / 2 - height / 2
    }

    onClosing: pb.closeReportMsgView()

    ColumnLayout{
        id: idMainItem
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        width: (parent.width > parent.height*scaleKoef) ? parent.height*scaleKoef : parent.width
        height: (parent.width > parent.height*scaleKoef) ? parent.height : parent.width/scaleKoef
        spacing: 0

        IndicationPanel{
            id: indication
            Layout.fillWidth: true
            Layout.preferredHeight: 110
        }
        RowLayout{
            Layout.fillHeight: true
            Layout.fillWidth: true
            spacing: 0

            TcuPanel{
                id: tcu
                Layout.fillHeight: true
                Layout.fillWidth: true
                width: 120
            }
            RpmPanel{
                id: rpm
                Layout.fillHeight: true
                Layout.fillWidth: true
                width: 230

                onUpdateThrottle: pb.updateVariables(name, val);
                onUpdateValue: pb.updateVariables(name, val);
            }
            EgtPanel{
                id: egt
                Layout.fillHeight: true
                Layout.fillWidth: true
                width: 120
            }
            ControlsPanel {
                id: control
                Layout.fillHeight: true
                Layout.preferredWidth: 300
                onUpdateValue: pb.updateVariables(name, val);
            }
        }
        EnginePanel{
            id: engine
            Layout.fillHeight: true
            Layout.fillWidth: true
        }

    }
}
