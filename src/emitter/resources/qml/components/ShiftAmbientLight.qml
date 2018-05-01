import QtQuick 2.9
import ShiftRayReceptor 1.0

ShiftReceptor {
    id: rootReceptor

    isConnectedToBackend: ambientLightReceptor.connectedToBackend
    isReceptorListening: ambientLightReceptor.listening

    property string lightLevel: ""

    function lightLevelToString(lightLevel) {
        switch(lightLevel)
        {
        case 0: return "Undefined";
        case 1: return "Dark";
        case 2: return "Twilight";
        case 3: return "Light";
        case 4: return "Bright";
        case 5: return "Sunny";
        }
    }

    AmbientLightReceptor {
        id: ambientLightReceptor

        Component.onCompleted: {
            connectReceptor();
            startListening();
        }

        onLightLevelChanged: {
            rootReceptor.lightLevel = lightLevelToString(lightLevel)
        }
    }

    Text {
        id: lightLevelText
        width: parent.width
        height: 30
        anchors.centerIn: parent
        text: "Light Level: " + rootReceptor.lightLevel
        horizontalAlignment: Text.AlignHCenter
    }

}
