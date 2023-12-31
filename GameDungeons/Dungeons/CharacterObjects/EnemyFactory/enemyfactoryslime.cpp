#include "enemyfactoryslime.h"

Enemy *EnemyFactorySlime::getEnemy(int x, int y) {
    srand(time(0));     // Damage within interval 10-19, armor 18-20, exp for hero 20-30
    return new Enemy(x, y, "Slime", rand()%9+10, rand()%3+18, rand()%11+20);
}
