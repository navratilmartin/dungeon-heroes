#ifndef POTION_H
#define POTION_H

#include "../../Board/item.h"

class Potion: public Item {
private:
    Q_OBJECT
    int m_percentageHealthBonus;

public:
    Potion(int percentageHealthBonus, const std::string& name, const std::string& description, int x, int y);
    int getPercentageHealthBonus() const;
    Item::ItemType getItemType() const override;
};

#endif // POTION_H
