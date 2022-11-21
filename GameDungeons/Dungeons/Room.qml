import QtQuick 2.15

Rectangle {
    property int positionx: 1
    property int positiony: 1
    width: 20
    height: 20
    color: "green"
    x: 15+55*(positionx-1)
    y: 15+55*(positiony-1)

    Image {
        source: "images/exit-door.png"
        width: 50
        height: 50
        anchors {
            centerIn: parent
        }
    }
}
