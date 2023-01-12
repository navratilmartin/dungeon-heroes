#include "hero.h"

Hero::Hero(int x, int y, const std::string& name, int baseDamage):
        Character(x, y, name, baseDamage, 0){
    m_experience = 0;
    m_level = 1;
    m_inventory = std::vector<Item*>(inventorySize, nullptr);
    m_weapon = nullptr;
    m_armor = nullptr;
    m_indexOfEquipedWeaponInInventory = 0;
    m_indexOfEquipedArmorInInventory = 0;

    m_isItemWeapon = false;
    m_isItemArmor = false;
    m_isItemPotion = false;
}

std::vector<Item*> Hero::getInventory() const {
    return m_inventory;
}

int Hero::getLevel() const {
    return m_level;
}

int Hero::getExperience() const {
    return m_experience;
}

Weapon* Hero::getWeapon() const {
    return m_weapon;
}

Armor* Hero::getArmor() const {
    return m_armor;
}

void Hero::simpleAttack(Character* ch){
    ch->decHealth(this->m_baseDamage);
}

int Hero::changeX(int by) {

    m_x += by;
    emit xChanged();
    // std::cout<<"##################################"<<std::endl;
    // std::cout<<m_x<<std::endl;
    // std::cout<<m_y<<std::endl;

    return m_x;
}

int Hero::changeY(int by) {

    m_y += by;
    emit yChanged();
    // std::cout<<"##################################"<<std::endl;
    // std::cout<<m_x<<std::endl;
    // std::cout<<m_y<<std::endl;

    return m_y;
}

void Hero::resetXY() {
    m_x = 0;
    m_y = 0;
    emit xChanged();
    emit yChanged();
}

void Hero::interactWithBoardCell(BoardCell* boardCell) {
    if (boardCell != nullptr and boardCell->getItem() != nullptr) {
        for (unsigned long long itemIndex = 0; itemIndex < m_inventory.size(); itemIndex++) {
            if (m_inventory.at(itemIndex) == nullptr) {
                m_inventory.at(itemIndex) = boardCell->getItem();
                emit inventoryChanged();
                // std::cout << boardCell->getItem()->getName() << '\n';
                // std::cout << "Item has been added into inventory.\n";
                boardCell->removeItem();
                break;
            }
        }
    }
}

void Hero::useItem(int itemIndex) {
    if (dynamic_cast<Weapon*>(m_inventory.at(itemIndex)) and m_weapon == nullptr) {
        m_weapon = dynamic_cast<Weapon*>(m_inventory.at(itemIndex));
        m_indexOfEquipedWeaponInInventory = itemIndex;
        m_baseDamage += m_weapon->getDamageBonus();
        emit damageChanged();
        emit weaponChanged();
    } else if (dynamic_cast<Armor*>(m_inventory.at(itemIndex)) and m_armor == nullptr) {
        m_armor = dynamic_cast<Armor*>(m_inventory.at(itemIndex));
        m_defense += m_armor->getArmorBonus();
        emit defenseChanged();
        emit armorChanged();
    } else if (dynamic_cast<Potion*>(m_inventory.at(itemIndex))) {
        m_actualHealth += m_maxHealth * dynamic_cast<Potion*>(m_inventory.at(itemIndex))
                ->getPercentageHealthBonus() / 100;
        m_inventory.at(itemIndex) = nullptr;
        emit healthChanged();
        emit inventoryChanged();
    }
}

void Hero::dropItem(int itemIndex) {
    if (m_inventory.at(itemIndex) != nullptr and m_inventory.at(itemIndex) == m_weapon) {
        m_baseDamage -= m_weapon->getDamageBonus();
        m_baseDamage = m_baseDamage < 0 ? 0 : m_baseDamage;
        m_weapon = nullptr;
        emit weaponChanged();
    } else if (m_inventory.at(itemIndex) != nullptr and m_inventory.at(itemIndex) == m_armor) {
        m_defense -= m_armor->getArmorBonus();
        m_defense = m_defense < 0 ? 0 : m_defense;
        m_armor = nullptr;
        emit armorChanged();
    }

    m_inventory.at(itemIndex) = nullptr;
    emit inventoryChanged();
}

void Hero::inspectItem(int itemIndex) {
    if (dynamic_cast<Weapon*>(m_inventory.at(itemIndex))) {
        m_isItemWeapon = true;
        emit isItemWeaponChanged();
    } else if (dynamic_cast<Armor*>(m_inventory.at(itemIndex))) {
        m_isItemArmor = true;
        emit isItemArmorChanged();
    } else if (dynamic_cast<Potion*>(m_inventory.at(itemIndex))) {
        m_isItemPotion = true;
        emit isItemPotionChanged();
    }
}

void Hero::attack(Enemy *e) { // Hero always attacks the enemy, never the other way around.
    int weaponBonusDamage = 0;
    if(m_weapon != nullptr){
        weaponBonusDamage = m_weapon->getDamageBonus();
    }
    float attackDamage = (m_baseDamage+weaponBonusDamage) * (1-float(e->getDefense())/100);
    float attackDamageEnemy = e->getBaseDamage() * (1-float(m_defense)/100);
    if(attackDamage >= 2*attackDamageEnemy){   // If the hero damage is twice than enemy's, he kills immediately
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
    if(m_weapon->getDurability() == 1){ // If the weapon is just about to be destroyed
        delete m_weapon;
        m_weapon = nullptr;
        std::cout << "Weapon destroyed" << std::endl;
        //TODO vypise se na frontend ze zbran byla znicena
    }else{
        m_weapon->decreaseDurabilityByOne();
    }
}

void Hero::useArmor(int durabilityDecrease) {
    if(m_armor->getDurability() == 1) { // If the armor is about to be destroyed
        delete m_armor;
        m_armor = nullptr;
        std::cout << "Armor destroyed" << std::endl;
        //TODO vypise se na frontend ze armor byl znicen
    } else {
        m_armor->decreaseDurability(durabilityDecrease);
    }
}

void Hero::getXp(int experienceBonus) { // If the hero has 100xp, he will level up and his stats will increase
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
    m_actualHealth -= damage;

    if((m_actualHealth-damage) <= 0){
        m_actualHealth = 0;
    }
}

int Hero::getIndexOfEquipedArmorInInventory() const {
    return m_indexOfEquipedArmorInInventory;
}

int Hero::getIndexOfEquipedWeaponInInventory() const {
    return m_indexOfEquipedWeaponInInventory;
}
