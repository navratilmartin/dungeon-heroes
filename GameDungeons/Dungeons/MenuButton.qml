import QtQuick 2.15

Rectangle {
    property alias textB: textButton.text
    property alias textBSize: textButton.font.pixelSize
    property alias textBFamily: textButton.font.family

    width: 100
    height: 40
    color: "black"

    Text {
        id: textButton
        text: "Menu Button"
        color: "white"
        font.family: "Helvetica"
        font.pixelSize: 13
        font.bold: true

        anchors {
            centerIn: parent
        }
    }
}
