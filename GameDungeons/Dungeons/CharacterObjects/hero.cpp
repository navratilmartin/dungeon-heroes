#include "hero.h"

Hero::Hero(int x, int y, const std::string& name, int baseDamage):
        Character(x, y, name, baseDamage, 0){
    m_experience = 0;
    m_level = 1;
    m_inventory = {};
    m_weapon = nullptr;
    m_armor = nullptr;
}

void Hero::attack(Enemy *e) { //Hero always attacks the enemy, never the other way around.
    int weaponBonusDamage = 0;
    if(m_weapon != nullptr){
        weaponBonusDamage = m_weapon->getDamageBonus();
    }
    float attackDamage = (m_baseDamage+weaponBonusDamage) * (1-float(e->getDefense())/100);
    float attackDamageEnemy = e->getBaseDamage() * (1-float(m_defense)/100);
    if(attackDamage >= 2*attackDamageEnemy){   // If the hero damage is twice the enemy damage, kills the enemy immediately
        if(m_weapon != nullptr){
            useWeapon();
        }
        getXp(e->getExperienceBonus());
        delete e;
    }
    else if(attackDamage >= attackDamageEnemy){ // If the hero wins, he takes only half the damage
        takeDamage(attackDamageEnemy/2);
        if(m_weapon != nullptr){
            useWeapon();
        }
        if(m_armor != nullptr){
            useArmor(1);
        }
        getXp(e->getExperienceBonus());
        delete e;
    }
    else if(attackDamage < attackDamageEnemy){  // If the hero loses, he takes full damage and doesnt hurt the enemy
        takeDamage(attackDamageEnemy);
        if(m_weapon != nullptr){
            useWeapon();
        }
        if(m_armor != nullptr){
            useArmor(2);
        }
    }
}

void Hero::useWeapon() {
    if(m_weapon->getDurability() == 1){ // Pokud je zbran tesne pred znicenim
        delete m_weapon;
        m_weapon = nullptr;
        std::cout << "Weapon destroyed" << std::endl;
        //TODO vypise se na frontend ze zbran byla znicena
    }else{
        m_weapon->decreaseDurabilityByOne();
    }
}

void Hero::useArmor(int durabilityDecrease) {
    if(m_armor->getDurability() == 1){ // Pokud je armor tesne pred znicenim
        delete m_armor;
        m_armor = nullptr;
        std::cout << "Armor destroyed" << std::endl;
        //TODO vypise se na frontend ze armor byl znicen
    }else{
        m_armor->decreaseDurability(durabilityDecrease);
    }
}

void Hero::getXp(int experienceBonus) { // Pokud hrdina ma xp 100, dostane dalsi level a zvednou se mu staty
    if((m_experience + experienceBonus) >= 100){
        m_level += (m_experience + experienceBonus) /100;
        m_experience = (m_experience + experienceBonus) % 100;
        m_baseDamage = m_baseDamage*1.1;
        m_maxHealth = m_maxHealth*1.1;
        m_actualHealth = m_actualHealth*1.1;
    }
    else{
        m_experience += experienceBonus;
    }
}

void Hero::takeDamage(int damage) {
    if((m_actualHealth-damage) <= 0){
        std:: cout << "You have lost the game" << std::endl;
        //TODO You have lost
    } else{
        m_actualHealth -= damage;
    }
}

void Hero::equipWeapon(Weapon *w) {     //Item seberu ze zeme, pak z batohu pridam pomoci equip.
    try {
        m_weapon = w;
    }
    //TODO Pokud bych poslal pointer na jinou tridu nez na weapon. Jakou exception odchytavat?
    catch(std::exception &e){
        std::cout << "exception caught in hero.cpp" << std::endl;
    }
}

void Hero::equipArmor(Armor *a) {
    try {
        m_armor = a;
    }
    catch(std::exception &e){
        std::cout << "exception caught in hero.cpp" << std::endl;
    }
}

void Hero::drinkPotion(Potion *p) {
    try {
        m_actualHealth += m_maxHealth * p->getPercentageHealthBonus() / 100; // Using potion can exceed the maxHealth
    }
    catch(std::exception &e){
        std::cout << "exception caught in hero.cpp" << std::endl;
    }
}

void Hero::pickupItem(Item *i) {    // Finds an empty place in inventory and places the item in.
    auto ptr = std::find(m_inventory.begin(), m_inventory.end(), nullptr);
    if (ptr != m_inventory.end()){
        *ptr = i;
    }else{
        //TODO inventory is full, emit signal na frontend a vypise se hlaska
    }

}