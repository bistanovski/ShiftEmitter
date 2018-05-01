import QtQuick 2.9
import ShiftRayReceptor 1.0

ShiftReceptor {
    id: rootReceptor

    isConnectedToBackend: compassReceptor.connectedToBackend
    isReceptorListening: compassReceptor.listening

    property real azimuthValue: 0.0
    property real calibrationLevelValue: 0.0

    CompassReceptor {
        id: compassReceptor

        Component.onCompleted: {
            connectReceptor();
            startListening();
        }

        onCompassReadingChanged: {
            rootReceptor.azimuthValue = azimuth
            rootReceptor.calibrationLevelValue = calibrationLevel
        }
    }

    Text {
        id: azimuthText
        width: parent.width
        height: 30
        anchors.centerIn: parent
        text: "Azimuth: " + rootReceptor.azimuthValue
        horizontalAlignment: Text.AlignHCenter
    }

    Text {
        id: calibrationLevelText
        width: parent.width
        height: 30
        anchors.top: azimuthText.bottom
        text: "Calibration Level: " + rootReceptor.calibrationLevelValue
        horizontalAlignment: Text.AlignHCenter
    }
}
