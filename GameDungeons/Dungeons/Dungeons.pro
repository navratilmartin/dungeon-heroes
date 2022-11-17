QT += quick

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Board/board.cpp \
        Board/boardcell.cpp \
        Board/boardroom.cpp \
        Board/character.cpp \
        Board/item.cpp \
        CharacterObjects/EnemyFactory/enemyfactory.cpp \
        CharacterObjects/EnemyFactory/enemyfactoryrobber.cpp \
        CharacterObjects/EnemyFactory/enemyfactoryshaman.cpp \
        CharacterObjects/EnemyFactory/enemyfactoryslime.cpp \
        CharacterObjects/Items/armor.cpp \
        CharacterObjects/enemy.cpp \
        CharacterObjects/hero.cpp \
        BoardCellObjects/hideout.cpp \
        CharacterObjects/Items/potion.cpp \
        BoardCellObjects/road.cpp \
        CharacterObjects/Items/weapon.cpp \
        game.cpp \
        loader.cpp \
        main.cpp

RESOURCES += qml.qrc

RC_ICONS = images/Papirus-Team-dungeon.ico

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Board/EnumDifficulty.h \
    Board/board.h \
    Board/boardcell.h \
    Board/boardroom.h \
    Board/character.h \
    Board/item.h \
    CharacterObjects/EnemyFactory/enemyfactory.h \
    CharacterObjects/EnemyFactory/enemyfactoryrobber.h \
    CharacterObjects/EnemyFactory/enemyfactoryshaman.h \
    CharacterObjects/ItemsEnemyFactory/enemyfactoryslime.h \
    CharacterObjects/Items/armor.h \
    CharacterObjects/enemy.h \
    CharacterObjects/hero.h \
    BoardCellObjects/hideout.h \
    CharacterObjects/Items/potion.h \
    BoardCellObjects/road.h \
    CharacterObjects/Items/weapon.h \
    game.h \
    loader.h
