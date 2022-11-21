import QtQuick 2.15

Rectangle {
    property int logicalPositionx: 0
    property int logicalPositiony: 0

    property int realPositionx:1
    property int realPositiony:1
    property int dimension: 8

    property bool enteredRoom: false

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
        if(y-55>toplimit){
            y=y-55
            logicalPositiony -= 1

            if (enteredRoom === false) {
                checkRoom()
            }

        }else{

        }
    }
    Keys.onRightPressed: {
        if(x+55<rightlimit){
            x=x+55
            logicalPositionx += 1

            if (enteredRoom === false) {
                checkRoom()
            }
        }else{

        }
    }
    Keys.onDownPressed: {
        if(y+55<bottomlimit){
            y=y+55
            logicalPositiony += 1

            if (enteredRoom === false) {
                checkRoom()
            }

        }else{

        }
    }
    Keys.onLeftPressed: {
        if(x-55>leftlimit){
            x=x-55
            logicalPositionx -= 1

            if (enteredRoom === false) {
                checkRoom()
            }
        }else{

        }

    }

    function checkRoom() {
        if(game.board[logicalPositionx][logicalPositiony].emptyRoom === true) {
            enteredRoom = true
            pageloader.active=true
            root.visible=false
        }
    }
}
