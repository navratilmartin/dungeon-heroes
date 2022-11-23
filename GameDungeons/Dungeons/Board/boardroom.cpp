#include "boardroom.h"

BoardRoom::BoardRoom(EnumDifficulty difficulty)
{
    m_size = roomSize;
    m_room = std::vector<std::vector<BoardCell*>> (roomSize, std::vector<BoardCell*> (roomSize));
    generateCells(difficulty);
    m_emptyRoom = false;
}

void BoardRoom::generateCells(EnumDifficulty difficulty) {  // Misto generate algorithmu for cykly - potrebuju
    for(int height=0; height<roomSize; height++) {          // x a y souradnice do konstruktoru Roads.
        for(int width=0; width<roomSize; width++) {
            m_room.at(height).at(width) = new Road(height, width);
            std::cout << height << width;
        }
        std::cout << std::endl;
    }
}

void BoardRoom::addHideout() {
    int randx = rand()%(roomSize*roomSize);
    int x = randx / roomSize;
    if(x == 0){
        x++;
    }
    int y = randx % roomSize;
    m_room.at(x).at(y) = new Hideout(x, y, 15);
}

void BoardRoom::addEnemy(int type) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, roomSize-1);
    int x = dis(gen);
    if(x == 0){
        x++;
    }
    int y = dis(gen);
    while(m_room.at(x).at(y)->getCharacter() != nullptr){
        x = (x+1)%8;
    }
    if(type == 1){
        EnemyFactory* ef = new EnemyFactoryRobber();
        m_room.at(x).at(y)->addCharacter(ef->getEnemy(x, y));
    } else if(type == 2){
        EnemyFactory* ef = new EnemyFactorySlime();
        m_room.at(x).at(y)->addCharacter(ef->getEnemy(x, y));
    } else {
        EnemyFactory* ef = new EnemyFactoryShaman();
        m_room.at(x).at(y)->addCharacter(ef->getEnemy(x, y));
    }
}

bool BoardRoom::isEmptyRoom() const {
    return m_emptyRoom;
}

void BoardRoom::unsetEmpty() {
    m_emptyRoom = true;

    emit emptyRoomChanged();
    emit roomChanged();
}

std::vector<std::vector<BoardCell*>> BoardRoom::getRoom() const {
    return m_room;
}

void BoardRoom::printCells(){
    for(int i=0; i<roomSize; i++){
        for(int j=0; j<roomSize; j++){
            if(m_room.at(i).at(j) ->getCharacter() != nullptr){
                std::cout << m_room.at(i).at(j)->getX() << m_room.at(i).at(j)->getY() << std::endl;
            }
        }
    }
}
