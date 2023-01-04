import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    id: root
    color: "black"
    width: 640
    height: 480
    visible: true
    visibility: Window.Maximized
    title: qsTr("Dungeons")

    Rectangle {
        id: gameMain
        color: "black"
        anchors.fill: parent
        // border.width: 1
        // border.color: "white"

        Text {
            id: gameTitle
            text: "Dungeons"
            font.family: "Papyrus"
            color: "white"
            font.pixelSize: 40
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.topMargin: 40
        }

        Menu {

        }

        NewGame {
            id: newGameDifficulty
        }

        Column {
            id: gameSessionBlock
            spacing: 25
            anchors.verticalCenter: parent.verticalCenter
            padding: 15
            visible: false

            InfoField {
                width: 250
                height: 200
            }

            Inventory {

            }

            MenuButton {
                height: 20
                textB: "Help"
                textBSize: 18
                textBFamily: "Papyrus"
                anchors.horizontalCenter: parent.horizontalCenter
            }

            MenuButton {
                height: 20
                textB: "Menu"
                textBSize: 18
                textBFamily: "Papyrus"
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }

        Component {
            id: gameFieldComp

            CellField {
                id: gameField
            }
        }
        Component {
            id: fightFieldComp

            Fight{
                id: fightField
            }
        }

        Loader {
            id: roomLoader
            property int roomNumber: 0
            active: false
            focus: true
            sourceComponent: gameFieldComp
            anchors.right: parent.right
            anchors.rightMargin: 40
            anchors.verticalCenter: parent.verticalCenter

            onLoaded: {
                item.anchors.horizontalCenter = roomLoader.horizontalCenter
                item.anchors.verticalCenter = roomLoader.verticalCenter
            }

        }
        Loader {
            id: fightLoader
            property string enemy : ""
            active: false
            focus:false
            sourceComponent: fightFieldComp

            anchors.right: parent.right
            anchors.rightMargin: 40
            anchors.verticalCenter: parent.verticalCenter
            onLoaded: {
                item.anchors.horizontalCenter = fightLoader.horizontalCenter
                item.anchors.verticalCenter = fightLoader.verticalCenter
            }

        }
    }
}
