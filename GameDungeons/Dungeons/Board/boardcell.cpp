#include "boardcell.h"

BoardCell::BoardCell(int x, int y, Character*ch, Item* i){
    m_x = x;
    m_y = y;
    m_character = ch;
    m_item = i;
}

int BoardCell::getY() const{
    return m_y;
}

int BoardCell::getX() const{
    return m_x;
}

Character *BoardCell::getCharacter() {
    return m_character;
}

Item *BoardCell::getItem() {
    return m_item;
}

void BoardCell::addCharacter(Character* ch) {
    m_character = ch;
}

void BoardCell::addItem(Item *i) {
    m_item = i;
}

Item *BoardCell::pickUpItem() {
    return m_item;
    m_item = nullptr;
}

void BoardCell::removeCharacter() {
    m_character = nullptr;
}
