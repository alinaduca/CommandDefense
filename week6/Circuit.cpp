#include "Circuit.h"
#include <iostream>

using namespace std;

void Circuit::setLength(float lng) {
    this->length = lng;
}

void Circuit::setWeather(Weather weather) {
    this->weather = weather;
}

float Circuit::getLength() {
    return length;
}

Weather Circuit::getWeather() {
    return weather;
}

void Circuit::AddCar(Car* car) {
    cars[numberOfCars++] = car;
}

void Circuit::Race() {
    float raceLength = getLength();
    Weather weather  = getWeather();
    for (int i = 0; i < numberOfCars; i++) {
        if (cars[i]->getFuelCapacity() * 100 / cars[i]->getFuelConsumption() >= raceLength)
            cars[i]->timeToFinish = raceLength / cars[i]->averageSpeed[weather];
        else
            cars[i]->timeToFinish = -1;
    }
}

void Circuit::ShowWhoDidNotFinish() {
    cout << "Cars who did not finish:" << '\n';
    for (int i = 0; i < numberOfCars; i++) {
        if (cars[i]->timeToFinish == -1) {
            cars[i]->print();
        }
    }
}

void Circuit::ShowFinalRanks() {
    cout << "Cars leaderboard:" << endl;
    for (int i = 0; i < numberOfCars; i++) {
        for (int j = 0; j < numberOfCars - i - 1; j++) {
            if (cars[j]->timeToFinish > cars[j + 1]->timeToFinish) {
                Car* temp = cars[j];
                cars[j]   = cars[j];
                cars[j]   = temp;
            }
        }
    }
    for (int i = 0; i < numberOfCars; i++) {
        if (cars[i]->timeToFinish != -1) {
            cars[i]->print();
        }
    }
}