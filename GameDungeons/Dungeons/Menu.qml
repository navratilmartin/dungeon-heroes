import QtQuick 2.15

Column {
    id: gameMenu
    property alias resumeButtonVisible: gameSessionResume.visible
    property alias saveButtonVisible: gameSessionSave.visible

    spacing: 10

    MenuButton {
        id: gameSessionResume
        textB: "Resume"
        visible: false

        MouseArea {
            anchors {
                fill: parent
            }

            onClicked: {
                gameMenu.visible = false
                gameSessionBlock.visible = true
                roomLoaderWrapper.visible = true
                roomLoader.visible = true
            }
        }
    }

    MenuButton {
        id: gameSessionSave
        textB: "Save game"
        visible: false

        MouseArea {
            anchors {
                fill: parent
            }

            onClicked: {
                gameMenu.visible = false
                gameSessionBlock.visible = true
                gameSessionBlock.messageText = "Game saved"
                gameSessionBlock.messageVisible = true
                gameSessionBlock.messageTimerRunning = true
                roomLoaderWrapper.visible = true
                roomLoader.visible = true
                game.saveGame()
            }
        }
    }



    MenuButton {
        id: newGameMenu
        textB: "New game"

        MouseArea {
            anchors {
                fill: parent
            }

            onClicked: {
                newGameDifficulty.visible = true
                newGameMenu.visible = false
                gameMenu.visible = false
            }
        }
    }

    MenuButton {
        textB: "Load game"

        MouseArea {
            anchors {
               fill: parent
            }

            onClicked: {
                if (roomLoader.active === true) {
                    roomLoader.active = false
                }
                game.loadBoard();
                roomLoader.active = true
                // console.log(game.hero.heroX)
                // console.log(game.hero.heroX)
                roomLoader.visible = true
                roomLoaderWrapper.visible = true
                roomLoader.focus = true
                //roomLoader.item.gameHeroEntity.focus = true

                // Initializing main session and hero inventory and stats
                gameMenu.visible = false
                gameTitle.visible = false
                gameSessionBlock.gameInventory.visible = true
                gameSessionBlock.visible = true
                gameSessionBlock.messageText = "Use the arrow keys to move the hero on the map"
                gameSessionBlock.messageVisible = true
                gameSessionBlock.messageTimerRunning = true

                gameSessionBlock.gameInventory.inventoryModel = game.hero.heroInventory
                gameSessionBlock.statsHeroName = game.hero.heroName
                gameSessionBlock.statsHeroHealth = game.hero.heroHealth
                gameSessionBlock.statsHeroDamage = game.hero.heroDamage
                gameSessionBlock.statsHeroDefense = game.hero.heroDefense
                gameSessionBlock.statsHeroLevel = game.hero.heroLevel
                gameSessionBlock.statsHeroExperience = game.hero.heroExperience
                gameSessionBlock.statsKilledShamans = game.hero.killedShamans
                gameSessionBlock.totalShamans = game.board.numberOfShamans
            }
        }

    }

    MenuButton {
        textB: "Quit"

        MouseArea {
            anchors {
                fill: parent
            }

            onClicked: {
                root.close()
            }
        }
    }

    anchors {
        centerIn: parent
    }

}
