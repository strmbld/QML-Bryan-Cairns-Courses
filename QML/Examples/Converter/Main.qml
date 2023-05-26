import QtQuick
import QtQuick.Window
import QtQuick.Controls 6.2

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    function inches_to_feet(val) {
        return val / 12
    }

    function feet_to_inches(val) {
        return val * 12
    }

    function convert() {
        let value = txtFrom.text
        let ret = 0

        switch(cmbType.currentIndex) {
        case 0:
            ret = inches_to_feet(value)
            break;
        case 1:
            ret = feet_to_inches(value)
            break;
        }

        lblResult.text = ret
    }

    Column {
        id: column
        width: 200
        height: 400
        spacing: 10
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter

        Grid {
            id: grid
            width: 400
            height: 150
            spacing: 10
            rows: 0
            columns: 2

            Label {
                id: label
                text: qsTr("Type: ")
            }

            ComboBox {
                id: cmbType
                model: ListModel {
                    ListElement { text: "Inches to feet" }
                    ListElement { text: "Feet to inches" }
                }
            }

            Label {
                id: label1
                text: qsTr("From: ")
            }

            TextField {
                id: txtFrom
                placeholderText: qsTr("Enter quantity")
            }

            Label {
                id: label2
                text: qsTr("Result: ")
            }

            Label {
                id: lblResult
                text: qsTr("Nothing")
                font.pointSize: 15
                font.bold: true
            }
        }

        Button {
            id: button
            text: qsTr("Convert")
            anchors.horizontalCenter: parent.horizontalCenter

            onClicked: {
                convert()
            }
        }

    }
}
