#include "potion.h"

Potion::Potion(int percentageHealthBonus, const std::string& name, const std::string& description, int x, int y):
        Item(x, y, name, description) {
        m_percentageHealthBonus = percentageHealthBonus;
}

int Potion::getPercentageHealthBonus() const {
    return m_percentageHealthBonus;
}

Item::ItemType Potion::getItemType() const {
    return Item::ItemType::Potion;
}
