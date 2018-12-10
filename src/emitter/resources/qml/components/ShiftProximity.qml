import QtQuick 2.9
import ShiftRayReceptor 1.0

import "../elements"

ShiftReceptor {
    id: rootReceptor

    isConnectedToBackend: proximityReceptor.connectedToBackend
    isReceptorListening: proximityReceptor.listening

    property bool somethingClose: false

    ProximityReceptor {
        id: proximityReceptor

        Component.onCompleted: {
            connectReceptor();
        }

        onSomethingIsCloseChanged: {
            rootReceptor.somethingClose = close
            MqttClient.sendProximityTelemetry(close)
        }
    }

    Text {
        id: somethingCloseText
        width: parent.width
        height: 30
        anchors.centerIn: parent
        text: "Something is close: " + rootReceptor.somethingClose
        horizontalAlignment: Text.AlignHCenter
    }

    CheckableStreamButton {
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter

        receptorTarget: proximityReceptor
    }

}
