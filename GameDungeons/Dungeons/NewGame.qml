import QtQuick 2.15

Column {
        spacing: 10
        visible: false

        MenuDifficulty {
            textDiff: "Easy"
            levelDifficulty: 0
        }

        MenuDifficulty {
            textDiff: "Medium"
            levelDifficulty: 1
        }

        MenuDifficulty {
            textDiff: "Hard"
            levelDifficulty: 2
        }

        anchors {
            centerIn: parent
        }
    }
