import QtQuick 2.15

Rectangle {
    id: gameOver
    property alias gameOverText: gameOverInfoFieldText.text

    Column {
        spacing: 5
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter

        InfoFieldText {
            id: gameOverInfoFieldText
            text: "You died..."
            font.pixelSize: 30
            anchors.horizontalCenter: parent.horizontalCenter
        }

        MenuButton {
            id: newGameAfterSession
            textB: "New game"
            anchors.horizontalCenter: parent.horizontalCenter

            MouseArea {
                anchors {
                    fill: parent
                }

                onClicked: {
                    gameSessionBlock.visible = false
                    roomLoaderWrapper.visible = false
                    roomLoader.visible = false
                    roomLoader.active = false
                    roomLoader.roomNumber = 0
                    roomLoader.sourceComponent = gameFieldComp
                    newGameDifficulty.visible = true
                }
            }
        }

    }
}
