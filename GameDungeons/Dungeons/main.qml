import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Dungeons")
    Grid{
        rows:2
        spacing:1
        columns:2



    }


    Menu {

    }

    NewGame {
        id: newGameDifficulty
    }


    GridField {
        id: gameField
        visible: false

        Hero {
            id: hero
        }

        Loader {
            id: pageloader
            active: false
            sourceComponent: Window {
                width: 640
                height: 480
                visible: true

                // onClosing: winld.active = false
                CellField {
                    Hero {
                        onXChanged: function() {
                            if(x===exit.x && y===exit.y) {
                                hero.enteredRoom=false
                                pageloader.active=false
                                root.visible=true
                            }
                        }

                        onYChanged: function() {
                            if(x===exit.x && y===exit.y) {
                                hero.enteredRoom=false
                                pageloader.active=false
                                root.visible=true
                            }
                        }
                    }

                    Exit {
                        id: exit
                        positionx: 8
                        positiony: 1
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
