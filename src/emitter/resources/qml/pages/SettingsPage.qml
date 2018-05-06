import QtQuick 2.9
import QtQuick.Controls 2.2

ShiftRayPage {

    headerText: qsTr("Settings Page")

    CheckBox {
        id: simulatorCheckbox
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 100
        text: qsTr("Simulator enabled")

        onCheckedChanged: {
            ShiftSettings.usingSimulator = checked
        }

        Component.onCompleted: {
            checked = ShiftSettings.usingSimulator
        }
    }

    Text {
        id: deviceUUIDtext
        anchors.top: simulatorCheckbox.bottom
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
        text: "Device UUID: " + ShiftSettings.deviceUUID
    }

    Text {
        id: initialText
        anchors.centerIn: parent
        text: "App icon by "
    }
    Text {
        anchors.left: initialText.right
        anchors.top: initialText.top
        text: "icons8"
        font.italic: true
        font.underline: true

        MouseArea {
            anchors.fill: parent
            cursorShape: Qt.PointingHandCursor
            onClicked: {
                Qt.openUrlExternally("https://icons8.com");
            }
        }
    }
}
