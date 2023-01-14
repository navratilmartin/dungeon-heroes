#include "loader.h"

Loader::Loader(){

}

Board* Loader::loadNewGame(EnumDifficulty difficulty) {
    Board* board = new Board(difficulty);
    return board;
}

void Loader::saveGame(const Board* currentBoard, Hero* hero){
    std::cout << "zde" << std::endl;
    QFile saveFile("../AppData/save.json");
    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file.");
    }
    std::cout << "zde1" << std::endl;
    QJsonObject board;
    //Position
    board["actualRoomIndex"] =  currentBoard->getCurrentRoomIndex();
    board["heroX"] = hero->getX();
    board["heroY"] =  hero->getY();
    //Hero atributes
    board["heroName"] = hero->getQName();
    board["heroHealth"] = hero-> getActualHealth();
    board["heroDamage"] = hero->getBaseDamage();
    board["heroDefense"] = hero->getDefense();
    board["heroLevel"] = hero->getLevel();
    board["heroExperience"] = hero->getExperience();
    //Hero equiped items
    if(hero->getIndexOfEquipedWeaponInInventory() != 0){
        board["indexOfEqupiedWeaponFromInventory"] = hero->getIndexOfEquipedWeaponInInventory();
    }
    if(hero->getIndexOfEquipedArmorInInventory() != 0){
        board["indexOfEqupiedArmorFromInventory"] = hero->getIndexOfEquipedArmorInInventory();
    }
    std::cout << "zde2" << std::endl;
    //Inventory
    QJsonArray weaponArray = {};
    QJsonArray armorArray = {};
    QJsonArray potionArray = {};
    for (auto item: hero->getInventory()){
        if(item==nullptr){
            std::cout << "zdeNull" << std::endl;
        } else{
            std::cout << "zdeX" << std::endl;
            if (item->getItemType() == Item::ItemType::Weapon){
                QJsonObject weaponObj;
                auto weapon = dynamic_cast<Weapon*>(item);
                weaponObj["name"] = weapon->getQStringName();
                weaponObj["description"] = weapon->getQstringDescription();
                weaponObj["damage"] = weapon->getDamageBonus();
                weaponObj["durability"] = weapon->getDurability();
                weaponArray.append(weaponObj);
            } else if (item->getItemType() == Item::ItemType::Armor){
               QJsonObject armorObj;
               auto armor = dynamic_cast<Armor*>(item);
               armorObj["name"] = armor->getQStringName();
               armorObj["description"] = armor->getQstringDescription();
               armorObj["armor"] = armor->getArmorBonus();
               armorObj["durability"] = armor->getDurability();
               armorArray.append(armorObj);
            } else if (item->getItemType() == Item::ItemType::Potion){
                QJsonObject potionObj;
                auto potion = dynamic_cast<Potion*>(item);
                potionObj["name"] = potion->getQStringName();
                potionObj["description"] = potion->getQstringDescription();
                potionObj["bonus"] = potion->getPercentageHealthBonus();
                potionArray.append(potionObj);
            }
        }
    }
    std::cout << "zde3" << std::endl;
    board["inventoryWeapons"] = weaponArray;
    board["inventoryArmors"] = armorArray;
    board["inventoryPotions"] = potionArray;

    //Cells of individual rooms
    /*
    for (auto room:currentBoard->getBoard()){
        for(auto row:room->getBoardCells()){
            auto it=std::find(row.begin(), row.end(), [](){

            });
        }
    }
    */
    QJsonDocument saveDoc(board);
    saveFile.write(saveDoc.toJson());
    std::cout << "zde4" << std::endl;
}

QStringList Loader::loadHelpFile() {
    QStringList fileMessages{};
    QFile inputFile("../AppData/help.txt");


    if (inputFile.open(QIODevice::ReadOnly)) {
        QTextStream in(&inputFile);
        std::string temporary;

        while (!in.atEnd()) {
            QString temporary = in.readLine();
            fileMessages.push_back(temporary);
        }

        inputFile.close();
    } else {
        std::cerr << "File was not found\n";
        fileMessages.push_back("Something went wrong. Perhaps, you deleted AppData folder.");
    }

    return fileMessages;
}
