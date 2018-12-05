import QtQuick 2.9
import ShiftRayReceptor 1.0

import "../elements"

ShiftReceptor {
    id: rootReceptor

    isConnectedToBackend: tiltReceptor.connectedToBackend
    isReceptorListening: tiltReceptor.listening

    property real xRotationValue: 0.0
    property real yRotationValue: 0.0

    TiltReceptor {
        id: tiltReceptor

        Component.onCompleted: {
            connectReceptor();
        }

        onTiltDetected: {
            rootReceptor.xRotationValue = xRotation
            rootReceptor.yRotationValue = yRotation
            AmqpClient.sendTiltTelemetry(xRotation, yRotation)
        }
    }

    Text {
        id: xRotationText
        width: parent.width
        height: 30
        anchors.centerIn: parent
        text: "X Rotation: " + rootReceptor.xRotationValue
        horizontalAlignment: Text.AlignHCenter
    }

    Text {
        id: yRotationText
        width: parent.width
        height: 30
        anchors.top: xRotationText.bottom
        text: "Y Rotation: " + rootReceptor.yRotationValue
        horizontalAlignment: Text.AlignHCenter
    }

    CheckableStreamButton {
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter

        receptorTarget: tiltReceptor
    }
}
