import QtQuick 2.9
import ShiftRayReceptor 1.0

ShiftReceptor {
    id: rootReceptor

    isConnectedToBackend: lightReceptor.connectedToBackend
    isReceptorListening: lightReceptor.listening

    property real luxValue: 0.0

    LightReceptor {
        id: lightReceptor

        Component.onCompleted: {
            connectReceptor();
            startListening();
        }

        onLightReadingChanged: {
            rootReceptor.luxValue = luxValue
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
}
