import QtQuick
import QtQuick.Window
import QtQuick.Controls 6.2

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Column {
        id: column
        width: 200
        height: 168
        spacing: 25
        anchors.centerIn: parent

        Label {
            id: label
            text: qsTr("Call a C++ slot")
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Button {
            id: button
            text: qsTr("Call")
            anchors.horizontalCenter: parent.horizontalCenter

            onClicked: {
                externalCppClass.doSomething(); // Slot; works fine
                externalCppClass.getNumber(); // can't call regular method
            }
        }
    }


}
