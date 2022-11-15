import QtQuick 2.15

Grid{
    rows:2
    columns:2
    spacing:5
    Repeater{
        model: game.fields //Q_PROPERTY, vyslu signal fieldsChanged
        Field{

        }

    }
}
