import QtQuick
import QtQuick.Controls 6.2

Item {
    signal login(string username, string password)

    width: 300
    height: 200

//    Connections {
//        target: btnLogin
//        // onClicked: login(txtUsername.text, txtPassword.text)
//        function onClicked() {
//            login(txtUsername.text, txtPassword.text)
//        }
//    }

    Column {
        id: column
        anchors.fill: parent
        spacing: 10

        Label {
            id: lblUsername
            text: qsTr("Username")
        }

        TextField {
            id: txtUsername
            placeholderText: qsTr("Enter username")
            width: parent.width
        }

        Label {
            id: lblPassword
            text: qsTr("Password")
        }

        TextField {
            id: txtPassword
            width: parent.width
            placeholderText: qsTr("Enter password")
            echoMode: TextInput.Password
        }

        Button {
            id: btnLogin
            width: parent.width
            height: 30
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("Login")

            onClicked: {
                login(txtUsername.text, txtPassword.text)
            }
        }
    }

}
