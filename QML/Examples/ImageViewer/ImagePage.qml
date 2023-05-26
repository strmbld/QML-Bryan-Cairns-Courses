import QtQuick
import QtQuick.Controls 6.2

Item {
    property alias source: image.source

    Page {
        anchors.fill: parent

        Image {
            id: image
            anchors.fill: parent
            fillMode: Image.PreserveAspectFit
            source: ""
        }
    }
}
