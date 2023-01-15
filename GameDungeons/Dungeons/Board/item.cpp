#include "item.h"

#include <utility>

Item::Item(int x, int y, std::string name, std::string description, bool isEquiped){
    m_x = x;
    m_y = y;
    m_name = name;
    m_description = description;
    m_itemCorruption = false;
    m_isEquiped = isEquiped;
}

int Item::getX() {
    return m_x;
}

int Item::getY() {
    return m_y;
}

bool Item::isEquiped(){
    return m_isEquiped;
}

void Item::equip(){
    m_isEquiped = true;
}

void Item::unEquip(){
    m_isEquiped = false;
}

QString Item::getQStringName() const {
    return QString::fromStdString(m_name);
}

QString Item::getQstringDescription() const{
    return QString::fromStdString(m_description);
}

Item::ItemType Item::getItemType() const {
    return ItemType::None;
}

std::string Item::getName() {
    return m_name;
}

std::string Item::getDescription() {
    return m_description;
}

bool Item::getItemCorruption() const {
    return m_itemCorruption;
}

void Item::setItemCorruption() {
    m_itemCorruption = true;
    emit itemCorruptionChanged();
}
