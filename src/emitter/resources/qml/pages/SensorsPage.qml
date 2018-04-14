import QtQuick 2.9
import QtQuick.Controls 2.2

ShiftRayPage {

    headerText: qsTr("Found Sensors")

    ListView {
        id: sensorList
        width: parent.width
        height: parent.height
        clip: true
        model: foundTypes
        delegate: ItemDelegate {
            text: modelData
            width: parent.width
        }
    }
}
