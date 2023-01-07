#include "boardcell.h"

BoardCell::BoardCell(int x, int y, Character*ch, Item* i){
    m_x = x;
    m_y = y;
    m_character = ch;
    m_item = i;
}
int BoardCell::getCharacterHealth(){
    return m_character->getActualHealth();
}
int BoardCell::getY() const{
    return m_y;
}

int BoardCell::getX() const{
    return m_x;
}

bool BoardCell::characterIsNotNull(){
    return m_character!=nullptr;
}

bool BoardCell::itemIsNotNull(){
    return m_item!=nullptr;
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
}

void BoardCell::removeCharacter() {
    m_character = nullptr;
}

void BoardCell::removeItem() {
    m_item = nullptr;
    emit itemIsNotNullChanged();
}

QString BoardCell::characterName(){
    std::string str = m_character->getName();
    QString qstr = QString::fromStdString(str);
    return qstr;
}
QString BoardCell::itemName(){
    std::string str = m_item->getName();
    QString qstr = QString::fromStdString(str);
    return qstr;
}


