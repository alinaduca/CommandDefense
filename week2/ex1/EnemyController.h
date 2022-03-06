#pragma once

#include "EnemiesStructures.h"
class Enemy; //forward declaration

#define ENEMY_HEALTH 10

class EnemyController
{
private:
    //Place here other required variables
    Enemy* enemies;
    int stepSize;
    int nrEnemies, maxEnemies;
    Point startinLocation;

public:
    void Init(int maximumEnemies, int step, Point initialLocation); // set maxEnemies and stepSize and allocated enemies and do the rest of initialization
    void Uninit();//delete allocated resources

    void Move();//move all spawned enemies (current enemies)
    void DamageAll(); // goes through every enemy and shoots them with the damage value (index of the element + 1)
    int CountKilledEnemies(); //returns the number of enemeies which are dead
    bool SpawnEnemy(); //if it can add the new enemy with ENEMY_HEALTH health value returns true, otherwise false
};
