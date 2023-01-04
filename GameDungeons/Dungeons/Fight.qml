import QtQuick 2.15

Rectangle{
    property string enemy : game.enemyName
    color:"black"
    width:600
    height:600
    focus:true


    Image{
        source: if(enemy == "Robber"){
                    "images/robber-mask.png"
                }else if(enemy == "Slime"){
                    "images/slime.png"
                }else if(enemy == "Shaman"){
                    "images/tribal-mask.png"
                }else{
                    ""
                }

        width: 100
        height: 100
        anchors.centerIn: parent
        x:600
        y:250
        Rectangle{
           id:healthBar
           height:20
           width:game.board.boardRoom.enemyHealth(game.hero.heroX,game.hero.heroY)
           color:"green"

           Text{
               id:healthBarText
               color:"red"
               text:game.board.boardRoom.enemyHealth(game.hero.heroX,game.hero.heroY)

           }
        }
    }
    Image{
            source: "images/frog-mouth-helm.png"
            width: 100
            height: 100
            x:100
            y:250
        }


    Keys.onDeletePressed:{
        game.attackEnemy()
        if(game.board.boardRoom.enemyHealth(game.hero.heroX,game.hero.heroY)>0){
            healthBarText.text=game.board.boardRoom.enemyHealth(game.hero.heroX,game.hero.heroY)
            healthBar.width=game.board.boardRoom.enemyHealth(game.hero.heroX,game.hero.heroY)
        }else{
            roomLoader.source=""
            roomLoader.source="CellField.qml"
        }


    }

}
