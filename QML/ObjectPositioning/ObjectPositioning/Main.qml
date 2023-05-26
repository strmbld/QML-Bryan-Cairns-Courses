import QtQuick
import QtQuick.Window
import "qrc:///"

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    property real midX: width / 2
    property real midY: height / 2

    Column { // Row // Grid
        spacing: 2

        SomeShape {
            color: "red"

            x: midX - width / 2
            y: midY - height / 2 - 30
        }

        SomeShape {
            color: "green"

            x: midX - width / 2 + 55
            y: midY - height / 2 + 30
        }

        SomeShape {
            color: "blue"

            x: midX - width / 2 - 55
            y: midY - height / 2 + 30
        }
    }
}
