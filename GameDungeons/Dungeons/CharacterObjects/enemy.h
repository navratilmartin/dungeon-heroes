#ifndef ENEMY_H
#define ENEMY_H

#include "../Board/character.h"

class Enemy: public Character{
private:
    int m_experienceBonus;
public:
    Enemy(int x, int y, const std::string& name, int damage, int armor, int experienceBonus);
};

#endif // ENEMY_H
