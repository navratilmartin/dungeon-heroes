#ifndef DUNGEONS_CHARACTER_H
#define DUNGEONS_CHARACTER_H

#include <iostream>

class Character{
protected:
    int m_x;
    int m_y;
    std::string m_name;
    int m_maxHealth;
    int m_actualHealth;
    int m_damage;
    int m_armor;
public:
    Character(int x, int y, std::string name, int damage, int armor);
    int getX() const;
    int getY() const;
    std::string getName();
    int getMaxHealth() const;
    int getActualHealth() const;
    int getDamage() const;
    int getArmor() const;
};


#endif //DUNGEONS_CHARACTER_H
