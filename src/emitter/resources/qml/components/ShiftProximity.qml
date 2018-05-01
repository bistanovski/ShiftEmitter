import QtQuick 2.9
import ShiftRayReceptor 1.0

ShiftReceptor {
    id: rootReceptor

    isConnectedToBackend: proximityReceptor.connectedToBackend
    isReceptorListening: proximityReceptor.listening

    property bool somethingClose: false

    ProximityReceptor {
        id: proximityReceptor

        Component.onCompleted: {
            connectReceptor();
            startListening();
        }

        onSomethingIsCloseChanged: {
            rootReceptor.somethingClose = close
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

}
