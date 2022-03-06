#include <iostream>
#include "Wave.h"
#include "GlobalFunctions.h"

/*
	Design a C++ class that reflects the properties of an wave of enemies. The class should include the following:
 - methods to set and get the name of the wave
 - methods to set and get the number of enemies  (must be bigger than 0)
 - methods to set and get the starting health (bigger than 0)
 - methods to set and get the money per enemy (must be a float value)


	Create 2 global functions that compare two wave in terms of: number of enemies and money per enemy.
If two waves are equal the return value of such a function will be 0. If the first wave is bigger than the second one, the return value will be 1, otherwise -1.
	Make sure that you have the following:
a cpp file for the methods specific to the class
a header file for the global functions
a cpp file for the global functions implementation
a main.cpp file that shows how the methods and global functions can be used.

*/

int main()
{
    Wave *w1 = new Wave;
    Wave *w2 = new Wave;
    w1->setName((char*)"unu");
    w2->setName((char*)"doi");
    w1->setNumberOfEemies(23);
    w2->setNumberOfEemies(34);
    w1->setStartingHealth(10);
    w2->setStartingHealth(12);
    w1->setMoney(25.7);
    w2->setMoney(33.5);
    if (!CompareMoneyPerEnemy(w1, w2) && !CompareNumberOfEnemies(w1, w2))
        printf("Cele doua valuri sunt egale.");
    else if (CompareMoneyPerEnemy(w1, w2) >= 0 && CompareNumberOfEnemies(w1, w2) >= 0)
        printf("Valul %s este mai mare decat valul %s.", w1->getName(), w2->getName());
    else if (CompareMoneyPerEnemy(w1, w2) <= 0 && CompareNumberOfEnemies(w1, w2) <= 0)
        printf("Valul %s este mai mic decat valul %s.", w1->getName(), w2->getName());
    else
        printf("Nu putem decide ce val este mai mare.");
    return 0;
}