#include "Wave.h"

void Wave::setName(char *name) {
    this->nameWave = name;
}

void Wave::setNumberOfEemies(int number) {
    if (number > 0)
        this->numberOfEnemies = number;
}

void Wave::setStartingHealth(int health) {
    if (health > 0)
        this->startingHealth = health;
}

void Wave::setMoney(float value) {
    if (value != int(value))
        this->money = value;
}

char* Wave::getName() {
    return nameWave;
}

int Wave::getNumberOfEnemies() {
    return numberOfEnemies;
}

int Wave::getStartingHealth() {
    return startingHealth;
}

float Wave::getMoney() {
    return money;
}