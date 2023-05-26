import QtQuick
import QtQuick.Window

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    property string theKey: "glue"
    property color goalOn: "green"
    property color goalOff: "red"
    property color ballOn: "yellow"
    property color ballOff: "orange"
    property color borderColor: "black"

    DropArea {
        id: dropArea
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        width: 300
        Drag.keys: [theKey]
        onDropped: {
            goal.color = goalOn
        }

        Rectangle {
            id: goal
            anchors.fill: parent
            color: goalOff
            border.color: borderColor
            border.width: 5
        }
    }

    Rectangle {
        id: ball
        width: 100
        height: 100
        radius: width
        x: 25
        y: parent.height / 2 - height / 2
        color: ballOff
        border.color: borderColor
        border.width: 5

        Text {
            id: ballTxt
            anchors.centerIn: parent
            text: Math.round(parent.x) + " x " + Math.round(parent.y)
        }

        Drag.active: dragArea.drag.active
        Drag.keys: [theKey]

        MouseArea {
            id: dragArea
            anchors.fill: parent
            drag.target: ball
            onPressed: { parent.color = ballOn; goal.color = goalOff }
            onReleased: { parent.color = ballOff; parent.Drag.drop() }
        }
    }
}
