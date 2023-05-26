import QtQuick

Component {
    id: colorDelegate
    Item {
        id: item
        width: 180
        height: 40
        Row {
            spacing: 5

            Rectangle {
                id: colorBox
                width: 10
                height: 10
                color: code // from model
                border.color: "black"
                border.width: 1
            }

            Text {
                text: '<b>Name</b> ' + name // name from model
            }
        }
    }
}
