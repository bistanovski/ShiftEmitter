import QtQuick 2.9
import QtQuick.Controls 2.2

ShiftRayPage {
    id: rootPage
    headerText: qsTr("Streaming Page")

    function loadReceptor(receptorName, receptorProps) {
        rootPage.headerText = receptorName
        receptorLoader.setSource("../components/Shift" + receptorName + ".qml", receptorProps)
    }

    Loader {
        id: receptorLoader
        anchors.fill: parent
    }
}
