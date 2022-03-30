#include "Dacia.h"
#include "WeatherCondition.h"
#include <iostream>

using namespace std;

Dacia::Dacia() {
    setFuelCapacity(20);
    setFuelConsumption(30);
    averageSpeed[Rain]  = 20;
    averageSpeed[Sunny] = 40;
    averageSpeed[Snow]  = 60;
}

void Dacia::Print() {
    cout << "Dacia" << endl;
}