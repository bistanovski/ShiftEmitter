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
        text: "Device UUID: "
    }

    Text {
        id: uUIDValuetext
        anchors.top: deviceUUIDtext.bottom
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
        text: ShiftSettings.deviceUUID
    }

    Text {
        id: osNameText
        anchors.top: uUIDValuetext.bottom
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
        text: "OS Name: " + ShiftSettings.osName
    }

    Text {
        id: osVersionText
        anchors.top: osNameText.bottom
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
        text: "OS Version: " + ShiftSettings.osVersion
    }

    Text {
        id: telemetryConnectionText
        anchors.top: osVersionText.bottom
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
        text: "Connected to Telemetry Broker: " + (TelemetryTransporter.isConnected ? "TRUE" : "FALSE")
    }

    Item {
        id: telemetryHostInput
        width: parent.width
        height: 100
        anchors.top: telemetryConnectionText.bottom
        anchors.topMargin: 20

        TextField {
            id: hostInput
            width: parent.width/2
            height: parent.height/2 - 10
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
            horizontalAlignment: TextField.AlignHCenter
            text: ShiftSettings.telemetryHost
            placeholderText: qsTr("MQTT Host")
        }

        Button {
            id: saveTelemetryHost
            height: parent.height/2 - 10
            anchors.top: hostInput.bottom
            anchors.topMargin: 5
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("Save")

            onClicked: {
                ShiftSettings.telemetryHost = hostInput.text
            }
        }
    }

    Item {
        id: telemetryPortInput
        width: parent.width
        height: 100
        anchors.top: telemetryHostInput.bottom
        anchors.topMargin: 20

        TextField {
            id: portInput
            width: parent.width/2
            height: parent.height/2 - 10
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
            horizontalAlignment: TextField.AlignHCenter
            text: ShiftSettings.telemetryPort
            placeholderText: qsTr("MQTT Port")
        }

        Button {
            id: saveTelemetryPort
            height: parent.height/2 - 10
            anchors.top: portInput.bottom
            anchors.topMargin: 5
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("Save")

            onClicked: {
                ShiftSettings.telemetryPort = parseInt(portInput.text)
            }
        }
    }

    Button {
        id: registerDeviceButton
        anchors.top: telemetryPortInput.bottom
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter

        contentItem: Text {
            text: qsTr("Register Device")
            font: registerDeviceButton.font
            color: registerDeviceButton.down ? "white" : "#21beaa"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            elide: Text.ElideRight
        }

        onClicked: {
            RestApiClient.registerDevice("TestDevice@22")
        }
    }

    Text {
        id: initialText
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
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
