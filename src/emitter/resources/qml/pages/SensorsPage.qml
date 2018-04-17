import QtQuick 2.9
import QtQuick.Controls 2.2

ShiftRayPage {

    headerText: qsTr("Found Sensors")
    signal loadReceptor(var receptorName, var receptorProps)

    Item {
        id: viewHolder
        width: parent.width - 20
        anchors {
            top: parent.top
            topMargin: 10
            bottom: parent.bottom
            horizontalCenter: parent.horizontalCenter
        }

        GridView {
            id: gridView
            anchors.fill: parent
            clip: true
            cellWidth: width / 2
            cellHeight: cellWidth

            model: receptorsModel
            delegate: numberDelegate
        }

        Component {
            id: numberDelegate

            Rectangle {
                id: sensorHolder
                width: gridView.cellWidth - 10
                height: width
                anchors.margins: 10
                radius: 10
                border.width: 3
                border.color: "#11998e"

                gradient: Gradient {
                    GradientStop { position: 0.0; color: "#38ef7d" }
                    GradientStop { position: 0.5; color: "#11998e" }
                }

                Image {
                    id: receptorImage
                    source: "qrc:/images/" + friendlyName + ".png"
                    anchors.centerIn: parent
                    fillMode: Image.PreserveAspectFit
                }

                Text {
                    anchors.top: receptorImage.bottom
                    anchors.topMargin: 10
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.pixelSize: 15
                    text: friendlyName
                    color: "white"
                    font.italic: true
                }

                MouseArea {
                    anchors.fill: parent
                    onPressed: {
                        parent.border.color = "white"
                    }
                    onReleased: {
                        parent.border.color = "#11998e"
                    }

                    onClicked: {
                        console.log('Got: ' , friendlyName)
                        navigateTo(1)
                        var receptorProps = {"receptorName": friendlyName, "receptorType": receptorType, "receptorIdentifier": receptorIdentifier};
                        loadReceptor(friendlyName, receptorProps)
                    }
                }
            }
        }
    }
}
