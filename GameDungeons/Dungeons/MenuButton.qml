import QtQuick 2.15

Rectangle {
    property alias textB: textButton.text
    width: 100
    height: 40

    Text {
        id: textButton
        text: "Menu Button"

        anchors {
            centerIn: parent
        }
    }
}
