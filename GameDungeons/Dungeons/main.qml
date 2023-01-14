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
            id: gameMainMenu
        }

        NewGame {
            id: newGameDifficulty
        }

        SessionBlock {
            id: gameSessionBlock
            visible: false
        }

        Component {
            id: gameFieldComp

            CellField {
                id: gameField
            }
        }

        Component {
            id: fightFieldComp

            Fight {
                id: fightField
            }
        }

        Rectangle {
            id: roomLoaderWrapper
            visible: false
            width: 450
            height: 450
            radius: 5
            anchors.right: parent.right
            anchors.rightMargin: 40
            anchors.verticalCenter: parent.verticalCenter
            border.width: 2
            border.color: "white"
            color: "#00000000"

            Loader {
                id: roomLoader
                property int roomNumber: 0
                active: false
                focus: true
                sourceComponent: gameFieldComp
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter

                onLoaded: {
                    item.anchors.horizontalCenter = roomLoader.horizontalCenter
                    item.anchors.verticalCenter = roomLoader.verticalCenter
                }

            }
        }

        SessionHelp {
            id: gameSessionHelp
            width: 400
            height: 460
            anchors.centerIn: parent
        }
    }
}
