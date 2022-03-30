#include "Toyota.h"
#include "WeatherCondition.h"
#include <iostream>

using namespace std;

Toyota::Toyota()
{
    setFuelCapacity(250);
    setFuelConsumption(10);
    averageSpeed[Rain]  = 20;
    averageSpeed[Sunny] = 40;
    averageSpeed[Snow]  = 60;
}

void Toyota::Print() {
    cout << "Toyota" << endl;
}