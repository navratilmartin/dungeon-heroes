#include "boardroom.h"

BoardRoom::BoardRoom(EnumDifficulty difficulty)
{
    m_size = roomSize;
    m_room = std::vector<std::vector<BoardCell*>> (roomSize, std::vector<BoardCell*> (roomSize));
    generateCells(difficulty);
    addEnemy(1);
    addEnemy(2);
    addEnemy(3);
    m_emptyRoom = false;
}

void BoardRoom::generateCells(EnumDifficulty difficulty) {  // Misto generate algorithmu for cykly - potrebuju
    for(int height=0; height<roomSize; height++) {          // x a y souradnice do konstruktoru Roads.
        for(int width=0; width<roomSize; width++) {
            m_room.at(height).at(width) = new Road(height, width);
        }
    }
}

void BoardRoom::addHideout() {
    int randx = rand()%(roomSize*roomSize);
    int x = randx / roomSize;
    if(x == 0){     // First row is empty
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
    if(x == 0){     // First row is empty
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

void BoardRoom::addItem(int typeOfItem){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, roomSize-1);
    std::uniform_int_distribution<int> ite(1, 3);
    std::uniform_int_distribution<int> pot(3, 10);
    std::uniform_int_distribution<int> arm(5, 20);
    std::uniform_int_distribution<int> dmg(5, 30);
    int x = dis(gen);
    if(x == 0){     // First row is empty
        x++;
    }
    int y = dis(gen);
    while(m_room.at(x).at(y)->getItem() != nullptr){
        x = (x+1)%8;
    }
    if(typeOfItem == 1){
        int weaponBonus = dmg(gen);
        std::string weaponName;
        if(weaponBonus >22){
            weaponName = "Sword";
        }
        else if(weaponBonus > 12){
            weaponName = "Axe";
        }
        else{
            weaponName = "Dagger";
        }
        Weapon* w = new Weapon(weaponBonus, weaponName,
                               "Deals " + std::to_string(weaponBonus) + " to the enemy.", x, y);
        m_room.at(x).at(y)->addItem(w);
    }
    else if(typeOfItem == 2){
        int armorBonus = arm(gen);
        Armor* a = new Armor(armorBonus, "Armor",
                             "Decreases the incoming damage from the enemy by " + std::to_string(armorBonus) + ".", x, y);
        m_room.at(x).at(y)->addItem(a);
    }
    else{
        int potionBonus = pot(gen);
        Potion* p = new Potion(potionBonus, "Potion",
                               "Regenerates " + std::to_string(potionBonus) + " hp.", x, y);
        m_room.at(x).at(y)->addItem(p);
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
    for(int i =0;i<m_room.size();i++){
        for(int j=0;j<m_room[i].size();j++){


        }
    }
    return m_room;
}

void BoardRoom::printCells(){
    for(int i=0; i<roomSize; i++){
        for(int j=0; j<roomSize; j++){
            if(m_room.at(i).at(j) ->getCharacter() != nullptr){
                std::cout << "Ch " << m_room.at(i).at(j)->getX() << m_room.at(i).at(j)->getY() << std::endl;
            }
            if(m_room.at(i).at(j) ->getItem() != nullptr){
                std::cout << "I " << m_room.at(i).at(j)->getX() << m_room.at(i).at(j)->getY() <<
                          m_room.at(i).at(j)->getItem()->getName() << std::endl;
            }
        }
    }
}
