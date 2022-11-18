#include "enemyfactoryrobber.h"

Enemy *EnemyFactoryRobber::getEnemy(int x, int y) {
    srand(time(0));     // Damage within interval 5-9, armor 1-3, exp for hero 15-25
    return new Enemy(x, y, "Robber", rand()%5+5, rand()%3+1, rand()%11+15);
}
