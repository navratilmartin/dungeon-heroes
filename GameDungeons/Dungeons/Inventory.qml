import QtQuick 2.15

Grid {
    property alias inventoryModel: inventoryRepeater.model

    width: 200
    height: 130
    rows: 2
    columns: 4
    spacing: 7

    Repeater {
        id: inventoryRepeater
        model: 0

        Field {
            property int itemIndex: index
            width: 57
            border.color: "white"
            border.width: 1
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
        }
    }
}
