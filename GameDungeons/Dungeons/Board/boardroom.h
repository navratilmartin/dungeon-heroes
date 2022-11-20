#ifndef BOARDROOM_H
#define BOARDROOM_H

#include "boardcell.h"
#include "EnumDifficulty.h"
#include <vector>
#include <QObject>

const int roomSize = 8;

class BoardRoom : public QObject {
private:
    Q_OBJECT
    int m_size;
    std::vector<std::vector<BoardCell*>> m_rooms;

    void generateCells(EnumDifficulty difficulty);
public:
    BoardRoom(EnumDifficulty difficulty);

};

#endif // BOARDROOM_H
