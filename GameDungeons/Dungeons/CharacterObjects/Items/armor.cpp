#include "CharacterObjects/Items/armor.h"

Armor::Armor(int armorBonus, const std::string& name, const std::string& description, int x, int y):
    Item(x, y, name, description) {
    m_armorBonus = armorBonus;
    m_durability = 100;
}

int Armor::getDurability() const {
    return m_durability;
}

int Armor::getArmorBonus() const {
    return m_armorBonus;
}

void Armor::decreaseDurability(int amount) {
    m_durability -= amount;     // One layer above, we need to check if the amount is not below 0 after decreasing
}