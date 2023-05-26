import QtQuick
import QtQuick.Window
import QtQuick.Controls 6.2

Window {
    width: 640
    height: 320
    visible: true
    title: qsTr("Scroll View")

    Component {
        id: component

        Item {
            id: listItem
            width: 200
            height: 50

            Row {
                anchors.fill: parent
                spacing: 5

                Label {
                    text: name
                    font.bold: true
                }

                Label {
                    text: number
                }
            }
        }
    }

    ListModel {
        id: listModel

        ListElement {
            name: "Some Name0"
            number: "555 3535"
        }
        ListElement {
            name: "Some Name1"
            number: "555 3536"
        }
        ListElement {
            name: "Some Name2"
            number: "555 3537"
        }
        ListElement {
            name: "Some Name3"
            number: "555 3538"
        }
        ListElement {
            name: "Some Name4"
            number: "555 3539"
        }
        ListElement {
            name: "Some Name5"
            number: "555 3540"
        }
        ListElement {
            name: "Some Name6"
            number: "555 3541"
        }
        ListElement {
            name: "Some Name7"
            number: "555 3542"
        }
        ListElement {
            name: "Some Name8"
            number: "555 3543"
        }
    }

    ScrollView {
        id: scrollView
        anchors.fill: parent

        ListView {
            width: parent.width
            model: listModel
//            delegate: ItemDelegate {
//                text: "Item " + (index + 1)
//                width: parent.width
//            }
            delegate: component
        }
    }
}
