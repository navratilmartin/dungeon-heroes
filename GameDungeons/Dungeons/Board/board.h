#ifndef BOARD_H
#define BOARD_H

#include <iostream>

#include "boardroom.h"

const int boardSize = 8;

class Board
{
private:
    int m_size;
    std::vector<std::vector<BoardRoom*>> m_board;

    void generateRooms(EnumDifficulty difficulty);
public:
    Board(EnumDifficulty difficulty);

};

#endif // BOARD_H
