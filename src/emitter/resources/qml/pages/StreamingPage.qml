import QtQuick 2.9
import QtQuick.Controls 2.2

ShiftRayPage {

    headerText: qsTr("Found Identifiers: " + foundSensors)

    ListView {
        id: identifers
        width: parent.width
        height: parent.height
        clip: true
        model: foundIdentifiers
        delegate: ItemDelegate {
            text: modelData
            width: parent.width
        }
    }
}
