import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 480
    height: 640
    minimumWidth: width
    minimumHeight: height
    maximumWidth: width
    maximumHeight: height
    title: qsTr("ShiftRay Emitter")

    header: MainTabBar {
        id: mainTabBar
        currentIndex: mainSwipeView.currentIndex
    }

    function showInfoMessage(message) {
        messageText.text = message
        messageBox.backgroundItem.color = "#15a56b"
        messageBox.open();
    }

    function showErrorMessage(message) {
        messageText.text = message
        messageBox.backgroundItem.color = "#ce3939"
        messageBox.open();
    }

    Popup {
        id: messageBox
        width: parent.width - 20
        height: 50
        x: Math.round((parent.width - width) / 2)
        y: Math.round((parent.height - height) - 20)
        modal: false
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside

        property alias backgroundItem: backgroundItem

        background: Rectangle {
            id: backgroundItem
            color: "#16a58b"
        }

        Text {
            id: messageText
            anchors.fill: parent
            wrapMode: Text.WordWrap
            anchors.centerIn: parent
            color: "white"
        }
    }

    MainSwipeView {
        id: mainSwipeView
        currentIndex: mainTabBar.currentIndex
    }
}
