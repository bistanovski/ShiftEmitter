import QtQuick 2.9
import QtQuick.Controls 2.2

Page {
    property string headerText: ""

    header: Rectangle {
        id: pageHeader
        height: 20
        color: "lightgrey"
        opacity: 0.5

        Text {
            anchors.centerIn: parent
            text: headerText
            color: "red"
            opacity: 0.8
        }
    }
}
