import QtQuick
import QtQuick.Window

Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        id: mRect1
        color: "red"
        width: 100
        height: 100
        x: 0
        y: 0
        z: 1

        PropertyAnimation {
            id: animRight
            target: mRect1
            property: "x"
            to: root.width - mRect1.width
            duration: 1000
        }

        PropertyAnimation {
            id: animLeft
            target: mRect1
            property: "x"
            to: 0
            duration: 1000
        }

        MouseArea {
            anchors.fill: parent
            drag.target: parent
            onClicked: {
                mRect1.x === 0
                        ? animRight.start()
                        : animLeft.start()
            }
        }
    }

    Rectangle {
        id: mRect2
        color: "blue"
        width: 100
        height: 100
        x: parent.width - mRect2.width
        y: mRect2.height
        z: 0

        Text {
            id: mRect2Txt
            text: Math.round(parent.rotation)
            anchors.centerIn: parent
            font.bold: true
            font.pointSize: 24
        }

        RotationAnimation {
            id: animRotation
            target: mRect2
            loops: Animation.Infinite
            from: mRect2.rotation
            to: 360
            direction: RotationAnimation.Clockwise
            duration: 3000
            running: true
        }

        MouseArea {
            id: mRect2MouseArea
            anchors.fill: parent
            onClicked: {
                animRotation.paused
                        ? animRotation.resume()
                        : animRotation.pause()
            }
        }
    }

    Rectangle {
        id: mRect3
        color: "green"
        width: 100
        height: 100
        x: mRect3.width
        y: parent.height - mRect3.height * 2
        z: 0
        clip: true

        Text {
            id: mRect3Txt
            text: qsTr("SCALE")
            font.bold: true
            font.pointSize: 36
            rotation:  -45
            anchors.centerIn: parent
        }

        SequentialAnimation {
            id: animSeq1
            running: true
            loops: Animation.Infinite

            ScaleAnimator {
                id: animShrink
                target: mRect3
                from: 1
                to: 0.5
                duration: 3000
            }

            ScaleAnimator {
                id: animGrow
                target: mRect3
                from: 0.5
                to: 1
                duration: 3000
            }
        }
    }

    Image {
        id: img1
        source: "qrc:/images/image.png"
        opacity: 0
        scale: 0.33
        x: parent.width - img1.width
        y: parent.height - 500

        SequentialAnimation {
            id: animSeq2
            running: true
            loops: Animation.Infinite

            OpacityAnimator {
                id: animIn
                target: img1
                from: 0
                to: 1
                duration: 1500
            }

            OpacityAnimator {
                id: animOut
                target: img1
                from: 1
                to: 0
                duration: 2500
            }
        }
    }
}
