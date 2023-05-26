import QtQuick
import QtQuick.Window

import "qrc:///"


Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Custom Button")

    Column {
        id: column
        x: 196
        y: 65
        width: 105
        height: 231
        spacing: 25
        anchors.centerIn: parent

        CustomButton {
            id: customButton
            width: 100
            height: 100
            source: "qrc:/images/up.png"

            onClicked: {
                console.log("Up clicked")
            }
        }

        CustomButton {
            id: customButton1
            width: 100
            height: 100
            source: "qrc:/images/down.png"

            onClicked: {
                console.log("Down clicked")
            }
        }
    }
}
