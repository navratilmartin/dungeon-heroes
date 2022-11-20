import QtQuick 2.15

Grid {
    rows:8
    columns:8
    spacing:5

    Repeater{
        model: game.board

        Repeater {
            model: game.board[index]
            Field {

            }
        }

    }
}
