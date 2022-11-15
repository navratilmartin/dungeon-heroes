import QtQuick 2.15

Grid{
    rows:8
    columns:8
    spacing:5
    Repeater{
        model: 64 //Q_PROPERTY, vyslu signal fieldsChanged
        Field{

        }

    }
}
