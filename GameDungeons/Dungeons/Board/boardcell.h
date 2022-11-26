#ifndef BOARDCELL_H
#define BOARDCELL_H

#include "character.h"
#include "item.h"
#include <QObject>

class BoardCell : public QObject {
protected:
    Q_OBJECT
    int m_x;
    int m_y;
    Character* m_character;
    Item* m_item;
    Q_PROPERTY(Character* character READ getCharacter() CONSTANT)
    Q_PROPERTY(bool characterIsNotNull READ characterIsNotNull() CONSTANT)
    Q_PROPERTY(QString name READ characterName() CONSTANT)
public:

    BoardCell(int x, int y, Character*ch, Item* i);
    bool characterIsNotNull();
    int getX() const;
    int getY() const;
    Character* getCharacter();
    Item* getItem();
    void addCharacter(Character* ch);   // When the hero steps on the cell, or we want to place an enemy on the cell
    void addItem(Item* i);              // If we want to place an item on the cell
    Item* pickUpItem();                 // Returns the item and removes it from the cell
    void removeCharacter();             // When the hero leaves the cell
    QString characterName();
};

#endif // BOARDCELL_H
