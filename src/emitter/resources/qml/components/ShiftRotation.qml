import QtQuick 2.9
import QtQuick.Controls 2.2
import ShiftRayReceptor 1.0

import "../elements"

ShiftReceptor {
    id: rootReceptor

    isConnectedToBackend: rotation.connectedToBackend
    isReceptorListening: rotation.listening

    property real xValue: 0.0
    property real yValue: 0.0
    property real zValue: 0.0

    RotationReceptor {
        id: rotation

        Component.onCompleted: {
            connectReceptor();
        }

        onRotationChanged: {
            rootReceptor.xValue = xValue
            rootReceptor.yValue = yValue
            rootReceptor.zValue = zValue

            TelemetryTransporter.sendRotationTelemetry(xValue, yValue, zValue);
        }
    }

    Text {
        id: xValueText
        width: parent.width
        height: 30
        anchors.centerIn: parent
        text: "X: " + rootReceptor.xValue
        horizontalAlignment: Text.AlignHCenter
    }

    Text {
        id: yValueText
        width: parent.width
        height: 30
        anchors.top: xValueText.bottom
        text: "Y: " + rootReceptor.yValue
        horizontalAlignment: Text.AlignHCenter
    }

    Text {
        id: zValueText
        width: parent.width
        height: 30
        anchors.top: yValueText.bottom
        text: "Z: " + rootReceptor.zValue
        horizontalAlignment: Text.AlignHCenter
    }

    CheckableStreamButton {
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter

        receptorTarget: rotation
    }

}
