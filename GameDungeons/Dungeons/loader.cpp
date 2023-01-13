#include "loader.h"

Loader::Loader(){

}

Board* Loader::loadNewGame(EnumDifficulty difficulty) {
    Board* board = new Board(difficulty);
    return board;
}

void Loader::saveGame(const Board* currentBoard, Hero* hero){
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
    //Inventory

    //Cells of individual rooms

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
