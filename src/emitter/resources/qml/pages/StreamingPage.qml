import QtQuick 2.9
import QtQuick.Controls 2.2

ShiftRayPage {

    headerText: qsTr("Streaming Page")

    function loadReceptor(receptorName, receptorProps) {
        receptorLoader.setSource("../components/Shift" + receptorName + ".qml", receptorProps)
    }

    Loader {
        id: receptorLoader
        anchors.fill: parent
    }
}
