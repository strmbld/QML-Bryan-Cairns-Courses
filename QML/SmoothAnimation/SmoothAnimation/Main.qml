import QtQuick
import QtQuick.Window

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        anchors.fill: parent
        color: "black"
        focus: true

        Rectangle {
            id: chaser
            width: 60
            height: 60
            radius: width
            color: "yellow"

            Behavior on x { SmoothedAnimation { velocity: 100 } }
            Behavior on y { SmoothedAnimation { velocity: 100 } }

            x: player.x - 5
            y: player.y - 5
        }

        Rectangle {
            id: player
            width: 50
            height: 50
            radius: width
            color: "red"
            x: parent.width / 2 - width / 2
            y: parent.height / 2 - height / 2
        }

        Keys.onRightPressed: player.x += 100
        Keys.onLeftPressed: player.x -= 100
        Keys.onUpPressed: player.y -= 100
        Keys.onDownPressed: player.y += 100
    }
}
