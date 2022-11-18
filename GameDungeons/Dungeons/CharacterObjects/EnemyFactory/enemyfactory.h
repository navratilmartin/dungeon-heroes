#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H

#include <ctime>
#include <cstdlib>

#include "../enemy.h"

class EnemyFactory{
public:
    virtual Enemy* getEnemy(int x, int y) = 0;
};

#endif // ENEMYFACTORY_H
