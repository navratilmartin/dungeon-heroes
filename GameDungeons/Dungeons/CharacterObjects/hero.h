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

    Q_PROPERTY(QString heroName READ getQName CONSTANT)
    Q_PROPERTY(int heroHealth READ getActualHealth NOTIFY healthChanged)
    Q_PROPERTY(int heroDamage READ getBaseDamage NOTIFY damageChanged)
    Q_PROPERTY(int heroDefense READ getDefense NOTIFY defenseChanged)
    Q_PROPERTY(int heroLevel READ getLevel NOTIFY levelChanged)
    Q_PROPERTY(int heroExperience READ getExperience NOTIFY experienceChanged)

    Q_PROPERTY(std::vector<Item*> heroInventory READ getInventory NOTIFY inventoryChanged)
    Q_PROPERTY(Weapon* heroWeapon READ getWeapon NOTIFY weaponChanged)
    Q_PROPERTY(Armor* heroArmor READ getArmor NOTIFY armorChanged)

    Q_PROPERTY(bool heroEncounter MEMBER m_encounter NOTIFY encounterChanged)
    Q_PROPERTY(int killedShamans READ getNumberOfKilledShamans NOTIFY numberOfKilledShamansChanged)

    const unsigned long long static inventorySize = 8;

    int m_level;
    int m_experience;
    int m_numberOfkilledShamans;
    std::vector<Item*> m_inventory;
    Weapon* m_weapon;
    Armor* m_armor;
    bool m_encounter;
    int m_indexOfEquipedWeaponInInventory;
    int m_indexOfEquipedArmorInInventory;

    void useWeapon();
    void useArmor(int durabilityDecrease);
    void getXp(int experienceBonus);

public:
    Hero(int x, int y, const std::string& name, int baseDamage,int experience=0, int level=1,
         std::vector<Item*>inventory=std::vector<Item*>(8, nullptr), int numberOfKilledShamans=0, int defense=0, int health=100);
    void takeDamage(int damage);
    std::vector<Item*> getInventory() const;
    Weapon* getWeapon() const;
    Armor* getArmor() const;
    void equipWeapon(Weapon* w);
    void equipArmor(Armor* a);
    int getLevel() const;
    int getExperience() const;
    int getIndexOfEquipedArmorInInventory() const;
    int getIndexOfEquipedWeaponInInventory() const;
    int getNumberOfKilledShamans() const;

    Q_INVOKABLE int changeX(int by);
    Q_INVOKABLE int changeY(int by);
    Q_INVOKABLE void resetXY();
    Q_INVOKABLE void interactWithBoardCell(BoardCell* boardcell);
    Q_INVOKABLE void attack(BoardCell* boardcell);
    Q_INVOKABLE void useItem(int itemIndex);
    Q_INVOKABLE void dropItem(int itemIndex);

signals:
    void xChanged();
    void yChanged();

    void healthChanged();
    void damageChanged();
    void defenseChanged();
    void levelChanged();
    void experienceChanged();

    void inventoryChanged();
    void weaponChanged();
    void armorChanged();

    void encounterChanged();
    void numberOfKilledShamansChanged();
};

Q_DECLARE_METATYPE(std::vector<Item* >)
Q_DECLARE_METATYPE(Weapon*)
Q_DECLARE_METATYPE(Armor*)

#endif // HERO_H
