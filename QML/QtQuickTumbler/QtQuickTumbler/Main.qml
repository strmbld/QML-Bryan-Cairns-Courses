import QtQuick
import QtQuick.Window
import QtQuick.Controls 6.2

Window {
    width: 320
    height: 400
    visible: true
    title: qsTr("Hello World")

    Popup {
        id: statusPopup
        closePolicy: Popup.CloseOnEscape
        width: 200
        height: 300
        modal: true
        focus: true
        anchors.centerIn: parent

        onClosed: {
            if(column.currentStatus == "Unlocked") {
                column.currentStatus = "Locked"
                tumbler.currentIndex = 0;
                tumbler1.currentIndex = 0;
                tumbler2.currentIndex = 0;
            }
        }

        Label {
            id: txtStatusPopup
            anchors.centerIn: parent
            text: column.currentStatus
            font.bold: true
        }
    }

    Column {
        id: column
        x: 220
        y: 27
        spacing: 3
        anchors.centerIn: parent

        property string secret: "420"
        property string currentStatus: "Locked"

        Label {
            id: label
            width: 60
            text: tumbler.currentIndex + " " + tumbler1.currentIndex + " " + tumbler2.currentIndex
            anchors.left: parent.left
            anchors.right: parent.right
            horizontalAlignment: Text.AlignHCenter
            font.pointSize: 16
        }

        Row {
            id: row
            width: 200
            height: 250
            spacing: 3

            Tumbler {
                id: tumbler
                model: 10

                currentIndex: 0
            }

            Tumbler {
                id: tumbler1
                model: 10

                currentIndex: 0
            }

            Tumbler {
                id: tumbler2
                model: 10

                currentIndex: 0
            }
        }

        Button {
            id: button
            text: qsTr("Try")
            anchors.left: parent.left
            anchors.right: parent.right
            font.pointSize: 14

            onClicked: {
                let temp = tumbler.currentIndex + "" + tumbler1.currentIndex + "" + tumbler2.currentIndex
                if(temp == column.secret) column.currentStatus = "Unlocked"
                statusPopup.open()
            }
        }
    }
}
