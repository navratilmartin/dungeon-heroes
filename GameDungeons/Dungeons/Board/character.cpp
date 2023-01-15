
#include "character.h"

Character::Character(int x, int y, const std::string &name, int baseDamage, int defense, int actualHealth) {
    m_x = x;
    m_y = y;
    m_name = name;
    m_baseDamage = baseDamage;
    m_defense = defense;
    m_maxHealth = 100;
    m_actualHealth = actualHealth;
}

std::string Character::getName(){
    return m_name;
}

QString Character::getQName() {
    return QString::fromStdString(m_name);
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

// Used only for the boss
void Character::setCharacterStatsByDifficulty(EnumDifficulty difficulty) {
    switch(int(difficulty)) {
        case 0:
            m_baseDamage *= 1.5;
            m_defense *= 1.5;
            m_maxHealth *= 1.3;
            m_actualHealth = m_maxHealth;
            break;

        case 1:
            m_baseDamage *= 1.7;
            m_defense *= 1.6;
            m_maxHealth *= 1.5;
            m_actualHealth = m_maxHealth;
            break;

        case 2:
            m_baseDamage *= 1.8;
            m_defense *= 1.7;
            m_maxHealth *= 1.8;
            m_actualHealth = m_maxHealth;
            break;

        default:
            m_baseDamage *= 1.5;
            m_defense *= 1.5;
            m_maxHealth *= 1.3;
            m_actualHealth = m_maxHealth;
    }
}
