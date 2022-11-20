#include "hideout.h"

Hideout::Hideout(int x, int y, int healingBonus, Character* ch, Item* i): BoardCell(x, y, ch, i){
    m_healingBonus = healingBonus;
}
