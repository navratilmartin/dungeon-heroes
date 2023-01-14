#ifndef ENEMYFACTORYSHAMAN_H
#define ENEMYFACTORYSHAMAN_H

#include "enemyfactory.h"

class EnemyFactoryShaman: public EnemyFactory {
public:
    Enemy* getEnemy(int x, int y) override;
};

#endif // ENEMYFACTORYSHAMAN_H
