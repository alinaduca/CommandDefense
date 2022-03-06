#include "EnemyController.h"
#include "Enemy.h" // to actualy use the field Enemy declared in the header by forward declaration, we use the field here

void EnemyController::Init(int maximumEnemies, int step, Point initialLocation) {
    this->enemies = new Enemy[maximumEnemies];
    this->maxEnemies = maximumEnemies;
    this->nrEnemies = 0;
    this->stepSize = step;
    this->startinLocation = initialLocation;
}

void EnemyController::Uninit() {
    delete[] enemies;
    this->maxEnemies = 0;
    this->nrEnemies = 0;
}

void EnemyController::Move() {
    for (int iterator = 0; iterator < nrEnemies; iterator++)
        enemies[iterator].Move(EnemyDirection::UpDirection, stepSize);
}

void EnemyController::DamageAll() {
    for (int iterator = 0; iterator < nrEnemies; iterator++)
        enemies[iterator].Shoot(iterator + 1);
}

int EnemyController::CountKilledEnemies() {
    int killedEnemies = 0;
    for (int iterator = 0; iterator < nrEnemies; iterator++)
        if (enemies[iterator].IsDead())
            killedEnemies++;
    return killedEnemies;
}

bool EnemyController::SpawnEnemy() {
    for (int iterator = 0; iterator < nrEnemies; iterator++)
        if (enemies[iterator].IsDead()) {
            enemies[iterator].Init(startinLocation, ENEMY_HEALTH);
            return true;
        }
    if (nrEnemies + 1 > maxEnemies)
        return false;

    enemies[nrEnemies].Init(startinLocation, ENEMY_HEALTH);
    nrEnemies++;
    return true;
}