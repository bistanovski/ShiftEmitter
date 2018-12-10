import QtQuick 2.9
import QtQuick.Controls 2.2

ShiftRayPage {
    id: settingsPage
    headerText: qsTr("Settings Page")

    function saveDeviceToSettings() {
        ShiftSettings.telemetryHost = hostInput.text;
        ShiftSettings.telemetryPort = parseInt(portInput.text);
        ShiftSettings.deviceName = deviceNameInput.text;
        ShiftSettings.deviceType = deviceTypeInput.text;
    }

    function generateDetailsForRegister() {
        var registerDeviceData = {
            'user_name' : ShiftSettings.userName,
            'device_id' : ShiftSettings.deviceUUID,
            'name' : deviceNameInput.text,
            'type' : deviceTypeInput.text,
            'operating_system' : ShiftSettings.osName,
            'os_version' : ShiftSettings.osVersion,
            'number_of_sensors' : receptorsModel.length
        }

        var sensorsArray = [];
        for (var i = 0; i < receptorsModel.length; ++i) {
            var receptorInfoJson = receptorsModel[i].toJson();
            sensorsArray.push(
                        {
                          'sensor_name' : receptorInfoJson['sensor_name'],
                          'number_of_readings' : receptorInfoJson['number_of_readings'],
                          'sensor_readings' : receptorInfoJson['sensor_readings']
                        });
        }

        registerDeviceData['sensors'] = sensorsArray;
        return JSON.stringify(registerDeviceData);
    }

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
        anchors.topMargin: 10
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
        text: "Connected to Telemetry Broker: " + (MqttClient.isConnected ? "TRUE" : "FALSE")
    }

    Item {
        id: telemetryHostInput
        width: parent.width
        height: 50
        anchors.top: telemetryConnectionText.bottom
        anchors.topMargin: 5

        TextField {
            id: hostInput
            width: parent.width/2
            height: parent.height
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
            horizontalAlignment: TextField.AlignHCenter
            text: ShiftSettings.telemetryHost
            placeholderText: qsTr("MQTT Host")
        }
    }

    Item {
        id: telemetryPortInput
        width: parent.width
        height: 50
        anchors.top: telemetryHostInput.bottom
        anchors.topMargin: 5

        TextField {
            id: portInput
            width: parent.width/2
            height: parent.height
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
            horizontalAlignment: TextField.AlignHCenter
            text: ShiftSettings.telemetryPort
            placeholderText: qsTr("MQTT Port")
        }
    }

    Item {
        id: deviceNameHolder
        width: parent.width
        height: 50
        anchors.top: telemetryPortInput.bottom
        anchors.topMargin: 5

        TextField {
            id: deviceNameInput
            width: parent.width/2
            height: parent.height
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
            horizontalAlignment: TextField.AlignHCenter
            text: ShiftSettings.deviceName
            placeholderText: qsTr("Device name")
        }
    }

    Item {
        id: deviceTypeHolder
        width: parent.width
        height: 50
        anchors.top: deviceNameHolder.bottom
        anchors.topMargin: 5

        TextField {
            id: deviceTypeInput
            width: parent.width/2
            height: parent.height
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
            horizontalAlignment: TextField.AlignHCenter
            text: ShiftSettings.deviceType
            placeholderText: qsTr("Device type")
        }
    }

    Button {
        id: registerDeviceButton
        anchors.top: deviceTypeHolder.bottom
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
            if(ShiftSettings.isUserRegistered) {
                RestClient.registerDevice(generateDetailsForRegister());
            }
            else {
                console.log("User must be registered!");
            }
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
        id: icons8text
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

    Connections {
        target: RestClient
        onRegisterDeviceResponse: {
            if(succeed) {
                console.log("Succeed:", succeed);
                console.log("Data:", data);
            }
            else {
                console.log("ERROR:", data);
            }
        }
    }
}
