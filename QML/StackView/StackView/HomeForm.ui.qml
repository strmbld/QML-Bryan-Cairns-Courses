import QtQuick
import QtQuick.Controls 6.2

Page {
    id: homepage
    width: 600
    height: 400

    title: qsTr("Homepage")

    Label {
        text: qsTr("You are on Homepage.")
        anchors.centerIn: parent
    }
}
