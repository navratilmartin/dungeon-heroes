import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Dungeons")

    Menu {

    }

    NewGame {
        id: newGameDifficulty
    }

    Component {
        id: gameFieldComp

        CellField {
            id: gameField
        }
    }

    Loader {
        id: roomLoader
        property int roomNumber: 0
        active: false
        focus: true
        sourceComponent: gameFieldComp
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        onLoaded: {
            item.anchors.horizontalCenter = roomLoader.horizontalCenter
            item.anchors.verticalCenter = roomLoader.verticalCenter
        }

    }

}
