import QtQuick
import QtQuick.Window
import QtQuick.Controls 6.2

import com.application.worker 1.0


Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Qml-Cpp Interchange")

    Component.onCompleted: {
        btnStart.enabled = true
        btnStop.enabled = false
        btnPause.enabled = false
        btnResume.enabled = false

        progressBar.value = worker.workload
    }

    Worker {
        id: worker

        onStarted: {
            btnStart.enabled = false
            btnStop.enabled = true
            btnPause.enabled = true
            btnResume.enabled = false

            lblStatus.text = "Started"
        }

        onStopped: {
            btnStart.enabled = true
            btnStop.enabled = false
            btnPause.enabled = false
            btnResume.enabled = false

            lblStatus.text = "Stopped"
            progressBar.value = 0
        }

        onPaused: {
            btnStart.enabled = false
            btnStop.enabled = true
            btnPause.enabled = false
            btnResume.enabled = true

            lblStatus.text = "Paused"
        }

        onResumed: {
            btnStart.enabled = false
            btnStop.enabled = true
            btnPause.enabled = true
            btnResume.enabled = false

            lblStatus.text = "Resumed"
        }

        onProgress: {
            lblStatus.text = "Progress: " + worker.workload + "%"
            progressBar.value = worker.workload * 0.01
        }
    }

    Column {
        id: column
        width: 434
        height: 62
        spacing: 10
        anchors.centerIn: parent

        Label {
            id: lblStatus
            text: qsTr("Status")
        }

        ProgressBar {
            id: progressBar
            width: parent.width
            anchors.horizontalCenter: parent.horizontalCenter
            value: 0
        }

        Row {
            id: row
            width: 200
            height: 400
            spacing: 10

            Button {
                id: btnStart
                text: qsTr("Start")

                onClicked: {
                    worker.start()
                }
            }

            Button {
                id: btnStop
                text: qsTr("Stop")

                onClicked: {
                    worker.stop()
                }
            }

            Button {
                id: btnPause
                text: qsTr("Pause")

                onClicked: {
                    worker.pause()
                }
            }

            Button {
                id: btnResume
                text: qsTr("Resume")

                onClicked: {
                    worker.resume()
                }
            }
        }
    }
}
