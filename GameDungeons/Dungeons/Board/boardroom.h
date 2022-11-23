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
#include <random>

const int roomSize = 8;

class BoardRoom : public QObject {
private:
    Q_OBJECT
    Q_PROPERTY(bool emptyRoom READ isEmptyRoom NOTIFY emptyRoomChanged)
    Q_PROPERTY (std::vector<std::vector<BoardCell*>> room READ getRoom NOTIFY roomChanged)
    int m_size;
    bool m_emptyRoom;
    std::vector<std::vector<BoardCell*>> m_room;

    void generateCells(EnumDifficulty difficulty);
public:
    BoardRoom( EnumDifficulty difficulty);
    void addHideout();
    void addEnemy(int type);

    bool isEmptyRoom() const;
    void unsetEmpty();
    void printCells();

    std::vector<std::vector<BoardCell*>> getRoom() const;

signals:
    void emptyRoomChanged();

    void roomChanged();

};

Q_DECLARE_METATYPE(std::vector<std::vector<BoardCell*> >)

#endif // BOARDROOM_H
