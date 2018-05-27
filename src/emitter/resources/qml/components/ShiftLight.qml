import QtQuick 2.9
import ShiftRayReceptor 1.0

import "../elements"

ShiftReceptor {
    id: rootReceptor

    isConnectedToBackend: lightReceptor.connectedToBackend
    isReceptorListening: lightReceptor.listening

    property real luxValue: 0.0

    LightReceptor {
        id: lightReceptor

        Component.onCompleted: {
            connectReceptor();
        }

        onLightReadingChanged: {
            rootReceptor.luxValue = luxValue
            TelemetryTransporter.sendLightTelemetry(luxValue)
        }
    }

    Text {
        id: luxLevelText
        width: parent.width
        height: 30
        anchors.centerIn: parent
        text: "Lux Value: " + rootReceptor.luxValue
        horizontalAlignment: Text.AlignHCenter
    }

    CheckableStreamButton {
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter

        receptorTarget: lightReceptor
    }
}
