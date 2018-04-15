import QtQuick 2.9
import QtQuick.Controls 2.2

ShiftRayPage {

    headerText: qsTr("Found Sensors")

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
                id: wrapper

                width: gridView.cellWidth - 10
                height: width

                anchors.margins: 10

                gradient: Gradient {
                    GradientStop { position: 0.0; color: "#38ef7d" }
                    GradientStop { position: 0.5; color: "#11998e" }
                }

                Text {
                    anchors.centerIn: parent
                    font.pixelSize: 15
                    text: receptorType
                    color: "white"
                    font.italic: true
                }

                MouseArea {
                    anchors.fill: parent

                    onClicked: {
                        console.log('Got: ' , receptorType)
                    }
                }
            }
        }
    }
}
