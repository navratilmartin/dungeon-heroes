import QtQuick 2.15

Rectangle {
    width: 200
    height: 200
    border.width: 2
    border.color: "white"
    radius: 5
    anchors.horizontalCenter: parent.horizontalCenter
    color: "#96001850"

    Column {
        anchors.horizontalCenter: parent.horizontalCenter

        // Below code can be done with ListModel and Repeater
        // However, with ListModel it's quite difficult to edit its properties

        InfoFieldText { text: "Hero"; font.pixelSize: 25 }

        InfoFieldText { text: "Name: "+gameSessionBlock.statsHeroName }

        InfoFieldText { text: "Health: "+gameSessionBlock.statsHeroHealth }

        InfoFieldText { text: "Damage: "+gameSessionBlock.statsHeroDamage }

        InfoFieldText { text: "Armor: "+gameSessionBlock.statsHeroDefense }

        InfoFieldText { text: "Level: "+gameSessionBlock.statsHeroLevel }

        InfoFieldText { text: "Experience: "+gameSessionBlock.statsHeroExperience }
    }
}
