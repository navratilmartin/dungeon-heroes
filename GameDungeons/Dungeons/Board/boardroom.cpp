#include "boardroom.h"

BoardRoom::BoardRoom(EnumDifficulty difficulty) {
    m_size = roomSize;
    m_room = std::vector<std::vector<BoardCell*>> (roomSize, std::vector<BoardCell*> (roomSize));
    generateCells(difficulty);
    m_boss = false;
    m_oneBoardCell = m_room.at(0).at(0);
}

void BoardRoom::generateCells(EnumDifficulty difficulty) {
    for (int height=0; height < roomSize; height++) {
        for (int width=0; width < roomSize; width++) {
            m_room.at(height).at(width) = new Road(height, width);
        }
    }
}

void BoardRoom::addHideout() {
    int randx = rand()%(roomSize*roomSize);
    int x = randx / roomSize;
    if (x == 0) {     // First row is empty
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

    if (x == 0) {     // First row is empty
        x++;
    }

    int y = dis(gen);

    while (m_room.at(x).at(y)->getCharacter() != nullptr){
        x = (x+1)%8;
    }

    if (type == 1) {
        EnemyFactory* ef = new EnemyFactoryRobber();

        m_room.at(x).at(y)->addCharacter(ef->getEnemy(x,y));

    } else if (type == 2) {
        EnemyFactory* ef = new EnemyFactorySlime();

        m_room.at(x).at(y)->addCharacter(ef->getEnemy(x,y));

    } else {
        EnemyFactory* ef = new EnemyFactoryShaman();

        m_room.at(x).at(y)->addCharacter(ef->getEnemy(x,y));

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

    while (m_room.at(x).at(y)->getItem() != nullptr) {
        x = (x+1)%8;
    }

    if (typeOfItem == 1) {
        int weaponBonus = dmg(gen);
        std::string weaponName;

        if (weaponBonus > 22) {
            weaponName = "Sword";
        }

        else if (weaponBonus > 12) {
            weaponName = "Axe";
        }

        else {
            weaponName = "Dagger";
        }

        Weapon* w = new Weapon(weaponBonus, weaponName,
                               "Deals " + std::to_string(weaponBonus) + " to the enemy.", x, y);
        m_room.at(x).at(y)->addItem(w);

    } else if (typeOfItem == 2) {
        int armorBonus = arm(gen);
        Armor* a = new Armor(armorBonus, "Armor",
                             "Decreases the incoming damage from the enemy by " + std::to_string(armorBonus) + ".", x, y);
        m_room.at(x).at(y)->addItem(a);

    } else {
        int potionBonus = pot(gen);
        Potion* p = new Potion(potionBonus, "Potion",
                               "Regenerates " + std::to_string(potionBonus) + " hp.", x, y);
        m_room.at(x).at(y)->addItem(p);
    }

}

bool BoardRoom::isBossRoom() const {
    return m_boss;
}

void BoardRoom::setBoss() {
    m_boss = true;

    emit bossRoomChanged();
}

void BoardRoom::extractOneBoardCell(int x, int y) {
    m_oneBoardCell = m_room.at(x).at(y);
    emit boardCellChanged();
}

std::vector<std::vector<BoardCell*>> BoardRoom::getBoardCells() const {
    return m_room;
}

BoardCell* BoardRoom::getOneBoardCell() const {
    return m_oneBoardCell;
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
