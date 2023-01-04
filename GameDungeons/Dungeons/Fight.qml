import QtQuick 2.15

Rectangle{
    property string enemy : game.enemyName
    color:"black"
    width:600
    height:600
    focus:true
    Rectangle{
       id:healthBar
       height:20
       width:game.board.boardRoom.enemyHealth(game.hero.heroX,game.hero.heroY)
       color:"green"
    }
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
    }
    Image{
            source: "images/frog-mouth-helm.png"
            width: 100
            height: 100
            x:100
            y:250
        }
    Text{
        id:healthBarText
        color:"red"
        text:game.board.boardRoom.enemyHealth(game.hero.heroX,game.hero.heroY)

    }

    Keys.onEnterPressed: {

        healthBarText.text=length(game.board.boardRoom.boardCells[game.hero.heroY][game.hero.heroY])
        healthBar.width=game.board.boardRoom.enemyHealth(game.hero.heroX,game.hero.heroY)

    }

}
