import QtQuick
import QtQuick.Window
import QtQuick.Controls 6.2

import "qrc:///"

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Connections {
        target: loginScreen

        function onLogin(username, password) {
            lblLoginStatus.text = username + " " + password

            loginPopup.open()
        }
    }

    Popup {
        id: loginPopup
        anchors.centerIn: parent
        modal: true
        focus: true
        closePolicy: Popup.CloseOnEscape

        Label {
            id: lblLoginStatus
            anchors.centerIn: parent
            text: ""
        }
    }

    LoginScreen {
        id: loginScreen
        anchors.centerIn: parent
//        onLogin: {
//            lblLoginStatus.text = username + " " + password

//            loginPopup.open()
//        }
    }
}
