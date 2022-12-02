import QtQuick 2.15

Grid {
    rows:8
    columns:8
    spacing:5

    Repeater {
        id: currentRoom
        model: game.board.boardRoom.boardCells

        Repeater {
            model: currentRoom.model[index]
                Field {
                    Cell {
                                 Image {
                                     source:if(modelData.characterIsNotNull) {
                                             if(modelData.name==="Robber") {
                                                 "images/robber-mask.png"
                                             } else if(modelData.name==="Shaman") {
                                                 "images/tribal-mask.png"
                                             } else if(modelData.name==="Slime") {
                                                 "images/slime.png"
                                             }


                                             } else {
                                                ""
                                             }

                                     width: 30
                                     height: 30
                                     anchors {
                                         centerIn: parent
                                     }

                                }
                    }
                }
        }
    }

    Room {
        id: room
        realPositionx: 8
        realPositiony: 1
        visible: !game.board.boardRoom.bossRoom ? true : false
    }

    Exit {
        id: exit
        visible: roomLoader.roomNumber > 0 ? true : false
    }

    Hero {
        realPositionx: 1
        realPositiony: 1
    }

}
