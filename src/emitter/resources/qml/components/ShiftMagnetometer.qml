import QtQuick 2.9
import ShiftRayReceptor 1.0

import "../elements"

ShiftReceptor {
    id: rootReceptor

    isConnectedToBackend: magnetoMeter.connectedToBackend
    isReceptorListening: magnetoMeter.listening

    property real xFluxValue: 0.0
    property real yFluxValue: 0.0
    property real zFluxValue: 0.0
    property real calibrationLevel: 0.0

    MagnetometerReceptor {
        id: magnetoMeter

        Component.onCompleted: {
            connectReceptor();
        }

        onMagneticFluxChanged: {
            rootReceptor.xFluxValue = xFlux
            rootReceptor.yFluxValue = yFlux
            rootReceptor.zFluxValue = zFlux
            rootReceptor.calibrationLevel = calibrationLevel
            AmqpClient.sendMagnetometerTelemetry(xFlux, yFlux, zFlux, calibrationLevel)
        }
    }

    Text {
        id: xFluxText
        width: parent.width
        height: 30
        anchors.centerIn: parent
        text: "X Flux: " + rootReceptor.xFluxValue
        horizontalAlignment: Text.AlignHCenter
    }

    Text {
        id: yFluxText
        width: parent.width
        height: 30
        anchors.top: xFluxText.bottom
        text: "Y Flux: " + rootReceptor.yFluxValue
        horizontalAlignment: Text.AlignHCenter
    }

    Text {
        id: zFluxText
        width: parent.width
        height: 30
        anchors.top: yFluxText.bottom
        text: "Z Flux: " + rootReceptor.zFluxValue
        horizontalAlignment: Text.AlignHCenter
    }

    Text {
        id: calibrationText
        width: parent.width
        height: 30
        anchors.top: zFluxText.bottom
        text: "Calibration: " + rootReceptor.calibrationLevel
        horizontalAlignment: Text.AlignHCenter
    }

    CheckableStreamButton {
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter

        receptorTarget: magnetoMeter
    }
}
