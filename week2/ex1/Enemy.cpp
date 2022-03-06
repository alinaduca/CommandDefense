#include "Enemy.h"

void Enemy::Init(Point intitialLocation, int initialHealh) {
    this->location = intitialLocation;
    this->health   = initialHealh;
}

void Enemy::Move(EnemyDirection direction, int step) {
    if (direction == EnemyDirection::UpDirection)
        this->location.y -= step;
    if (direction == EnemyDirection::DownDirection)
        this->location.y += step;
    if (direction == EnemyDirection::LeftDirection)
        this->location.x -= step;
    if (direction == EnemyDirection::DownDirection)
        this->location.x += step;
}

bool Enemy::IsDead() {
    if (this->health <= 0)
        return true;
    return false;
}

void Enemy::Shoot(int damage)
{
    this->health -= damage;
}