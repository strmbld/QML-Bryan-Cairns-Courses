import QtQuick
import QtQuick.Window
import QtQuick.Controls 6.2

import com.application.someclass 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    SomeClass {
        id: someClassObj
        onStatus: {
            lblStatus.text = data
        }
    }

    Column {
        id: column
        width: 101
        height: 88
        spacing: 10
        anchors.centerIn: parent

        Label {
            id: label
            text: qsTr("Register a C++ Class")
            anchors.horizontalCenter: parent.horizontalCenter
            font.bold: true
            font.pixelSize: 10
        }

        Label {
            id: lblStatus
            text: qsTr("Status")
            anchors.horizontalCenter: parent.horizontalCenter
            font.bold: true
            font.pixelSize: 25
        }

        Button {
            id: button
            text: qsTr("Button")

            onClicked: {
                someClassObj.doWork(Math.random() * 100)
            }
        }
    }
}
