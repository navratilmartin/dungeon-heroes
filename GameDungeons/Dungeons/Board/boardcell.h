#ifndef BOARDCELL_H
#define BOARDCELL_H

#include "CharacterObjects/enemy.h"
#include "character.h"
#include "item.h"

class BoardCell : public QObject {
protected:
    Q_OBJECT
    Q_PROPERTY(Character* character READ getCharacter CONSTANT)
    Q_PROPERTY(bool isBossCell READ getIsBossCell CONSTANT)
    Q_PROPERTY(bool characterIsNotNull READ characterIsNotNull NOTIFY enemyIsNotNullChanged)
    Q_PROPERTY(QString characterName READ characterName CONSTANT)
    Q_PROPERTY(int characterHealth READ getCharacterHealth CONSTANT)
    Q_PROPERTY(bool itemIsNotNull READ itemIsNotNull NOTIFY itemIsNotNullChanged)
    Q_PROPERTY(QString itemName READ itemName CONSTANT)

    int m_x;
    int m_y;

    Item* m_item;
    Character* m_character;
    bool m_isBossCell;

public:
    BoardCell(int x, int y, Character*ch, Item* i);
    bool itemIsNotNull();
    bool characterIsNotNull();

    int getX() const;
    int getY() const;

    Character* getCharacter();
    QString characterName();
    int getCharacterHealth();
    void removeCharacter();

    Item* getItem();
    QString itemName();
    void addCharacter(Character* ch);   // When the hero steps on the cell, or we want to place an enemy on the cell
    void addItem(Item* i);              // If we want to place an item on the cell
    Item* pickUpItem();                 // Returns the item and removes it from the, when the hero leaves the cell
    void removeItem();

    bool getIsBossCell() const;
    void setBossCell(EnumDifficulty difficulty);

signals:
    void itemIsNotNullChanged();
    void enemyIsNotNullChanged();
};

Q_DECLARE_METATYPE(Character*)

#endif // BOARDCELL_H
