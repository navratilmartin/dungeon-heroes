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
        m_hero = new Hero(0, 0, "Nameless",15);
        createBoard(EnumDifficulty(userInput));
    } else {
        loadBoard();
    }
}

bool Game::onEnemy(){
   for(auto pair : m_board->getCurrentRoom()->m_enemies) {
       std::cout<<pair->getName()<<std::endl;
       std::cout<<pair->getX()<<std::endl;
       std::cout<<pair->getY()<<std::endl;
       //i have no idea why the characters coordinates are not consitant
       if((m_hero->getX()==pair->getY())&&(m_hero->getY()==pair->getX())){
           return true;
       }

   }
   return false;
}

QString Game::enemyName(){
        if(m_board->getCurrentRoom()->getCells().at(m_hero->getY()).at(m_hero->getX())!=nullptr){
            return QString::fromStdString(m_board->getCurrentRoom()->getCells().at(m_hero->getY()).at(m_hero->getX())->getCharacter()->getName());

        }
        return QString::fromStdString("Nothing");;
}

