import QtQuick
import QtQuick.Window
import QtQuick.Controls 6.2

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Connections {
        target: externalCppClass

        // deprecated
//        onNotice: {
//            console.log("Called Qml slot by signal from Cpp")
//            lblStatus.text = data // arg of SomeClass.notice(data)
//        }

        function onNotice(data) {
            console.log("Called Qml slot by signal from Cpp")
            lblStatus.text = data // arg of SomeClass.notice(data)
        }
    }

    Column {
        id: column
        width: 228
        height: 159
        anchors.centerIn: parent

        Label {
            id: lblTitle
            text: qsTr("Connect to Signals")
            font.pointSize: 10
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Label {
            id: lblStatus
            text: qsTr("Status")
            font.pointSize: 25
            font.bold: true
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Row {
            id: row
            width: 200
            height: 400
            spacing: 25

            Button {
                id: button
                text: qsTr("Start")

                onClicked: externalCppClass.start()
            }

            Button {
                id: button1
                text: qsTr("Stop")

                onClicked: externalCppClass.stop()
            }
        }
    }
}
