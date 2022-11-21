import QtQuick 2.15

Rectangle {
    width: 50
    height: 50
    color: "black"

    Image {
        source: "images/path-tile"
        width: 30
        height: 30
        anchors {
            centerIn: parent
        }
    }
}
