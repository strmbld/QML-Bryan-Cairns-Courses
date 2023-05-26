import QtQuick
import QtQuick.Window
import QtQuick.Controls 6.2

import "qrc:///"


Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Dice Roller")

    function calc() {
        let total = 0

        for(let i = 0; i < listView.model.count; i++) {
            let item = listView.model.get(i);

            for(let rolls = 0; rolls < item.value; rolls++) {
                let min = 1
                let max = item.number
                // let subtotal = Math.floor(Math.random() * (max - min + 1)+ min)
                let subtotal = Math.floor((Math.random() * max) + min)
                total += subtotal
            }
        }

        lblTotal.text = "Total: " + total
    }

    Column {
        id: column
        anchors.fill: parent
        spacing: 10

        ListView {
            id: listView
            width: parent.width
            focus: true
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 100

            model: DiceModel {}
            delegate: DiceDelegate {}
        }

        Row {
            id: row
            width: parent.width
            height: 50
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0

            Rectangle {
                anchors.fill: parent
                color: "gray"

                Label {
                    id: lblTotal
                    color: "white"
                    text: "Total: 0"
                    font.pointSize: 25
                    font.bold: true
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.leftMargin: 10
                }

                Button {
                    id: btnCalculate
                    text: "Calculate"
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.right: parent.right
                    anchors.rightMargin: 10

                    onClicked: {
                        calc()
                    }
                }
            }
        }
    }
}
