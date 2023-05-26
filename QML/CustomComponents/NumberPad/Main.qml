import QtQuick
import QtQuick.Window
import QtQuick.Controls 6.2

import "qrc:///"


Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Column {
        id: column
        width: 252
        height: 300
        anchors.verticalCenter: parent.verticalCenter
        spacing: 15
        anchors.horizontalCenter: parent.horizontalCenter

        Label {
            id: lblStatus
            text: qsTr("Status")
            font.bold: true
            font.pointSize: 16
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Connections {
            target: numberPad

            function onClicked(value) {
                lblStatus.text = value
            }
        }

        NumberPad {
            id: numberPad
            width: 100
            height: 100
            anchors.horizontalCenter: parent.horizontalCenter

            // deprecated params passing
//            onClicked: {
//                lblStatus.text = value
//            }
        }
    }
}
