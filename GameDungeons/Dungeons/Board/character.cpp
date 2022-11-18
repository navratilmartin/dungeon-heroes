
#include "character.h"

Character::Character(int x, int y, std::string name, int damage, int armor) {
    m_x = x;
    m_y = y;
    m_name = name;
    m_damage = damage;
    m_armor = armor;
    m_maxHealth = 1000;
    m_actualHealth = m_maxHealth;
}

std::string Character::getName() {
    return m_name;
}

int Character::getX() const {
    return m_x;
}

int Character::getY() const {
    return m_y;
}

int Character::getActualHealth() const {
    return m_actualHealth;
}

int Character::getMaxHealth() const {
    return m_maxHealth;
}

int Character::getArmor() const {
    return m_armor;
}

int Character::getDamage() const {
    return m_damage;
}