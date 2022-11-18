#include "hero.h"

Hero::Hero(int x, int y, const std::string& name, int damage, int armor):
        Character(x, y, name, damage, armor){
    m_experience = 0;
    m_level = 1;
    m_inventory = {};
    m_weapon = nullptr;
    m_armor = nullptr;
}

void Hero::equipWeapon(Weapon *w) {     //Item seberu ze zeme, pak z batohu pridam pomoci equip.
    m_weapon = w;
}

void Hero::equipArmor(Armor *a) {
    m_armor = a;
}

void Hero::drinkPotion(Potion *p) {
    m_actualHealth+= m_maxHealth * p->getPercentageHealthBonus()/100; // Using potion can exceed the maxHealth
}

void Hero::pickupItem(Item *i) {    // Finds an empty place in inventory and places the item in.
    auto ptr = std::find(m_inventory.begin(), m_inventory.end(), nullptr);
    if (ptr != m_inventory.end()){
        *ptr = i;
    }else{
        //inventory is full, emit signal na frontend a vypise se hlaska
    }

}