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
                game.loadBoard();
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
