#ifndef ENEMY_H
#define ENEMY_H

#include "../Board/character.h"

class Enemy: public Character {
private:
    Q_OBJECT
    int m_experienceBonus;
public:
    Enemy(int x, int y, const std::string& name, int damage, int armor, int experienceBonus);
    int getExperienceBonus() const;
};

#endif // ENEMY_H
