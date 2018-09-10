import QtQuick 2.9
import QtQuick.Controls 2.2

ShiftRayPage {
    id: rootPage
    headerText: qsTr("Registration Page")

    function saveUserToSettings() {
        ShiftSettings.isUserRegistered = true;
        ShiftSettings.userName = usernameInput.text;
        ShiftSettings.userEmail = emailInput.text;
        ShiftSettings.userFirstName = firstNameInput.text;
        ShiftSettings.userLastName = lastNameInput.text;
        ShiftSettings.userPassword = passwordInput.text;
    }

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
        id: firstNameInput
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
        anchors.top: firstNameInput.bottom
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
    }

    TextField {
        id: lastNameInput
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
        anchors.top: lastNameInput.bottom
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
        anchors.top: passwordInput.bottom
        anchors.topMargin: 5
        anchors.horizontalCenter: parent.horizontalCenter
        text: qsTr("Register User")

        onClicked: {
            var registerUserData = {
                'username' : usernameInput.text,
                'email' : emailInput.text,
                'password' : passwordInput.text,
                'first_name' : firstNameInput.text,
                'last_name' : lastNameInput.text
            }

            RestClient.registerUser(JSON.stringify(registerUserData));
        }
    }

    Connections {
        target: RestClient
        onRegisterUserResponse : {
            if(succeed) {
                console.log("Success:", data);
                rootPage.saveUserToSettings();
            }
            else {
                console.log("Error!");
            }
        }
    }
}
