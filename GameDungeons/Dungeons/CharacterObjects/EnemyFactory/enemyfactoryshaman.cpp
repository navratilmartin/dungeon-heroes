#include "enemyfactoryshaman.h"

Enemy *EnemyFactoryShaman::getEnemy(int x, int y) {
    srand(time(0));     // Damage within interval 21-24, armor 7-9, exp for hero 30-40
    return new Enemy(x, y, "Shaman", rand()%4+21, rand()%3+7, rand()%11+30);
}
