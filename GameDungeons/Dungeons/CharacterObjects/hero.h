#ifndef HERO_H
#define HERO_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#include "../Board/character.h"
#include "../Board/boardcell.h"
#include "Items/weapon.h"
#include "Items/potion.h"
#include "Items/armor.h"
#include "enemy.h"


class Hero: public Character {
private:
    Q_OBJECT
    Q_PROPERTY(int heroX READ getX NOTIFY xChanged)
    Q_PROPERTY(int heroY READ getY NOTIFY yChanged)

    Q_PROPERTY(std::vector<Item*> heroInventory READ getInventory NOTIFY inventoryChanged)
    Q_PROPERTY(QString heroName READ getQName CONSTANT)
    Q_PROPERTY(int heroHealth READ getActualHealth NOTIFY healthChanged)
    Q_PROPERTY(int heroDamage READ getBaseDamage NOTIFY damageChanged)
    Q_PROPERTY(int heroDefense READ getDefense NOTIFY defenseChanged)
    Q_PROPERTY(int heroLevel READ getLevel NOTIFY levelChanged)
    Q_PROPERTY(int heroExperience READ getExperience NOTIFY experienceChanged)

    const unsigned long long inventorySize = 8;

    int m_level;
    int m_experience;
    std::vector<Item*> m_inventory;
    Weapon* m_weapon;
    Armor* m_armor;

    void useWeapon();
    void useArmor(int durabilityDecrease);
    void getXp(int experienceBonus);
    void takeDamage(int damage);
public:
    Hero(int x, int y, const std::string& name, int baseDamage);

    std::vector<Item*> getInventory() const;
    int getLevel() const;
    int getExperience() const;

    void attack(Enemy* e);
    void equipWeapon(Weapon* w);
    void equipArmor(Armor* a);
    void drinkPotion(Potion* p);
    void pickupItem(Item* i);
    //temp
    void simpleAttack(Character* ch);

    Q_INVOKABLE int changeX(int by);
    Q_INVOKABLE int changeY(int by);
    Q_INVOKABLE void resetXY();
    Q_INVOKABLE void interactWithBoardCell(BoardCell* boardcell);

signals:
    void xChanged();
    void yChanged();
    void inventoryChanged();
    void healthChanged();
    void damageChanged();
    void defenseChanged();
    void levelChanged();
    void experienceChanged();
};

Q_DECLARE_METATYPE(std::vector<Item* >)

#endif // HERO_H
