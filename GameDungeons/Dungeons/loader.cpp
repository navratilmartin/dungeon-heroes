#include "loader.h"

Loader::Loader(){

}

Board* Loader::loadNewGame(EnumDifficulty difficulty) {
    Board* board = new Board(difficulty);
    return board;
}

void Loader::saveGame(const Board* currentBoard, Hero* hero){
    QFile saveFile("../AppData/save.json");
    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file.");
    } else {
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
        board["numberOfKilledShamans"] = hero->getNumberOfKilledShamans();
        //Hero equiped items

        //Inventory
        QJsonArray weaponArray = {};
        QJsonArray armorArray = {};
        QJsonArray potionArray = {};
        for (auto item: hero->getInventory()){
            if(item!=nullptr){
                if (item->getItemType() == Item::ItemType::Weapon){
                    QJsonObject weaponObj;
                    auto weapon = qobject_cast<Weapon*>(item);
                    weaponObj["name"] = weapon->getQStringName();
                    weaponObj["description"] = weapon->getQstringDescription();
                    weaponObj["damage"] = weapon->getDamageBonus();
                    weaponObj["durability"] = weapon->getDurability();
                    if(weapon->isEquiped()){
                        weaponObj["equiped"] = 1;
                    } else {
                        weaponObj["equiped"] = 0;
                    }
                    weaponArray.append(weaponObj);
                } else if (item->getItemType() == Item::ItemType::Armor){
                   QJsonObject armorObj;
                   auto armor = qobject_cast<Armor*>(item);
                   armorObj["name"] = armor->getQStringName();
                   armorObj["description"] = armor->getQstringDescription();
                   armorObj["armor"] = armor->getArmorBonus();
                   armorObj["durability"] = armor->getDurability();
                   if(armor->isEquiped()){
                       armorObj["equiped"] = 1;
                   } else{
                       armorObj["equiped"] = 0;
                   }
                   armorArray.append(armorObj);
                } else if (item->getItemType() == Item::ItemType::Potion){
                    QJsonObject potionObj;
                    auto potion = qobject_cast<Potion*>(item);
                    potionObj["name"] = potion->getQStringName();
                    potionObj["description"] = potion->getQstringDescription();
                    potionObj["bonus"] = potion->getPercentageHealthBonus();
                    potionArray.append(potionObj);
                }
            }
        }
        board["inventoryWeapons"] = weaponArray;
        board["inventoryArmors"] = armorArray;
        board["inventoryPotions"] = potionArray;

        //Cells of individual rooms
        QJsonArray enemyArray = {};
        QJsonArray boardWeaponArray = {};
        QJsonArray boardArmorArray = {};
        QJsonArray boardPotionArray = {};
        for(int roomIndex=0; roomIndex<currentBoard->getSize(); roomIndex++){
            BoardRoom* room=currentBoard->getRoom(roomIndex);
            for(auto row:room->getBoardCells()){
                std::for_each(row.begin(), row.end(), [&boardWeaponArray, &boardArmorArray, &boardPotionArray, &enemyArray, &roomIndex](BoardCell* b){
                    if(b->characterIsNotNull()){
                        auto enemy = qobject_cast<Enemy*>(b->getCharacter());
                        QJsonObject enemyObj;
                        enemyObj["x"] = enemy->getX();
                        enemyObj["y"] = enemy->getY();
                        enemyObj["roomIndex"] = roomIndex;
                        enemyObj["name"] = enemy->getQName();
                        enemyObj["defense"] = enemy->getDefense();
                        enemyObj["attack"] = enemy->getBaseDamage();
                        enemyObj["xp"] = enemy->getExperienceBonus();
                        enemyArray.append(enemyObj);
                    }
                    if(b->itemIsNotNull()){
                        if (b->getItem()->getItemType() == Item::ItemType::Weapon){
                            QJsonObject weaponObj;
                            auto weapon = qobject_cast<Weapon*>(b->getItem());
                            weaponObj["x"] = weapon->getX();
                            weaponObj["y"] = weapon->getY();
                            weaponObj["roomIndex"] = roomIndex;
                            weaponObj["name"] = weapon->getQStringName();
                            weaponObj["description"] = weapon->getQstringDescription();
                            weaponObj["damage"] = weapon->getDamageBonus();
                            weaponObj["durability"] = weapon->getDurability();
                            boardWeaponArray.append(weaponObj);
                        } else if (b->getItem()->getItemType() == Item::ItemType::Armor){
                           QJsonObject armorObj;
                           auto armor = qobject_cast<Armor*>(b->getItem());
                           armorObj["x"] = armor->getX();
                           armorObj["y"] = armor->getY();
                           armorObj["roomIndex"] = roomIndex;
                           armorObj["name"] = armor->getQStringName();
                           armorObj["description"] = armor->getQstringDescription();
                           armorObj["armor"] = armor->getArmorBonus();
                           armorObj["durability"] = armor->getDurability();
                           boardArmorArray.append(armorObj);
                        } else if (b->getItem()->getItemType() == Item::ItemType::Potion){
                            QJsonObject potionObj;
                            auto potion = qobject_cast<Potion*>(b->getItem());
                            potionObj["x"] =  potion->getX();
                            potionObj["y"] = potion->getY();
                            potionObj["roomIndex"] = roomIndex;
                            potionObj["name"] = potion->getQStringName();
                            potionObj["description"] = potion->getQstringDescription();
                            potionObj["bonus"] = potion->getPercentageHealthBonus();
                            boardPotionArray.append(potionObj);
                        }
                    }
                });
            }
            board["boardWeapons"] = boardWeaponArray;
            board["boardArmors"] = boardArmorArray;
            board["boardPotions"] = boardPotionArray;
            board["enemies"] = enemyArray;
        }

        QJsonDocument saveDoc(board);
        saveFile.write(saveDoc.toJson());
    }
}

