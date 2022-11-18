#include "CharacterObjects/enemy.h"

Enemy::Enemy(int x, int y, const std::string& name, int damage, int armor, int experienceBonus):
        Character(x, y, name, damage, armor){
    m_experienceBonus = experienceBonus;
}
