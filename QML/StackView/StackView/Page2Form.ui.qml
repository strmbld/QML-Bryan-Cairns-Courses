import QtQuick
import QtQuick.Controls 6.2

Page {
    id: page2
    width: 600
    height: 400

    title: qsTr("Page 2")

    Label {
        text: qsTr("You are on Page 2.")
        anchors.centerIn: parent
    }
}
