import QtQuick 2.15
import QtQuick.Layouts 1.15

GridLayout {
    property alias inventoryModel: inventoryRepeater.model

    width: 200
    height: 130
    rows: 3
    columns: 4
    columnSpacing: 7


    Repeater {
        id: inventoryRepeater
        model: 0

        Field {            
            property int itemIndex: index
            property string borderColor: "white"
            property string fieldImage: fieldImagePath

            width: 57
            color: "#96001850"
            border.color: if (modelData !== null) {
                              if (modelData === game.hero.heroWeapon || modelData === game.hero.heroArmor) {
                                  "blue"
                              } else {
                                  borderColor
                              }
                          } else {
                              borderColor
                          }

            border.width: 2
            radius: 5
            fieldImagePath: if (modelData !== null) {
                                 if (modelData.QitemName === "Sword") {
                                           "images/piercing-sword.png"
                                    } else if (modelData.QitemName === "Axe") {
                                               "images/battle-axe.png"
                                    } else if (modelData.QitemName === "Dagger") {
                                               "images/plain-dagger.png"
                                    } else if (modelData.QitemName === "Armor") {
                                               "images/armor-vest.png"
                                    } else if (modelData.QitemName === "Potion") {
                                               "images/potion-ball.png"
                                    }
                                    } else {
                                        ""
                                    }
            MouseArea {
                anchors.fill: parent

                onClicked: {
                    if (modelData !== null) {
                        borderColor = "green"

                        inventoryButtonsTimer.running = true
                        useItemButton.visible = true
                        dropItemButton.visible = true
                        useItemButton.currentItem = itemIndex
                        dropItemButton.currentItem = itemIndex
                    }
                }
            }
        }
    }

    Rectangle {
        width: 57
        radius: 5
        height: 10
        color: "#00000000"
        Layout.column: 0
        Layout.row: 2
    }

    MenuButton {
        id: useItemButton
        property int currentItem: 0
        height: 40
        width: 57
        radius: 5
        textB: "Use"
        textBSize: 16
        visible: false
        Layout.column: 1
        Layout.row: 2

        MouseArea {
            anchors.fill: parent

            onClicked: {
                useItemButton.visible = false
                dropItemButton.visible = false

                // If Item has a type of Weapon (enum class)
                if ((game.hero.heroInventory[useItemButton.currentItem].itemType === 3 && game.hero.heroWeapon === null) ||

                // or if Item has a type of Armor (enum class)
                (game.hero.heroInventory[useItemButton.currentItem].itemType === 2 && game.hero.heroArmor === null)) {
                    game.hero.useItem(useItemButton.currentItem)
                    gameSessionBlock.statsHeroDamage = game.hero.heroDamage
                    gameSessionBlock.statsHeroDefense = game.hero.heroDefense
                    inventoryRepeater.itemAt(useItemButton.currentItem).borderColor = "blue"
                } else if (game.hero.heroInventory[useItemButton.currentItem].itemType === 1) {
                    game.hero.useItem(useItemButton.currentItem)
                    gameSessionBlock.statsHeroHealth = game.hero.heroHealth
                } else {
                    gameSessionBlock.messageTimerRunning = true
                    gameSessionBlock.messageVisible = true
                    gameSessionBlock.messageText = "You can't equip more than one weapon or armor!"
                    inventoryRepeater.itemAt(useItemButton.currentItem).borderColor = "white"
                }
            }
        }
    }

    MenuButton {
        id: dropItemButton
        property int currentItem: 0

        height: 40
        width: 57
        textB: "Drop"
        textBSize: 16
        visible: false
        Layout.column: 2
        Layout.row: 2

        MouseArea {
            anchors.fill: parent

            onClicked: {
                game.hero.dropItem(dropItemButton.currentItem)
                gameSessionBlock.statsHeroDamage = game.hero.heroDamage
                gameSessionBlock.statsHeroDefense = game.hero.heroDefense

                inventoryRepeater.itemAt(dropItemButton.currentItem).borderColor = "white"
                dropItemButton.visible = false
                useItemButton.visible = false
            }
        }

    }

    Timer {
        id: inventoryButtonsTimer
        interval: 4000
        onTriggered: {
            useItemButton.visible = false
            dropItemButton.visible = false
            inventoryRepeater.itemAt(useItemButton.currentItem).borderColor = "white"
        }

        running: false
    }
}
