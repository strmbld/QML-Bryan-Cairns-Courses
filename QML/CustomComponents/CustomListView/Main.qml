import QtQuick
import QtQuick.Window
import QtQuick.Controls 6.2

import "qrc:///"


Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    ListView {
        id: listView
        anchors.fill: parent
        anchors.margins: 20
        delegate: ColorDelegate {}
        model: ColorModel {}
    }
}
