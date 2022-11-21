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
    int y = randx % roomSize;
    m_room.at(x).at(y) = new Hideout(x, y, 15);
}

void BoardRoom::addEnemy(int type) {
    int randx = rand()%(roomSize*roomSize);
    int x = randx / roomSize;
    int y = randx % roomSize;
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
