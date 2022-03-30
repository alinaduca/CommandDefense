#pragma once
#include "WeatherCondition.h"
#include "Car.h"
class Circuit {
  private:
    float length;
    Weather weather;
    int numberOfCars = 0;
    Car* cars[100];

  protected:
  public:
    void setLength(float lng);
    void setWeather(Weather weather);
    float getLength();
    Weather getWeather();
    void AddCar(Car* car);
    void Race();
    void ShowWhoDidNotFinish();
    void ShowFinalRanks();
};