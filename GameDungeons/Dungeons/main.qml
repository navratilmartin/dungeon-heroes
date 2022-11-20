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


    GridField {
        id: gameField
        visible: false

        Hero {
            onXChanged: function() {
                if(x===room.x && y===room.y){
                    pageloader.active=true
                }
            }
            onYChanged: function() {
                if(x===room.x && y===room.y) {
                    pageloader.active=true
                }
            }
        }

        Room {
            id:room
            positionx:4
            positiony:4
        }

        Loader {
            id:pageloader
            active:false
            sourceComponent: Window {
                width: 640
                height: 480
                visible: true
                onClosing: winld.active = false
                GridField {
                    Hero {
                        onXChanged: function() {
                            if(x===exit.x && y===exit.y){
                                pageloader.active=false
                            }
                        }
                        onYChanged: function() {
                            if(x===exit.x && y===exit.y){
                                pageloader.active=false
                            }
                        }
                    }
                    Exit {
                        id:exit
                        positionx: 3
                        positiony: 3
                    }
                    anchors {
                        horizontalCenter: parent.horizontalCenter
                        verticalCenter: parent.verticalCenter
                    }
                }
            }
        }

        anchors {
            horizontalCenter: parent.horizontalCenter
            verticalCenter: parent.verticalCenter
        }
    }
}
