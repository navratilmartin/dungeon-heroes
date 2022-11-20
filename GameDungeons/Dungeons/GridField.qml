import QtQuick 2.15

Grid {
    rows:8
    columns:8
    spacing:5

    Repeater {
        model: game.board
        Repeater {
            id: columnRep
            property int outerIndex: index
            model: game.board[outerIndex]

            Field {
                Room {
                    visible: game.board[index][columnRep.outerIndex].emptyRoom
                }
            }
        }

    }
}
