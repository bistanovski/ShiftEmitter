import QtQuick 2.9
import QtQuick.Controls 2.2

ShiftRayPage {
    id: rootPage
    headerText: qsTr("Registration Page")

    Text {
        id: usernameLabel
        text: qsTr("Username:")
        anchors.top: parent.top
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
    }

    TextField {
        id: usernameInput
        width: parent.width/2
        height: 50
        anchors.top: usernameLabel.bottom
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
        horizontalAlignment: TextField.AlignHCenter
        placeholderText: qsTr("Username")
        text: ShiftSettings.userName
    }

    Text {
        id: emailLabel
        text: qsTr("Email:")
        anchors.top: usernameInput.bottom
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
    }

    TextField {
        id: emailInput
        width: parent.width/2
        height: 50
        anchors.top: emailLabel.bottom
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
        horizontalAlignment: TextField.AlignHCenter
        placeholderText: qsTr("Email")
        text: ShiftSettings.userEmail
    }

    Text {
        id: fNameLabel
        text: qsTr("First name:")
        anchors.top: emailInput.bottom
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
    }

    TextField {
        id: fNameInput
        width: parent.width/2
        height: 50
        anchors.top: fNameLabel.bottom
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
        horizontalAlignment: TextField.AlignHCenter
        placeholderText: qsTr("First name")
        text: ShiftSettings.userFirstName
    }

    Text {
        id: lNameLabel
        text: qsTr("Last name:")
        anchors.top: fNameInput.bottom
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
    }

    TextField {
        id: lNameInput
        width: parent.width/2
        height: 50
        anchors.top: lNameLabel.bottom
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
        horizontalAlignment: TextField.AlignHCenter
        placeholderText: qsTr("Last name")
        text: ShiftSettings.userLastName
    }

    Text {
        id: passwordLabel
        text: qsTr("Password:")
        anchors.top: lNameInput.bottom
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
    }

    TextField {
        id: passwordInput
        width: parent.width/2
        height: 50
        anchors.top: passwordLabel.bottom
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
        horizontalAlignment: TextField.AlignHCenter
        echoMode: TextInput.Password
        placeholderText: qsTr("Password")
        text: ShiftSettings.userPassword
    }

    Button {
        id: registrationButton
        height: 50
        width: 100
        anchors.top: passwordInput.bottom
        anchors.topMargin: 5
        anchors.horizontalCenter: parent.horizontalCenter
        text: qsTr("Register")

        onClicked: {
            ShiftSettings.userName = usernameInput.text
            ShiftSettings.userEmail = emailInput.text
            ShiftSettings.userFirstName = fNameInput.text
            ShiftSettings.userLastName = lNameInput.text
            ShiftSettings.userPassword = passwordInput.text
        }
    }
}
