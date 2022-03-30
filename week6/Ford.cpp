#include "Ford.h"
#include "WeatherCondition.h"
#include <iostream>

using namespace std;

Ford::Ford() {
    setFuelCapacity(100);
    setFuelConsumption(20);
    averageSpeed[Rain]  = 30;
    averageSpeed[Sunny] = 50;
    averageSpeed[Snow]  = 70;
}

void Ford::Print() {
    cout << "Ford" << endl;
}