QT += quick

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Board/board.cpp \
        Board/boardcell.cpp \
        Board/boardroom.cpp \
        BoardCellObjects/EnemyFactory/enemyfactory.cpp \
        BoardCellObjects/EnemyFactory/enemyfactoryrobber.cpp \
        BoardCellObjects/EnemyFactory/enemyfactoryshaman.cpp \
        BoardCellObjects/EnemyFactory/enemyfactoryslime.cpp \
        BoardCellObjects/armor.cpp \
        BoardCellObjects/enemy.cpp \
        BoardCellObjects/hero.cpp \
        BoardCellObjects/hideout.cpp \
        BoardCellObjects/item.cpp \
        BoardCellObjects/potion.cpp \
        BoardCellObjects/road.cpp \
        BoardCellObjects/weapon.cpp \
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
    BoardCellObjects/EnemyFactory/enemyfactory.h \
    BoardCellObjects/EnemyFactory/enemyfactoryrobber.h \
    BoardCellObjects/EnemyFactory/enemyfactoryshaman.h \
    BoardCellObjects/EnemyFactory/enemyfactoryslime.h \
    BoardCellObjects/armor.h \
    BoardCellObjects/enemy.h \
    BoardCellObjects/hero.h \
    BoardCellObjects/hideout.h \
    BoardCellObjects/item.h \
    BoardCellObjects/potion.h \
    BoardCellObjects/road.h \
    BoardCellObjects/weapon.h \
    game.h \
    loader.h
