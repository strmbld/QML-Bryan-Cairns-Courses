import QtQuick
import QtQuick.Window

import "qrc:/app.js" as JSCode


Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("JS and signals/slots")

    Component.onCompleted: {
        JSCode.startup(root, box)
        mouseArea.clicked.connect(JSCode.clicked)
    }

    Rectangle {
        id: box
        color: JSCode.swapColor(mouseArea)
        width: 100
        height: 100
        x: 0
        y: parent.height / 2 - height / 2

        MouseArea {
            id: mouseArea
            anchors.fill: parent

            // onClicked: JSCode.performClick()
        }
    }
}
