#ifndef HIDEOUT_H
#define HIDEOUT_H

#include "../Board/boardcell.h"


class Hideout: public BoardCell {
private:
    int m_healingBonus;

public:
    Hideout(int x, int y, int healingBonus, Character* ch = nullptr, Item* i = nullptr);
    int getHealingBonus() const;
};

#endif // HIDEOUT_H
