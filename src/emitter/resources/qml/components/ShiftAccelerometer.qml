import QtQuick 2.9
import ShiftRayReceptor 1.0

ShiftReceptor {
    id: rootReceptor

    isConnectedToBackend: accelerometer.connectedToBackend
    isReceptorListening: accelerometer.listening

    property real xValue: 0.0
    property real yValue: 0.0
    property real zValue: 0.0

    AccelerometerReceptor {
        id: accelerometer

        Component.onCompleted: {
            connectReceptor();
            startListening();
        }

        onAccelerationChanged: {
            rootReceptor.xValue = xValue
            rootReceptor.yValue = yValue
            rootReceptor.zValue = zValue
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
}
