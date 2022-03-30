#pragma once
class Car {
  private:
    float fuelCapacity;
    float fuelConsumption;

  private:
  public:
    virtual void print() = 0;
    float averageSpeed[3];
    int timeToFinish;
    float getFuelCapacity() {
        return fuelCapacity;
    }
    float getFuelConsumption() {
        return fuelConsumption;
    }
    void setFuelCapacity(float x) {
        fuelCapacity = x;
    }
    void setFuelConsumption(float x) {
        fuelConsumption = x;
    }
};