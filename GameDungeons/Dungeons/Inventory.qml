import QtQuick 2.15

Grid {
    property alias inventoryModel: inventoryRepeater.model

    width: 200
    height: 130
    rows: 3
    columns: 4
    spacing: 7


    Repeater {
        id: inventoryRepeater
        model: 0

        Field {            
            property int itemIndex: index
            property string borderColor: "white"
            property int borderWidth: border.width
            property string fieldImage: fieldImagePath

            width: 57
            color: "#96001850"
            border.color: borderColor
            border.width: borderWidth
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
                    if (borderColor === "white" && fieldImage !== "") {
                        borderColor = "green"
                        borderWidth = 2

                        useItemButton.visible = true
                        useItemButton.currentItem = itemIndex
                    } else if (borderColor === "blue") {
                        dropItemButton.visible = true
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
    }

    MenuButton {
        id: useItemButton
        property int currentItem: 0

        height: 40
        width: 57
        radius: 5
        textB: "Use item"
        textBSize: 16
        textBFamily: "Papyrus"
        visible: false

        MouseArea {
            anchors.fill: parent

            onClicked: {
                inventoryRepeater.itemAt(useItemButton.currentItem).borderColor = "blue"
                useItemButton.visible = false
            }
        }
    }


    MenuButton {
        id: dropItemButton
        property int currentItem: 0

        height: 40
        width: 57
        radius: 5
        textB: "Drop item"
        textBSize: 16
        textBFamily: "Papyrus"
        visible: false

        MouseArea {
            anchors.fill: parent

            onClicked: {
                inventoryRepeater.itemAt(dropItemButton.currentItem).borderColor = "white"
                dropItemButton.visible = false
            }
        }

    }

    Rectangle {
        width: 57
        radius: 5
        height: 10
        color: "#00000000"
    }
}
