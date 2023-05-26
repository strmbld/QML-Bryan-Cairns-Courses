import QtQuick
import QtQuick.Controls 6.2


Component {
    id: diceDelegate

    Item {
        id: item
        anchors.leftMargin: 10
        width: parent.width
        height: 100

        Row {
            spacing: 10

            Label {
                width: 50
                font.bold: true
                font.pixelSize: 25
                text: model.name // from model
            }

            SpinBox {
                id: sbThrows
                from: 0
                to: 100
                value: model.value // from model

                onValueChanged: {
                    model.value = sbThrows.value
                }
            }
        }
    }
}
