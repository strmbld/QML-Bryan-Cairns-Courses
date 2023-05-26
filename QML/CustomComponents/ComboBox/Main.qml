import QtQuick
import QtQuick.Window

import "qrc:///"


Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Custom ComboBox")

    ColorCombo {
        id: cmbColor
        anchors.centerIn: parent
    }
}
