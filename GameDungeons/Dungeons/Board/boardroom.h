#ifndef BOARDROOM_H
#define BOARDROOM_H

#include "../BoardCellObjects/road.h"
#include "../BoardCellObjects/hideout.h"
#include "../CharacterObjects/hero.h"
#include "../CharacterObjects/EnemyFactory/enemyfactoryrobber.h"
#include "../CharacterObjects/EnemyFactory/enemyfactoryshaman.h"
#include "../CharacterObjects/EnemyFactory/enemyfactoryslime.h"
#include "../CharacterObjects/Items/armor.h"
#include "../CharacterObjects/Items/weapon.h"
#include "../CharacterObjects/Items/potion.h"
#include "EnumDifficulty.h"
#include <vector>
#include <array>
#include <algorithm>
#include <cstdlib>
#include <time.h>
#include <QObject>
#include <random>

const int roomSize = 8;

class BoardRoom : public QObject {
private:
    Q_OBJECT
    Q_PROPERTY(bool bossRoom READ isBossRoom NOTIFY bossRoomChanged)
    Q_PROPERTY (std::vector<std::vector<BoardCell*>> boardCells READ getCells NOTIFY roomChanged)
    int m_size;
    bool m_boss;
    std::vector<std::vector<BoardCell*>> m_room;

    void generateCells(EnumDifficulty difficulty);
public:
    BoardRoom(EnumDifficulty difficulty);
    void addHideout();
    void addEnemy(int type);
    void addItem(int typeOfItem);
    bool isBossRoom() const;
    void setBoss();
    void printCells();

    std::vector<std::vector<BoardCell*>> getCells() const;

signals:
    void bossRoomChanged();
    void roomChanged();
};

Q_DECLARE_METATYPE(std::vector<std::vector<BoardCell*> >)

#endif // BOARDROOM_H
