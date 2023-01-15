import QtQuick 2.15

Rectangle {
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
        source: if (game.board.boardRoom.oneBoardCell.isBossCell) {
                    "images/totem-mask.png"
                } else if (game.board.boardRoom.oneBoardCell.characterName === "Robber") {
                    "images/robber-mask.png"
                } else if (game.board.boardRoom.oneBoardCell.characterName === "Slime") {
                    "images/slime.png"
                } else if (game.board.boardRoom.oneBoardCell.characterName === "Shaman") {
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
           width: 100
           color: "green"
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
        healthBar.width -= game.hero.heroDamage

        if (healthBar.width <= 0) {
            game.hero.attack(game.board.boardRoom.oneBoardCell)
            roomLoader.source = "CellField.qml"
            gameSessionBlock.statsHeroHealth = game.hero.heroHealth
            gameSessionBlock.statsHeroDamage = game.hero.heroDamage
            gameSessionBlock.statsHeroDefense = game.hero.heroDefense
            gameSessionBlock.statsHeroExperience = game.hero.heroExperience
            gameSessionBlock.statsHeroLevel = game.hero.heroLevel
            gameSessionBlock.statsKilledShamans = game.hero.killedShamans
            gameSessionBlock.gameInventory.visible = true
            gameSessionBlock.gameSessionMenu.visible = true

            if (game.board.boardRoom.oneBoardCell.characterIsNotNull && gameSessionBlock.statsHeroHealth > 0) {
                gameSessionBlock.messageText = "You miraculously escaped!"
                gameSessionBlock.messageVisible = true
                gameSessionBlock.messageTimerRunning = true

            } else if (gameSessionBlock.statsHeroHealth > 0) {
                gameSessionBlock.messageText = "Enemy has been slayed!"
                gameSessionBlock.messageVisible = true
                gameSessionBlock.messageTimerRunning = true

                if (game.board.boardRoom.oneBoardCell.isBossCell) {
                   roomLoader.source = "GameOver.qml"
                   roomLoader.item.gameOverText = "You won!"
                   gameSessionBlock.statsKilledShamans = game.hero.killedShamans-1
                   gameSessionBlock.gameInventory.visible = false
                   gameSessionBlock.gameSessionMenu.visible = true
                }

            } else {
                roomLoader.source = "GameOver.qml"
                gameSessionBlock.gameInventory.visible = false
                gameSessionBlock.gameSessionMenu.visible = true

           }
        }
    }

}
