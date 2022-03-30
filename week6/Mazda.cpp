#include "Mazda.h"
#include "WeatherCondition.h"
#include <iostream>

using namespace std;

Mazda::Mazda() {
    setFuelCapacity(120);
    setFuelConsumption(30);
    averageSpeed[Rain]  = 10;
    averageSpeed[Sunny] = 30;
    averageSpeed[Snow]  = 50;
}

void Mazda::Print() {
    cout << "Mazda" << endl;
}