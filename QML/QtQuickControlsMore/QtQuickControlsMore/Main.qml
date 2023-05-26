import QtQuick
import QtQuick.Window
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Row {
        id: row
        x: 18
        y: 21
        width: 196
        height: 67
        spacing: 20

        DelayButton {
            id: delayButton
            width: 100
            height: 40
            text: qsTr("Delay Button")

            delay: 5000
            onProgressChanged: {
                label.text = Math.round(progress * 100) + "%"
            }
            onActivated: {
                label.text = "Done"
                text = "Activated"
            }
        }

        Label {
            id: label
            width: 60
            height: 32
            text: qsTr("Label")
            font.pointSize: 16
        }
    }

    Column {
        id: column
        x: 18
        y: 107
        width: 120
        height: 148

        Label {
            id: label1
            width: 120
            text: qsTr("Label")
            horizontalAlignment: Text.AlignHCenter
            font.pointSize: 16
        }

        Dial {
            id: dial
            width: 120
            height: 120

            onMoved: label1.text = Math.round(dial.value * 100)
        }
    }

    Popup {
        id: popup
        anchors.centerIn: parent
        width: frame.width
        height: frame.height
        modal: true
        focus: true
        closePolicy: Popup.CloseOnEscape // | Popup.CloseOnPressOutside

        Column {
            id: columnPopup
            anchors.fill: parent

            Label {
                id: popupLabel0
                text: "CheckBox0.checked: " + checkBox0.checked
            }

            Label {
                id: popupLabel1
                text: "CheckBox1.checked: " + checkBox1.checked
            }

            Label {
                id: popupLabel2
                text: "CheckBox2.checked: " + checkBox2.checked
            }

            Button {
                id: btnPopupClose
                height: 30
                text: qsTr("Close")
                anchors.left: parent.left
                anchors.right: parent.right

                onClicked: popup.close()
            }
        }
    }

    Frame {
        id: frame
        x: 220
        y: 7
        width: 200
        height: 95

        Column {
            id: column1
            anchors.fill: parent

            CheckBox {
                id: checkBox0
                text: qsTr("Check Box0")
                anchors.left: parent.left
                anchors.right: parent.right
            }

            CheckBox {
                id: checkBox1
                text: qsTr("Check Box1")
                anchors.left: parent.left
                anchors.right: parent.right
            }

            CheckBox {
                id: checkBox2
                text: qsTr("Check Box2")
                anchors.left: parent.left
                anchors.right: parent.right
            }

            Button {
                id: button
                height: 30
                text: qsTr("Show popup")
                anchors.left: parent.left
                anchors.right: parent.right

                onClicked: popup.open()
            }
        }
    }

    property string leftChoice: ""
    property string rightChoice: ""

    Popup {
        id: radioButtonsPopup
        anchors.centerIn: parent
        width: 200
        height: 150
        modal: true
        focus: true
        closePolicy: Popup.CloseOnEscape

        Column {
            anchors.fill: parent
            spacing: 20

            Label {
                id: txtRadioButtonsPopup
                text: leftChoice + " and " + rightChoice
            }

            Button {
                id: btnRadioButtonsPopupClose
                text: "Close"
                onClicked: radioButtonsPopup.close()
            }
        }
    }

    Column {
        id: column4
        x: 205
        y: 128
        width: 427
        height: 159
        spacing: 10

        Row {
            id: row1
            y: 108
            width: 427
            height: 107
            anchors.left: parent.left
            anchors.leftMargin: 0
            spacing: 18

            GroupBox {
                id: groupBox
                width: 200
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 0
                title: qsTr("Group Box")

                Column {
                    id: column2
                    anchors.fill: parent

                    RadioButton {
                        id: radioButton
                        text: qsTr("Radio Button")
                        anchors.left: parent.left
                        anchors.right: parent.right
                    }

                    RadioButton {
                        id: radioButton1
                        text: qsTr("Radio Button1")
                        anchors.left: parent.left
                        anchors.right: parent.right
                    }

                    RadioButton {
                        id: radioButton2
                        text: qsTr("Radio Button2")
                        anchors.left: parent.left
                        anchors.right: parent.right
                    }
                }
            }

            GroupBox {
                id: groupBox1
                width: 200
                height: 200
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                title: qsTr("Group Box")

                Column {
                    id: column3
                    anchors.fill: parent

                    RadioButton {
                        id: radioButton3
                        text: qsTr("Radio Button3")
                        anchors.left: parent.left
                        anchors.right: parent.right
                    }

                    RadioButton {
                        id: radioButton4
                        text: qsTr("Radio Button4")
                        anchors.left: parent.left
                        anchors.right: parent.right
                    }

                    RadioButton {
                        id: radioButton5
                        text: qsTr("Radio Button5")
                        anchors.left: parent.left
                        anchors.right: parent.right
                    }
                }
            }
        }

        Button {
            id: button1
            width: 200
            height: 30
            text: qsTr("Button")
            anchors.right: parent.right
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.rightMargin: 0

            onClicked: {
                for(let i = 0; i < column2.children.length; ++i) {
                    if(column2.children[i].checked) leftChoice = column2.children[i].text
                }

                for(let i = 0; i < column3.children.length; ++i) {
                    if(column3.children[i].checked) rightChoice = column3.children[i].text
                }

                radioButtonsPopup.open()
            }
        }
    }

    Row {
        id: row2
        x: 436
        y: 7
        width: 196
        height: 39
        spacing: 10

        Slider {
            id: slider
            width: 120
            value: 0

            // onMoved: label2.text = Math.round(slider.value * 100)
        }

        Label {
            id: label2
            text: Math.round(slider.value * 100)
            font.pointSize: 16
        }
    }

    Column {
        id: column5
        x: 457
        y: 52
        width: 196
        height: 39
        spacing: 10

        RangeSlider {
            id: rangeSlider
            width: 120
            first.value: 0
            second.value: 0.5
        }

        Label {
            id: label3
            text: "from " + Math.round(rangeSlider.first.value * 100) + " to " + Math.round(rangeSlider.second.value * 100)
            font.pointSize: 16
        }
    }

    Row {
        id: row3
        x: 5
        y: 293
        spacing: 10

        property int value: 0

        RoundButton {
            id: roundButton
            text: "+"

            onClicked: {
                row3.value++;
            }
        }

        RoundButton {
            id: roundButton1
            text: "-"

            onClicked: {
                row3.value--;
            }
        }

        Label {
            id: label4
            text: "Value: " + row3.value
            font.pointSize: 14
        }
    }

    Row {
        id: row4
        x: 11
        y: 347
        width: 45
        height: 28
        spacing: 10

        SpinBox {
            id: spinBox
            height: 28
            value: 0
            editable: true
        }

        Label {
            id: label5
            text: spinBox.value
            font.pointSize: 14
        }
    }

    Row {
        id: row5
        x: 205
        y: 293

        Switch {
            id: switch1
            text: qsTr("Switch")

            // onToggled:
        }

        Label {
            id: label6
            text: switch1.checked
            font.pointSize: 14
        }
    }
}
