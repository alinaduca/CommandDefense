#include "Mercedes.h"
#include "WeatherCondition.h"
#include <iostream>

using namespace std;

Mercedes::Mercedes() {
    setFuelCapacity(200);
    setFuelConsumption(50);
    averageSpeed[Rain]  = 20;
    averageSpeed[Sunny] = 40;
    averageSpeed[Snow]  = 60;
}

void Mercedes::Print() {
    cout << "Mercedes" << endl;
}