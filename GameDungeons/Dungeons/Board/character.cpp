
#include "character.h"

Character::Character(int x, int y, const std::string &name, int baseDamage, int defense) {
    m_x = x;
    m_y = y;
    m_name = name;
    m_baseDamage = baseDamage;
    m_defense = defense;
    m_maxHealth = 100;
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

int Character::getDefense() const {
    return m_defense;
}

int Character::getBaseDamage() const {
    return m_baseDamage;
}