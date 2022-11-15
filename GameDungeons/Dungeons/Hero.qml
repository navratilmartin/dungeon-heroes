import QtQuick 2.15

Rectangle{
    property int positionx:1
    property int positiony:1
    property int dimension: 8
    property int toplimit: 0
    property int rightlimit: 55*dimension
    property int bottomlimit: 55*dimension
    property int leftlimit: 0
    focus:true
    x:15+(positionx-1)*55
    y:15+(positiony-1)*55
    width:20
    height:20
    color:"red"
    radius:60
    Keys.onUpPressed: {
        if(y-55>toplimit){
            y=y-55
        }else{

        }
    }
    Keys.onRightPressed: {
        if(x+55<rightlimit){
            x=x+55
        }else{

        }
    }
    Keys.onDownPressed: {
        if(y+55<bottomlimit){
            y=y+55
        }else{

        }
    }
    Keys.onLeftPressed: {
        if(x-55>leftlimit){
            x=x-55
        }else{

        }
    }
}
