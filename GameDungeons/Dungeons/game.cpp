#include "game.h"

Game::Game() {
    m_loader = new Loader();
    m_board = nullptr;
    m_hero = nullptr;
}

Game::~Game() {
    delete m_loader;
    delete m_board;
    delete m_hero;
}

void Game::createBoard(EnumDifficulty difficulty) {
    m_board = m_loader->loadNewGame(difficulty);
}

void Game::loadBoard() {

}

Hero* Game::getHero() const {
    return m_hero;
}

Board* Game::getBoardMatrix() const {
    return m_board;
}

void Game::play(int userInput) {
    if (userInput != 3) {
        m_hero = new Hero(0, 0, "Nameless", 8);
        createBoard(EnumDifficulty(userInput));
    } else {
        loadBoard();
    }
}


