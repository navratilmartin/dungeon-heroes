#ifndef DUNGEONS_CHARACTER_H
#define DUNGEONS_CHARACTER_H

#include <string>
#include <QObject>
#include <QString>
#include "EnumDifficulty.h"

class Character: public QObject {
protected:
    int m_x;
    int m_y;
    std::string m_name;
    int m_maxHealth;
    int m_actualHealth;
    int m_baseDamage;
    int m_defense;

public:
    Character(int x, int y, const std::string &name, int baseDamage, int defense, int actualHealth=100);
    int getX() const;
    int getY() const;
    std::string getName();
    QString getQName();
    int getMaxHealth() const;
    int getActualHealth() const;
    int getBaseDamage() const;
    int getDefense() const;

    // Used only for the boss
    void setCharacterStatsByDifficulty(EnumDifficulty difficulty);
};


#endif //DUNGEONS_CHARACTER_H
