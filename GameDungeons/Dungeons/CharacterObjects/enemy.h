#ifndef ENEMY_H
#define ENEMY_H

#include "../Board/character.h"

class Enemy: public Character{
private:
    int m_experienceBonus;
public:
    Enemy(int x, int y, const std::string& name, int damage, int armor, int experienceBonus);
    int getExperienceBonus() const;
    ~Enemy();   //TODO Destruktor - kdyz zabiju priseru, tak by mela zmizet z herniho planu

};

#endif // ENEMY_H
