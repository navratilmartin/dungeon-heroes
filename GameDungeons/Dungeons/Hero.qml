import QtQuick 2.15

Rectangle {
    property int logicalPositionx: game.hero.heroX
    property int logicalPositiony: game.hero.heroY


    property int realPositionx: logicalPositionx+1
    property int realPositiony: logicalPositionY+1
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
    id:hero


    Image {
        Text{
            id:onEnemy
            text: game.onEnemy()
            color:"red"

        }
        Text{
            id:enemyName
            topPadding: 10
            text:"Nothing"
            color:"red"
        }



        source: "images/frog-mouth-helm.png"
        width: 30
        height: 30
        anchors {
            centerIn: parent
        }
//        Text{
//            text:logicalPositionx
//            color:"red"
//        }
//        Text {
//            text:logicalPositiony
//            color:"red"
//            leftPadding: 10
//        }
    }

    Keys.onUpPressed: {
        if(logicalPositiony-1>=0) {

            game.hero.changeY(-1)
            onEnemy.text= game.onEnemy()
            if(game.onEnemy()){
                enemyName.text = game.enemyName
            }else{
                enemyName.text = "Nothing"
            }


            checkRoom()
            if(game.onEnemy()){
                if(game.board.boardRoom.boardCells[game.hero.heroY][game.hero.heroX].characterHealth>0){
                    roomLoader.sourceComponent=fightFieldComp
                    gameSessionBlock.gameInventory.visible = false
                }
            }

        } else {

        }
    }

    Keys.onRightPressed: {
        if(logicalPositionx+1<dimension) {

            game.hero.changeX(1);
            onEnemy.text= game.onEnemy()
            if(game.onEnemy()){
                enemyName.text = game.enemyName
            }else{
                enemyName.text = "Nothing"
            }
            checkRoom()
            if(game.onEnemy()){
                if(game.board.boardRoom.boardCells[game.hero.heroY][game.hero.heroX].characterHealth>0){
                    if(game.board.boardRoom.boardCells[game.hero.heroY][game.hero.heroX].characterHealth>0){
                        roomLoader.sourceComponent=fightFieldComp
                        gameSessionBlock.gameInventory.visible = false
                    }
                }


            }

        } else {

        }
    }

    Keys.onDownPressed: {
        if(logicalPositiony+1<dimension) {

            game.hero.changeY(1)
            onEnemy.text= game.onEnemy()
            if(game.onEnemy()){
                enemyName.text = game.enemyName
            }else{
                enemyName.text = "Nothing"
            }
            checkRoom()
            if(game.onEnemy()){
                if(game.board.boardRoom.boardCells[game.hero.heroY][game.hero.heroX].characterHealth>0){
                    roomLoader.sourceComponent=fightFieldComp
                    gameSessionBlock.gameInventory.visible = false
                }
            }

        } else {

        }
    }

    Keys.onLeftPressed: {
        if(logicalPositionx-1>=0) {

            game.hero.changeX(-1)
            onEnemy.text= game.onEnemy()
            if(game.onEnemy()){
                enemyName.text = game.enemyName
            }else{
                enemyName.text = "Nothing"
            }
            checkRoom()
            if(game.onEnemy()){
                if(game.board.boardRoom.boardCells[game.hero.heroY][game.hero.heroX].characterHealth>0){
                    roomLoader.sourceComponent=fightFieldComp
                    gameSessionBlock.gameInventory.visible = false
                }
            }
        } else {

        }

    }





    function checkRoom() {
        if (logicalPositiony >= 1) {
                  game.board.boardRoom.extractOneBoardCell(logicalPositiony, logicalPositionx)
                  game.hero.interactWithBoardCell(game.board.boardRoom.oneBoardCell)
                  gameSessionBlock.gameInventory.inventoryModel = game.hero.heroInventory
        } else if(logicalPositionx === room.logicalPositionx && logicalPositiony === room.logicalPositiony
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
