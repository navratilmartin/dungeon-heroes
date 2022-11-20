import QtQuick 2.15

Column {
    id: gameMenu
    spacing: 10

    MenuButton {
        textB: "New game"

        MouseArea {
            anchors {
                fill: parent
            }

            onClicked: {
                newGameDifficulty.visible = true
                gameMenu.visible = false
            }
        }
    }

    MenuButton {
        textB: "Load game"
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
