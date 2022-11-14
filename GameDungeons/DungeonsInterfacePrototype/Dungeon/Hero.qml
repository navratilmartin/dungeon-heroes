import QtQuick 2.15

Rectangle{
    property int toplimit: 0
    property int rightlimit: 110
    property int bottomlimit: 110
    property int leftlimit: 0
    focus:true
    x:15
    y:15
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
