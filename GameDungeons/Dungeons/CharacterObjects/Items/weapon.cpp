#include "CharacterObjects/Items/weapon.h"

Weapon::Weapon(int damageBonus, const std::string& name, std::string description, int x, int y):
    Item(x, y, name, description) {
    m_durability = 100;
    m_damageBonus = damageBonus;
}

int Weapon::getDamageBonus() const {
    return m_damageBonus;
}

int Weapon::getDurability() const{
    return m_durability;
}

Item::ItemType Weapon::getItemType() const {
    return Item::ItemType::Weapon;
}

void Weapon::decreaseDurabilityByOne() {
    m_durability--; // When swinging a sword, we call getDurability() to check, if its not one. If it is == 1
                    // the sword is destroyed and we return an announcmenet. If its more than 1, we call this method.
                    // This has to be checked one layer above this one - in a metod "attack" within the Hero class.
}
