import QtQuick 2.15

Rectangle{
    property int positionx:1
    property int positiony:1
    height: 20
    width:20
    color:"orange"
    x:15+55*(positionx-1)
    y:15+55*(positiony-1)

}
