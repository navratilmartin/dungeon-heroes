#include "enemyfactoryshaman.h"

Enemy *EnemyFactoryShaman::getEnemy(int x, int y) {
    srand(time(0));     // Damage within interval 11-14, armor 7-9, exp for hero 30-40
    return new Enemy(x, y, "Shaman", rand()%4+11, rand()%3+7, rand()%11+30);
}