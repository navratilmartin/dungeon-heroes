import QtQuick 2.15

Rectangle {
    width: 200
    height: 200
    border.width: 1
    border.color: "white"
    radius: 5
    anchors.left: parent.left
    y: 18
    anchors.leftMargin: 15
    color: "#96001850"


    Text {
        text: "Hero"
        font.family: "Papyrus"
        font.pixelSize: 25
        color: "white"
        anchors.horizontalCenter: parent.horizontalCenter
    }
}
