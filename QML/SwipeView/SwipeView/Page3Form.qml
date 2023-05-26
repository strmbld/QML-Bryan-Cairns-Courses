import QtQuick
import QtQuick.Controls 6.2

Page {
    width: 600
    height: 400

    header: Label {
        text: qsTr("Page 3")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    Label {
        text: qsTr("You are on Page 3.")
        font.pointSize: 15
        font.bold: true
        anchors.centerIn: parent
    }
}
