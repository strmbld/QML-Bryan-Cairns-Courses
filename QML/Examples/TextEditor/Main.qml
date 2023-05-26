import QtQuick
import QtQuick.Window
import QtQuick.Controls 6.2
import QtQuick.Dialogs 6.2

import com.application.backend 1.0


ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Text Editor")

    menuBar: MenuBar {
        Menu {
            id: menuFile
            title: qsTr("File")
            MenuItem { action: actionNew }
            MenuItem { action: actionOpen }
            MenuItem { action: actionSave }
            MenuItem { action: actionQuit }
        }
        Menu {
            id: menuEdit
            title: qsTr("Edit")
            MenuItem { action: actionCopy }
            MenuItem { action: actionCut }
            MenuItem { action: actionPaste }
        }
    }

    header: ToolBar {
        Row {
            ToolButton { display: AbstractButton.IconOnly; action: actionNew }
            ToolButton { display: AbstractButton.IconOnly; action: actionOpen }
            ToolButton { display: AbstractButton.IconOnly; action: actionSave }
            ToolButton { display: AbstractButton.IconOnly; action: actionCopy }
            ToolButton { display: AbstractButton.IconOnly; action: actionCut }
            ToolButton { display: AbstractButton.IconOnly; action: actionPaste }
        }
    }

    Backend {
        id: backend
    }

    FileDialog {
        id: openDialog
        title: "Choose a file to open"
        fileMode: FileDialog.OpenFile

        onAccepted: {
            backend.path = openDialog.selectedFile
            editor.text = backend.data
        }
    }

    FileDialog {
        id: saveDialog
        title: "Save as"
        fileMode: FileDialog.SaveFile

        onAccepted: {
            backend.path = saveDialog.selectedFile
            backend.data = editor.text
        }
    }

    Action {
        id: actionNew
        text: qsTr("New")
        icon.color: "transparent"
        icon.source: "qrc:/images/new.png"

        onTriggered: {
            editor.clear()
        }
    }

    Action {
        id: actionOpen
        text: qsTr("Open")
        icon.color: "transparent"
        icon.source: "qrc:/images/open.png"

        onTriggered: {
            openDialog.open()
        }
    }

    Action {
        id: actionSave
        text: qsTr("Save")
        icon.color: "transparent"
        icon.source: "qrc:/images/save.png"

        onTriggered: {
            saveDialog.open()
        }
    }

    Action {
        id: actionCopy
        text: qsTr("Copy")
        icon.color: "transparent"
        icon.source: "qrc:/images/copy.png"

        onTriggered: {
            editor.copy()
        }
    }

    Action {
        id: actionCut
        text: qsTr("Cut")
        icon.color: "transparent"
        icon.source: "qrc:/images/cut.png"

        onTriggered: {
            editor.cut()
        }
    }

    Action {
        id: actionPaste
        text: qsTr("Paste")
        icon.color: "transparent"
        icon.source: "qrc:/images/paste.png"

        onTriggered: {
            editor.paste()
        }
    }

    Action {
        id: actionQuit
        text: qsTr("Exit")

        onTriggered: {
            Qt.quit()
        }
    }

    ScrollView {
        anchors.fill: parent

        TextArea {
            id: editor
            focus: true
            selectByMouse: true
            persistentSelection: true
        }
    }
}
