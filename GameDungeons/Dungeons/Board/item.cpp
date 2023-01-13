#include "item.h"

#include <utility>

Item::Item(int x, int y, std::string name, std::string description){
    m_x = x;
    m_y = y;
    m_name = name;
    m_description = description;
}

int Item::getX() {
    return m_x;
}

int Item::getY() {
    return m_y;
}

QString Item::getQStringName() const {
    return QString::fromStdString(m_name);
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
