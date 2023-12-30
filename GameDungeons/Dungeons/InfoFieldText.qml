import QtQuick 2.15

Text {
    id: infoFieldText
    text: ""
    font.family: "Papyrus"
    font.pixelSize: 15
    color: "white"
    anchors.horizontalCenter: parent.horizontalCenter
    font.bold: true

    states: [
        State {
            when: infoFieldText.visible
            PropertyChanges {
                target: infoFieldText
                opacity: 1.0
            }
        },

        State {
            when: !infoFieldText.visible
            PropertyChanges {
                target: infoFieldText
                opacity: 0.0
            }
        }

    ]

    transitions: [
        Transition {
            NumberAnimation {
                property: "opacity"
                duration: 300
            }
        }

    ]
}
