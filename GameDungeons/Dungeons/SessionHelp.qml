import QtQuick 2.15

Rectangle {
    border.width: 2
    border.color: "white"
    radius: 5
    color: "black"
    visible: false

    InfoFieldText {
        text: "Help"
        font.pixelSize: 30
    }

    Rectangle {
        width: 30
        height: 30
        color: "#00000000"
        anchors.right: parent.right

        Text {
            text: "X"
            color: "white"
            font.pixelSize: 15
            font.bold: true
            anchors.centerIn: parent

            MouseArea {
                anchors.fill: parent

                onClicked: {
                    gameSessionHelp.visible = false
                    gameSessionBlock.visible = true
                    roomLoaderWrapper.visible = true
                    roomLoader.visible = true
                }
            }
        }
    }

    Column {
        spacing: 5
        width: parent.width
        height: 350
        anchors.verticalCenter: parent.verticalCenter

        Repeater {
            model: game.helpMessages

            Rectangle {
                 width: 300
                 height: 20
                 color: "#00000000"
                 anchors.horizontalCenter: parent.horizontalCenter

                InfoFieldText {
                    text: qsTr(modelData)
                    font.pixelSize: 14
                    anchors.centerIn: parent
                }

            }
        }
    }
}
