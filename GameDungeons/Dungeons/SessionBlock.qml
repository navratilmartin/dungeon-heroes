import QtQuick 2.15

Column {
    property alias gameInventory: gameInventoryElement

    // properties for hero's stats, then included in InfoField
    property string statsHeroName: "Hero"
    property int statsHeroHealth: 100
    property int statsHeroDamage: 0
    property int statsHeroDefense: 0
    property int statsHeroLevel: 1
    property int statsHeroExperience: 0

    property bool weaponMessageVisible: false
    property alias weaponMessageRunning: weaponMessageTimer

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
            id: weaponInfoMessage

            visible: weaponMessageVisible
            text: "You can't equip more than one weapon or armor!"
            font.pixelSize: 12
        }

        Timer {
            id: weaponMessageTimer
            interval: 5000
            onTriggered: weaponInfoMessage.visible = false
            running: false
        }
    }

    MenuButton {
        height: 15
        textB: "Menu"
        textBSize: 18
        anchors.horizontalCenter: parent.horizontalCenter
    }
}
