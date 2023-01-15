import QtQuick 2.15

Rectangle {
    property int logicalPositionx: game.hero.heroX
    property int logicalPositiony: game.hero.heroY

    property bool allShamansKilled: false

    property int realPositionx: logicalPositionx+1
    property int realPositiony: logicalPositiony+1
    property int dimension: 8

    property int toplimit: 0
    property int rightlimit: 55*dimension
    property int bottomlimit: 55*dimension
    property int leftlimit: 0

    x: 15+(logicalPositionx)*55
    y: 15+(logicalPositiony)*55
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
        if (logicalPositiony-1 >= 0) {
            game.hero.changeY(-1)
            checkCell()
        }
    }

    Keys.onRightPressed: {
        if (logicalPositionx+1 < dimension) {
            game.hero.changeX(1)
            checkCell()
        }
    }

    Keys.onDownPressed: {
        if (logicalPositiony+1 < dimension) {
            game.hero.changeY(1)
            checkCell()
        }
    }

    Keys.onLeftPressed: {
        if (logicalPositionx-1 >= 0) {
            game.hero.changeX(-1)
            checkCell()
        }
    }


    function checkCell() {
        if (logicalPositiony >= 1) {
              game.board.boardRoom.extractOneBoardCell(logicalPositiony, logicalPositionx)
              game.hero.interactWithBoardCell(game.board.boardRoom.oneBoardCell)

              if (game.hero.heroEncounter) {
                  roomLoader.sourceComponent = fightFieldComp
                  gameSessionBlock.gameInventory.visible = false
                  gameSessionBlock.gameSessionMenu.visible = false
              }

              if (game.hero.killedShamans === game.board.numberOfShamans && !allShamansKilled) {
                  game.board.revealBoss()
                  allShamansKilled = true
                  gameSessionBlock.messageText = "The Greatest Shaman appeared!"
                  gameSessionBlock.messageVisible = true
                  gameSessionBlock.messageTimerRunning = true
              }

              gameSessionBlock.gameInventory.inventoryModel = game.hero.heroInventory
        } else if (logicalPositionx === room.logicalPositionx && logicalPositiony === room.logicalPositiony
                && room.visible === true) {
            game.board.switchRoom(1)
            roomLoader.roomNumber += 1
            game.hero.resetXY()
        } else if (logicalPositionx === exit.logicalPositionx && logicalPositiony === exit.logicalPositiony
                   && exit.visible === true) {
            game.board.switchRoom(0)
            roomLoader.roomNumber -= 1
            game.hero.resetXY()
        }
    }
}
