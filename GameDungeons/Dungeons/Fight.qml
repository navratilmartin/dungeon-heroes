import QtQuick 2.15

Rectangle {
    property string enemy: game.enemyName
    color: "black"
    width: 600
    height: 600
    focus: true


    InfoFieldText {
        text: "Combat!"
        font.pixelSize: 30
        color: "red"
        y: 100
        anchors.left: parent.left
        anchors.leftMargin: 160
    }

    Image {
        source: if(enemy == "Robber") {
                    "images/robber-mask.png"
                } else if(enemy == "Slime") {
                    "images/slime.png"
                } else if(enemy == "Shaman") {
                    "images/tribal-mask.png"
                } else {
                    ""
                }

        width: 100
        height: 100
        anchors.centerIn: parent
        x: 600
        y: 250

        Rectangle {
           id: healthBar
           height: 20
           width: game.board.boardRoom.enemyHealth(game.hero.heroX,game.hero.heroY)
           color: "green"

           Text {
               id: healthBarText
               color: "red"
               text: game.board.boardRoom.enemyHealth(game.hero.heroX,game.hero.heroY)

           }
        }
    }

    Image {
            source: "images/frog-mouth-helm.png"
            width: 100
            height: 100
            x: 100
            y: 250
    }

    InfoFieldText {
        text: "Press delete key to hit the enemy"
        y: 430
        anchors.left: parent.left
        anchors.leftMargin: 110
    }


    Keys.onDeletePressed: {
        game.attackEnemy()
        gameSessionBlock.statsHeroHealth = game.hero.heroHealth

        if(game.board.boardRoom.enemyHealth(game.hero.heroX,game.hero.heroY)>0) {
            healthBarText.text=game.board.boardRoom.enemyHealth(game.hero.heroX,game.hero.heroY)
            healthBar.width=game.board.boardRoom.enemyHealth(game.hero.heroX,game.hero.heroY)
        } if(game.board.boardRoom.enemyHealth(game.hero.heroX,game.hero.heroY)<=0) {
            roomLoader.source=""
            roomLoader.source="CellField.qml"
            gameSessionBlock.gameInventory.visible = true
            gameSessionBlock.gameSessionMenu.visible = true
        }if(game.hero.heroHealth<=0){
            roomLoader.source=""
            roomLoader.source="GameOver.qml"
            gameSessionBlock.gameInventory.visible = false
            gameSessionBlock.gameSessionMenu.visible = true
        }

    }

}
