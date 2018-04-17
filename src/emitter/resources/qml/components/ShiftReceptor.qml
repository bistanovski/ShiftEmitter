import QtQuick 2.9
import ShiftRayReceptor 1.0

Item {

    id: rootItem
    anchors.fill: parent

    property string receptorName: ""
    property string receptorType: ""
    property string receptorIdentifier: ""

    property string readingText: ""

    Text {
        text: rootItem.receptorName
        anchors.top: parent.top
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Text {
        anchors.centerIn: parent
        text: rootItem.readingText
    }
}
