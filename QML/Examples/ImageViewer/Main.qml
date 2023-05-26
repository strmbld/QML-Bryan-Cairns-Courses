import QtQuick
import QtQuick.Window
import QtQuick.Controls 6.2

import com.application.dirhelper 1.0


Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Image Viewer")

    DirHelper {
        id: dirHelper
        path: "C:\\Users\\strmbld\\Pictures"
    }

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: 0

        Component.onCompleted: {
            let files = dirHelper.files

            for(let i = 0; i < files.length; i++) {
                let component = Qt.createComponent("qrc:/ImagePage.qml")
                let page = component.createObject(swipeView, { "width": 640, "height": 480 })
                page.source = "file:\\" + files[i]
            }
        }
    }
}
