#ifndef BOARDROOM_H
#define BOARDROOM_H

#include "../BoardCellObjects/road.h"
#include "../BoardCellObjects/hideout.h"
#include "../CharacterObjects/hero.h"
#include "../CharacterObjects/EnemyFactory/enemyfactoryrobber.h"
#include "../CharacterObjects/EnemyFactory/enemyfactoryshaman.h"
#include "../CharacterObjects/EnemyFactory/enemyfactoryslime.h"
#include "EnumDifficulty.h"
#include <vector>
#include <array>
#include <algorithm>
#include <cstdlib>
#include <time.h>
#include <QObject>

const int roomSize = 8;

class BoardRoom : public QObject {
private:
    Q_OBJECT
    int m_size;
    std::vector<std::vector<BoardCell*>> m_room;

    void generateCells(EnumDifficulty difficulty);
public:
    BoardRoom( EnumDifficulty difficulty);
    void addHideout();
    void addEnemy(int type);

};

#endif // BOARDROOM_H
