#pragma once

class Wave {
  private:
    int numberOfEnemies;
    char *nameWave;
    int startingHealth;
    float money;

  public:
    void setName(char *name);
    void setNumberOfEemies(int number);
    void setStartingHealth(int health);
    void setMoney(float value);

    char* getName();
    int getNumberOfEnemies();
    int getStartingHealth();
    float getMoney();
};