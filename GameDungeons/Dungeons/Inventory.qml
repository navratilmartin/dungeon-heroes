import QtQuick 2.15

Grid {
    width: 200
    height: 130
    rows: 2
    columns: 4
    spacing: 7

    Repeater {
        model: 8

        Field {
            width: 57
            border.color: "white"
            border.width: 1
            radius: 5
            color: "#96001850"
            fieldImagePath: ""
        }
    }
}
