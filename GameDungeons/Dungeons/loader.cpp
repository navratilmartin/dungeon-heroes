#include "loader.h"

Loader::Loader(){

}

Board* Loader::laodNewGame(EnumDifficulty difficulty) {
    Board* board = new Board(difficulty);
    return board;
}

