import QtQuick 2.9
import ShiftRayReceptor 1.0

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
            startListening();
        }

        onTiltDetected: {
            rootReceptor.xRotationValue = xRotation
            rootReceptor.yRotationValue = yRotation
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
}
