import QtQuick 2.15

Rectangle {
    property int logicalPositionx: 7
    property int logicalPositiony: 0

    property int realPositionx: 1
    property int realPositiony: 1

    width: 20
    height: 20
    color: "green"
    x: 15+55*(realPositionx-1)
    y: 15+55*(realPositiony-1)

    Image {
        source: "images/exit-door.png"
        width: 50
        height: 50
        anchors {
            centerIn: parent
        }
    }
}
