import QtQuick 2.15

Column {
    property alias gameInventory: gameInventoryElement

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
    }

    MenuButton {
        height: 15
        textB: "Menu"
        textBSize: 18
        textBFamily: "Papyrus"
        anchors.horizontalCenter: parent.horizontalCenter
    }
}