Board* Loader::loadSavedGame(){
     QFile loadFile("../AppData/save.json");
     if (!loadFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open save file.");
        throw std::invalid_argument("Nepodarilo se otevrit soubor v laodSavedGame");
      }
     else {
        QByteArray saveData = loadFile.readAll();
        QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));
        QJsonObject board = loadDoc.object();
        int roomIndex = board["actualRoomIndex"].toInt();
        Board* loadedBoard = new Board(EnumDifficulty::Easy, roomIndex);
        loadedBoard->generateLoadedRooms(board["numberOfKilledShamans"].toInt());
        QJsonArray boardWeapons = board["boardWeapons"].toArray();
        QJsonArray boardArmors = board["boardArmors"].toArray();
        QJsonArray boardPotions = board["boardPotions"].toArray();
        QJsonArray enemies = board["enemies"].toArray();
        for(int index=0; index<boardWeapons.size(); index++){
            QJsonObject boardWeaponObj = boardWeapons.at(index).toObject();
            int x = boardWeaponObj["x"].toInt();
            int y = boardWeaponObj["y"].toInt();
            int roomIndex = boardWeaponObj["roomIndex"].toInt();
            int damage = boardWeaponObj["damage"].toInt();
            std::string name = boardWeaponObj["name"].toString().toStdString();
            std::string description = boardWeaponObj["description"].toString().toStdString();
            int durability = boardWeaponObj["durability"].toInt();
            Weapon* w = new Weapon(damage, name, description, x, y, durability);
            loadedBoard->addItem(roomIndex, x, y, w);
        }
        for(int index=0; index<boardArmors.size(); index++){
            QJsonObject boardArmorObj = boardArmors.at(index).toObject();
            int x = boardArmorObj["x"].toInt();
            int y = boardArmorObj["y"].toInt();
            int roomIndex = boardArmorObj["roomIndex"].toInt();
            int armor = boardArmorObj["armor"].toInt();
            std::string name = boardArmorObj["name"].toString().toStdString();
            std::string description = boardArmorObj["description"].toString().toStdString();
            int durability = boardArmorObj["durability"].toInt();
            Armor* a = new Armor(armor, name, description, x, y, durability);
            loadedBoard->addItem(roomIndex, x, y, a);
        }
        for(int index=0; index<boardPotions.size(); index++){
            QJsonObject boardPotionObj = boardPotions.at(index).toObject();
            int x = boardPotionObj["x"].toInt();
            int y = boardPotionObj["y"].toInt();
            int roomIndex = boardPotionObj["roomIndex"].toInt();
            int bonus = boardPotionObj["bonus"].toInt();
            std::string name = boardPotionObj["name"].toString().toStdString();
            std::string description = boardPotionObj["description"].toString().toStdString();
            Potion* p = new Potion(bonus, name, description, x, y);
            loadedBoard->addItem(roomIndex, x, y, p);
        }
        for(int index=0; index<enemies.size(); index++){
            QJsonObject enemyObj = enemies.at(index).toObject();
            int x = enemyObj["x"].toInt();
            int y = enemyObj["y"].toInt();
            int roomIndex = enemyObj["roomIndex"].toInt();
            int attack = enemyObj["attack"].toInt();
            std::string name = enemyObj["name"].toString().toStdString();
            int xp = enemyObj["xp"].toInt();
            int defense = enemyObj["defense"].toInt();
            Enemy* e = new Enemy(x, y, name, attack, defense, xp);
            loadedBoard->addEnemy(roomIndex, x, y, e);
        }

        return loadedBoard;
     }
}

