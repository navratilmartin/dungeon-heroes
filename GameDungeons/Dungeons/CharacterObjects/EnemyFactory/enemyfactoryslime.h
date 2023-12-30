#ifndef ENEMYFACTORYSLIME_H
#define ENEMYFACTORYSLIME_H

#include "enemyfactory.h"

class EnemyFactorySlime: public EnemyFactory{
public:
    Enemy* getEnemy(int x, int y) override;
};

#endif // ENEMYFACTORYSLIME_H
