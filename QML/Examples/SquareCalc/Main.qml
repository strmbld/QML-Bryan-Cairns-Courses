import QtQuick
import QtQuick.Window
import QtQuick.Controls 6.2

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Square Calc")

    function calc() {
        lblResult.text = sbWidth.value * sbHeight.value + " sqft/sqmt"
    }

    Column {
        id: column
        width: 200
        height: 228
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 10

        Label {
            id: lblResult
            text: qsTr("0 sqft/sqmt")
            anchors.horizontalCenter: parent.horizontalCenter
            font.pointSize: 25
            font.bold: true
        }

        Grid {
            id: grid
            rows: 2
            columns: 2
            spacing: 10

            Label {
                id: label1
                text: qsTr("Width")
            }

            SpinBox {
                id: sbWidth

                onValueChanged: {
                    calc()
                }
            }

            Label {
                id: label2
                text: qsTr("Height")
            }

            SpinBox {
                id: sbHeight

                onValueChanged: {
                    calc()
                }
            }
        }
    }
}
