import QtQuick 2.15

Rectangle {
    property alias fieldImagePath: fieldImage.source
    width: 50
    height: 50
    color: "black"

    Image {
        id: fieldImage
        source: "images/path-tile"
        width: 30
        height: 30
        anchors {
            centerIn: parent
        }
    }
}
