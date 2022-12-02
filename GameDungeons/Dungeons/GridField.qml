import QtQuick 2.15

// Smazat tento soubor pozdeji, asi ho nebudeme potrebovat? Vsechno se da vlozit do CellField

Grid {
    rows:8
    columns:8
    spacing:5

//    Repeater {
//        model: game.board
//        Repeater {
//            id: columnRep
//            property int outerIndex: index
//            model: game.board[outerIndex]

//            Field {
//                Room {
//                    visible: game.board[index][columnRep.outerIndex].emptyRoom
//                }
//            }
//        }

//    }
}
