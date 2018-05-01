import QtQuick 2.9
import ShiftRayReceptor 1.0

ShiftReceptor {
    id: rootReceptor

    isConnectedToBackend: orientationReceptor.connectedToBackend
    isReceptorListening: orientationReceptor.listening

    property string orientation: ""

    function orientationToString(orientationType) {
        switch(orientationType)
        {
        case 0: return "Undefined";
        case 1: return "Top Up";
        case 2: return "Top Down";
        case 3: return "Left Up";
        case 4: return "Right Up";
        case 5: return "Face Up";
        case 6: return "Face Down";
        }
    }

    OrientationReceptor {
        id: orientationReceptor

        Component.onCompleted: {
            connectReceptor();
            startListening();
        }

        onOrientationChanged: {
            rootReceptor.orientation = orientationToString(orientation)
        }
    }

    Text {
        id: orientationText
        width: parent.width
        height: 30
        anchors.centerIn: parent
        text: "Orientation: " + rootReceptor.orientation
        horizontalAlignment: Text.AlignHCenter
    }

}
