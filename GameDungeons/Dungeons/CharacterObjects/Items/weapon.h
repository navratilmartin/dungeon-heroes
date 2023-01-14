#ifndef WEAPON_H
#define WEAPON_H

#include "../../Board/item.h"
#include <iostream>


class Weapon: public Item {
private:
    int m_damageBonus;
    int m_durability;

public:
    Weapon(int damageBonus, const std::string& name, std::string description, int x, int y);
    int getDamageBonus() const;
    int getDurability() const;
    void decreaseDurabilityByOne();
    Item::ItemType getItemType() const override;
};

#endif // WEAPON_H
