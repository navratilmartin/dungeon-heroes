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
