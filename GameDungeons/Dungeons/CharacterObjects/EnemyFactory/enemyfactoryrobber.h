#ifndef ENEMYFACTORYROBBER_H
#define ENEMYFACTORYROBBER_H

#include "enemyfactory.h"

class EnemyFactoryRobber: public EnemyFactory {
public:
    Enemy* getEnemy(int x, int y) override;
};

#endif // ENEMYFACTORYROBBER_H
