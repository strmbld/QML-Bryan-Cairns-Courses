import QtQuick
import QtQuick.Controls 6.2

ComboBox {
    id: root
    model: ["red", "green", "blue", "yellow", "orange"]

    delegate: ItemDelegate {
        width: root.width
        highlighted: highlightedIndex === index

        contentItem: Row {
            spacing: 5
            width: root.width

            Rectangle {
                anchors.verticalCenter: parent.verticalCenter
                width: 10
                height: 10
                border.width: 1
                border.color: "black"

                color: modelData
            }

            Text {
                text: qsTr(modelData)
                color: "black"
                elide: Text.ElideRight
                verticalAlignment: Text.AlignVCenter
            }
        }

        background: Rectangle {
            width: root.width
            implicitHeight: 40
            implicitWidth: 100
            border.color: currentIndex === index ? "green" : "white"
            color: currentIndex === index ? "lightgreen" : "white"
        }
    }
}
