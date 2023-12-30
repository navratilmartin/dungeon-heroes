#ifndef ROAD_H
#define ROAD_H

#include "../Board/boardcell.h"

class Road: public BoardCell {
public:
    Road(int x, int y, Character*ch = nullptr, Item* i = nullptr);
};

#endif // ROAD_H
