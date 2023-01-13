#ifndef ARMOR_H
#define ARMOR_H

#include "../../Board/item.h"

class Armor: public Item{
private:
    int m_armorBonus;
    int m_durability;
public:
    Armor(int armorBonus, const std::string& name, const std::string& description, int x, int y);
    int getArmorBonus() const;
    int getDurability() const;
    Item::ItemType getItemType() const override;
    void decreaseDurability(int amount);
};

#endif // ARMOR_H
