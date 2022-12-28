import QtQuick 2.15

Rectangle {
    property int logicalPositionx: 0
    property int logicalPositiony: 0

    property int realPositionx:1
    property int realPositiony:1
    property int dimension: 8

    property int toplimit: 0
    property int rightlimit: 55*dimension
    property int bottomlimit: 55*dimension
    property int leftlimit: 0

    x: 15+(realPositionx-1)*55
    y: 15+(realPositiony-1)*55
    width: 20
    height: 20

    focus: true

    Image {
        source: "images/frog-mouth-helm.png"
        width: 30
        height: 30
        anchors {
            centerIn: parent
        }
    }

    Keys.onUpPressed: {
        if(y-55>toplimit) {
            y=y-55
            logicalPositiony -= 1

            checkRoom()

        } else {

        }
    }

    Keys.onRightPressed: {
        if(x+55<rightlimit) {
            x=x+55
            logicalPositionx += 1

            checkRoom()

        } else {

        }
    }

    Keys.onDownPressed: {
        if(y+55<bottomlimit) {
            y=y+55
            logicalPositiony += 1

            checkRoom()

        } else {

        }
    }

    Keys.onLeftPressed: {

        if(x-55>leftlimit) {
            x=x-55
            logicalPositionx -= 1

            checkRoom()

        } else {

        }

    }

    function checkRoom() {
        if(logicalPositionx === room.logicalPositionx && logicalPositiony === room.logicalPositiony
                && room.visible == true) {
            roomLoader.active = false
            game.board.switchRoom(1)
            roomLoader.active = true
            roomLoader.roomNumber += 1
        } else if (logicalPositionx === exit.logicalPositionx && logicalPositiony === exit.logicalPositiony
                   && exit.visible === true) {
            roomLoader.active = false
            game.board.switchRoom(0)
            roomLoader.active = true
            roomLoader.roomNumber -= 1
        }
    }
}
