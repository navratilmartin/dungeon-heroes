#include "game.h"

Game::Game() {
    m_loader = new Loader();
    m_board = new Board(EnumDifficulty::Easy);
}

Game::~Game() {
    delete m_loader;
    delete m_board;
}

void Game::createBoard(EnumDifficulty difficulty) {
    m_board = m_loader->loadNewGame(difficulty);
}

void Game::loadBoard() {

}

std::vector<std::vector<BoardRoom*>> Game::getBoardMatrix() const {
    return m_board->getBoard();
}

void Game::play(int userInput) {
    if (userInput != 3) {
        createBoard(EnumDifficulty(userInput));
    } else {
        loadBoard();
    }

    emit boardChanged();
}


