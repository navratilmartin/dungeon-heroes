#include "loader.h"

Loader::Loader(){

}

Board* Loader::loadNewGame(EnumDifficulty difficulty) {
    Board* board = new Board(difficulty);
    return board;
}

