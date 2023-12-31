#include "game.h"

Game::Game() {
    m_loader = new Loader();
    m_board = nullptr;
    m_hero = nullptr;
    m_helpMessages = m_loader->loadHelpFile();
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
    m_board = m_loader->loadSavedGame();
    m_hero = m_loader->loadSavedHero();
}

Hero* Game::getHero() const {
    return m_hero;
}

Board* Game::getBoardMatrix() const {
    return m_board;
}

QStringList Game::getHelpMessages() const {
    return m_helpMessages;
}

void Game::play(int userInput) {
    if (userInput != 3) {
        m_hero = new Hero(0, 0, "Wanderer", 10);
        createBoard(EnumDifficulty(userInput));
    } else {
        loadBoard();
    }
}

void Game::saveGame() {
    m_loader->saveGame(m_board, m_hero);
}

