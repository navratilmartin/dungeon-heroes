#ifndef HERO_H
#define HERO_H

#include "../Board/character.h"
#include "Items/weapon.h"
#include "Items/potion.h"
#include "Items/armor.h"
#include "enemy.h"

#include <algorithm>
#include <array>

class Hero: public Character{
private:
    int m_level;
    int m_experience;
    std::array<Item*, 10> m_inventory;
    Weapon* m_weapon;
    Armor* m_armor;
public:
    Hero(int x, int y, const std::string& name, int damage, int armor);
    void attack(Enemy* e);
    void equipWeapon(Weapon* w);
    void equipArmor(Armor* a);
    void drinkPotion(Potion* p);
    void pickupItem(Item* i);
};

#endif // HERO_H
