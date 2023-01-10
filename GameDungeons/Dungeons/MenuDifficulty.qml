import QtQuick 2.15

Rectangle {
    property alias textDiff: textDifficulty.text
    property int levelDifficulty: 0
    width: 100
    height: 40
    color: "black"

    Text {
        id: textDifficulty
        text: "Difficulty"
        color: "white"
        font.family: "Helvetica"
        font.pixelSize: 13
        font.bold: true

        anchors {
            centerIn: parent
        }
    }

    MouseArea {
        anchors {
            fill: parent
        }

        onClicked: {
            newGameDifficulty.visible = false

            // Initializing new Board and Hero
            game.play(levelDifficulty)
            roomLoader.active = true

            // Initializing main session and hero invetory and stats
            gameTitle.visible = false
            gameSessionBlock.visible = true
            gameSessionBlock.gameInventory.inventoryModel = game.hero.heroInventory
            gameSessionBlock.statsHeroName = game.hero.heroName
            gameSessionBlock.statsHeroHealth = game.hero.heroHealth
            gameSessionBlock.statsHeroDamage = game.hero.heroDamage
            gameSessionBlock.statsHeroDefense = game.hero.heroDefense
            gameSessionBlock.statsHeroLevel = game.hero.heroLevel
            gameSessionBlock.statsHeroExperience = game.hero.heroExperience
        }
    }
}
