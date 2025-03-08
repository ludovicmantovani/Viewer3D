import QtQuick
import QtQuick.Controls

ApplicationWindow {
    id: root
    width: 1024
    height: 640
    visible: true
    title: qsTr("Viewer3D")

    Text {
        anchors.centerIn: parent
        text: filePath ? "File: " + filePath : "No file provided"
        color: "black"
        font.pixelSize: 20
    }
}
