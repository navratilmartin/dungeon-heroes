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

void Game::attackEnemy() {
    m_hero->simpleAttack(m_board->getCurrentRoom()->getBoardCells().at(m_hero->getY()).at(m_hero->getX())->getCharacter());
    m_hero->takeDamage(m_board->getCurrentRoom()->getBoardCells().at(m_hero->getY()).at(m_hero->getX())->getCharacter()->getBaseDamage());
    if(m_board->getCurrentRoom()->getBoardCells().at(m_hero->getY()).at(m_hero->getX())->getCharacter()->getActualHealth()<=0){
        m_board->getCurrentRoom()->getBoardCells().at(m_hero->getY()).at(m_hero->getX())->removeCharacter();
    }
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

QStringList Game::getHelpMessages() const {
    return m_helpMessages;
}

void Game::play(int userInput) {
    if (userInput != 3) {
        m_hero = new Hero(0, 0, "Wanderer", 15);
        createBoard(EnumDifficulty(userInput));
    } else {
        loadBoard();
    }
}

bool Game::onEnemy() {
   if(m_board->getCurrentRoom()->getBoardCells().at(m_hero->getY()).at(m_hero->getX())->getCharacter()!=nullptr){
       return true;
   }

   return false;
}

QString Game::enemyName() {
        if(m_board->getCurrentRoom()->getBoardCells().at(m_hero->getY()).at(m_hero->getX())!=nullptr){
            return QString::fromStdString(m_board->getCurrentRoom()
                                          ->getBoardCells().at(m_hero->getY()).at(m_hero->getX())->getCharacter()->getName());

        }

        return QString::fromStdString("Nothing");
}

