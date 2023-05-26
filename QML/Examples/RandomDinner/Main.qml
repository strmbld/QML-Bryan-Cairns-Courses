import QtQuick
import QtQuick.Window
import QtQuick.Controls 6.2


Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Random Dinner")

    property variant places: ["Italian", "Mexican", "Asian", "American"]

    function pick() {
        let i = Math.floor(Math.random() * places.length)
        lblPlace.text = places[i]
        animSelection.start()
    }

    MouseArea {
        id: area
        anchors.fill: parent

        onClicked: {
            animStart.stop()
            animFadeOut.stop()

            lblPlace.font.pixelSize = 45
            lblPlace.opacity = 0
            lblPlace.rotation = 0.0

            animFadeOut.start()
        }

        Label {
            id: lblPlace
            anchors.centerIn: parent
            font.bold: true
            font.pixelSize: 25
            text: "Tap"
        }
    }

    SequentialAnimation {
        id: animStart
        running: true
        loops: Animation.Infinite

        NumberAnimation {
            target: lblPlace
            property: "font.pixelSize"
            to: 45
            duration: 1000
        }
        NumberAnimation {
            target: lblPlace
            property: "font.pixelSize"
            to: 25
            duration: 1000
        }
    }

    OpacityAnimator {
        id: animFadeOut
        running: false
        target: lblPlace
        from: 1
        to: 0
        duration: 1000

        onFinished: {
            pick()
        }
    }

    ParallelAnimation {
        id: animSelection
        running: false

        NumberAnimation {
            target: lblPlace
            property: "font.pixelSize"
            from: 0
            to: 45
            duration: 2000
        }

        OpacityAnimator {
            target: lblPlace
            from: 0
            to: 1
            duration: 2000
        }

        RotationAnimation {
            target: lblPlace
            from: 0
            to: 1
            duration: 2000
            direction: RotationAnimation.Counterclockwise
        }
    }
}
