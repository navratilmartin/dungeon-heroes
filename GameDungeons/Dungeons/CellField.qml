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

                    }
                }
        }
    }
}
