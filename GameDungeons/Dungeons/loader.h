#ifndef LOADER_H
#define LOADER_H

#include "Board/board.h"

class Loader
{
private:
    void controlFiles();
public:
    Loader();
    Board* loadNewGame(EnumDifficulty difficulty);
    Board* loadSavedGame();
    void saveGame(const Board* currentBoard);
};

#endif // LOADER_H
