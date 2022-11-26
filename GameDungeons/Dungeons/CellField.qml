import QtQuick 2.15

Grid {
    rows:8
    columns:8
    spacing:5

    Repeater {
        model: game.board[hero.logicalPositionx][hero.logicalPositiony].room // returns matrix of cells

        Repeater {
            model: game.board[hero.logicalPositionx][hero.logicalPositiony].room[index]
                Field {
                    Cell {

                                 Image{
                                     source:if(modelData.characterIsNotNull){
                                             if(modelData.name==="Robber"){
                                                 "images/robber-mask.png"
                                             }else if(modelData.name==="Shaman"){
                                                 "images/tribal-mask.png"
                                             }else if(modelData.name==="Slime"){
                                                 "images/slime.png"
                                             }


                                          }else{
                                                " "
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

}
