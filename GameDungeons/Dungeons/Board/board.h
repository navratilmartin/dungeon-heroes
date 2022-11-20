#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <algorithm>
#include <cmath>

#include "boardroom.h"

const int boardSize = 8; // Initializing here for more transparency, could be initialized in the constructor

class Board
{
private:
    int m_size;
    std::vector<std::vector<BoardRoom*>> m_board;

    void generateRooms(EnumDifficulty difficulty);
    void generateHideouts(EnumDifficulty difficulty);
    void generateEnemies(EnumDifficulty difficulty);
public:
    Board(EnumDifficulty difficulty);

    std::vector<std::vector<BoardRoom*>> getBoard() const;

};

#endif // BOARD_H
