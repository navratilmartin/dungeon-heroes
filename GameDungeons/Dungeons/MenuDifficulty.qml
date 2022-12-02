import QtQuick 2.15

Rectangle {
    property alias textDiff: textDifficulty.text
    property int levelDifficulty: 0
    width: 100
    height: 40

    Text {
        id: textDifficulty
        text: "Difficulty"

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
            game.play(levelDifficulty)
            roomLoader.active = true
        }
    }
}
