import QtQuick 2.15

Column {
    id: sessionBlock
    property alias gameInventory: gameInventoryElement

    // properties for hero's stats, then included in InfoField
    property string statsHeroName: "Hero"
    property int statsHeroHealth: 100
    property int statsHeroDamage: 0
    property int statsHeroDefense: 0
    property int statsHeroLevel: 1
    property int statsHeroExperience: 0

    property bool messageVisible: false
    property alias messageText: infoMessage.text
    property alias messageTimerRunning: infoMessageTimer.running

    spacing: 20
    anchors.verticalCenter: parent.verticalCenter
    padding: 15

    InfoField {
        width: 250
        height: 200
    }

    Inventory {
        id: gameInventoryElement
    }

    Rectangle {
        height: 50
        width: 250
        color: "#00000000"
        anchors.horizontalCenter: parent.horizontalCenter

        InfoFieldText {
            id: infoMessage

            visible: messageVisible
            text: "Use the arrow keys to move the hero on the map"
            font.pixelSize: 13
        }

        Timer {
            id: infoMessageTimer
            interval: 5000
            onTriggered: {
                sessionBlock.messageVisible = false
            }
            running: false
        }
    }

    Rectangle {
        width: 250
        height: 20
        color: "#00000000"
        anchors.horizontalCenter: parent.horizontalCenter

        MenuButton {
        height: 15
        textB: "Help"
        textBSize: 18
        anchors.left: parent.left

            MouseArea {
                anchors.fill: parent

                onClicked: {

                }
            }
        }

        MenuButton {
            id: gameSessionBlockMenu
            height: 15
            textB: "Menu"
            textBSize: 18
            anchors.right: parent.right

            MouseArea {
                anchors.fill: parent

                onClicked: {
                    gameSessionBlock.visible = false
                    roomLoaderWrapper.visible = false
                    roomLoader.visible = false

                    if (fightLoader.visible === true) {
                        fightLoader.visible = false
                    }

                    gameMainMenu.visible = true
                    gameMainMenu.resumeButtonVisible = true
                    gameMainMenu.saveButtonVisible = true
                }
            }
        }
    }
}