Hero* Loader::loadSavedHero(){
    QFile loadFile("../AppData/save.json");
    if (!loadFile.open(QIODevice::ReadOnly)) {
       qWarning("Couldn't open save file.");
       throw std::invalid_argument("Nepodarilo se otevrit soubor v loadSavedHero");
     }
    else{
        Weapon* equipedWeapon = nullptr;
        Armor* equipedArmor = nullptr;
        QByteArray saveData = loadFile.readAll();
        QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));
        QJsonObject board = loadDoc.object();
        int x = board["heroX"].toInt();
        int y = board["heroY"].toInt();
        std::string name = board["heroName"].toString().toStdString();
        int health = board["heroHealth"].toInt();
        int baseDamage = board["heroDamage"].toInt();
        int defense = board["heroDefense"].toInt();
        int level = board["heroLevel"].toInt();
        int experience = board["heroExperience"].toInt();
        int numberOfKilledShamans = board["numberOfKilledShamans"].toInt();
        std::vector<Item*> inventory = {8, nullptr};
        int inventoryIndex=0;
        QJsonArray inventoryWeapons = board["inventoryWeapons"].toArray();
        QJsonArray inventoryArmors = board["inventoryArmors"].toArray();
        QJsonArray inventoryPotions = board["inventoryPotions"].toArray();
        for(int index=0; index<inventoryWeapons.size(); index++){
            QJsonObject inventoryWeaponObj = inventoryWeapons.at(index).toObject();
            int damage = inventoryWeaponObj["damage"].toInt();
            std::string name = inventoryWeaponObj["name"].toString().toStdString();
            std::string description = inventoryWeaponObj["description"].toString().toStdString();
            int durability = inventoryWeaponObj["durability"].toInt();
            Weapon* w = new Weapon(damage, name, description, 0, 0, durability);
            if(inventoryWeaponObj["equiped"].toInt() == 1){
                equipedWeapon = w;
            }
            inventory.at(inventoryIndex) = w;
            inventoryIndex++;
        }
        for(int index=0; index<inventoryArmors.size(); index++){
            QJsonObject inventoryArmorObj = inventoryArmors.at(index).toObject();
            int armor = inventoryArmorObj["armor"].toInt();
            std::string name = inventoryArmorObj["name"].toString().toStdString();
            std::string description = inventoryArmorObj["description"].toString().toStdString();
            int durability = inventoryArmorObj["durability"].toInt();
            Armor* a = new Armor(armor, name, description, 0, 0, durability);
            if(inventoryArmorObj["equiped"].toInt() == 1){
                equipedArmor = a;
            }
            inventory.at(inventoryIndex) = a;
            inventoryIndex++;
        }
        for(int index=0; index<inventoryPotions.size(); index++){
            QJsonObject inventoryPotionObj = inventoryPotions.at(index).toObject();
            int bonus = inventoryPotionObj["bonus"].toInt();
            std::string name = inventoryPotionObj["name"].toString().toStdString();
            std::string description = inventoryPotionObj["description"].toString().toStdString();
            Potion* p = new Potion(bonus, name, description, 0, 0);
            inventory.at(inventoryIndex) = p;
            inventoryIndex++;
        }
        Hero* loadedHero = new Hero(x, y, name, baseDamage, experience, level, inventory,
                                    numberOfKilledShamans, defense, health);
        if (equipedWeapon != nullptr){
            loadedHero->equipWeapon(equipedWeapon);
        }
        if(equipedArmor != nullptr){
            loadedHero->equipArmor(equipedArmor);
        }
        return loadedHero;
    }
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
