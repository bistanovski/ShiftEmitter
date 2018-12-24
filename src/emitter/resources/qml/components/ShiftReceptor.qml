import QtQuick 2.9
import ShiftRayReceptor 1.0

Item {

    id: rootItem
    anchors.fill: parent

    //Values for these properties are provided from Loader's props initialization
    property string receptorName: ""
    property string receptorType: ""
    property string receptorIdentifier: ""

    property bool isConnectedToBackend: false
    property bool isReceptorListening: false

    Text {
        id: connectedText
        text: "Connected to backend: " + rootItem.isConnectedToBackend
        anchors.top: parent.top
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Text {
        id: listeningText
        text: "Receptor listening: " + rootItem.isReceptorListening
        anchors.top: connectedText.bottom
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
    }
}
