import QtQuick 2.9
import QtQuick.Controls 2.2

Button {

    property var receptorTarget: null

    id: registerDeviceButton

    property bool isChecked: false

    contentItem: Text {
        text: parent.isChecked ? qsTr("Stop listening") : qsTr("Start listening")
        font: registerDeviceButton.font
        color: registerDeviceButton.down ? "white" : "#21beaa"
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
    }

    onClicked: {
        isChecked = !isChecked
        if(isChecked){
            receptorTarget.startListening();
        }
        else{
            receptorTarget.stopListening();
        }
    }
}
