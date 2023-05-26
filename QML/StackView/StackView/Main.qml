import QtQuick
import QtQuick.Window
import QtQuick.Controls 6.2

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("StackView")

    header: ToolBar {
        contentHeight: toolButton.implicitHeight

        ToolButton {
            id: toolButton
            text: stackView.depth > 1 ? "\u25C0" : "\u2630"
            font.pixelSize: Qt.application.font.pixelSize * 1.6

            onClicked: {
                if(stackView.depth > 1) {
                    stackView.pop()

                    return;
                }

                drawer.open()
            }
        }

        Label {
            text: stackView.currentItem.title
            anchors.centerIn: parent
        }
    }

    Drawer {
        id: drawer
        width: parent.width * 0.66
        height: parent.height

        Column {
            anchors.fill: parent

            ItemDelegate {
                text: qsTr("Page 1")
                width: parent.width

                onClicked: {
                    stackView.push("qrc:/Page1Form.ui.qml")
                    drawer.close()
                }
            }

            ItemDelegate {
                text: qsTr("Page 2")
                width: parent.width

                onClicked: {
                    stackView.push("qrc:/Page2Form.ui.qml")
                    drawer.close()
                }
            }

            ItemDelegate {
                text: qsTr("Page 3")
                width: parent.width

                onClicked: {
                    stackView.push("qrc:/Page3Form.ui.qml")
                    drawer.close()
                }
            }
        }
    }

    StackView {
        id: stackView
        anchors.fill: parent
        initialItem: "qrc:/HomeForm.ui.qml"
    }
}
