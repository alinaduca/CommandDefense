#include "GlobalFunctions.h"

int CompareNumberOfEnemies(Wave *wave1, Wave *wave2) {
    if (wave1->getNumberOfEnemies() == wave2->getNumberOfEnemies())
        return 0;
    if (wave1->getNumberOfEnemies() > wave2->getNumberOfEnemies())
        return 1;
    return -1;
}

int CompareMoneyPerEnemy(Wave *wave1, Wave *wave2) {
    if (wave1->getMoney() == wave2->getMoney())
        return 0;
    if (wave1->getMoney() > wave2->getMoney())
        return 0;
    return -1;
}