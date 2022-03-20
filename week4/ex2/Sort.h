#pragma once
#include <iostream>

using namespace std;

class Sort
{
    // add data members
  private:
    int nrValues;
    int* v;

    // add constuctors
  public:
    void InsertSort(bool ascendent=false);
    void QuickSort(int st, int dr, bool ascendent=false);
    void BubbleSort(bool ascendent=false);
    void Print();
    int GetElementsCount();
    int GetElementFromIndex(int index);
    Sort(int nrValues, int min, int max);
    Sort(const Sort& other);
    Sort(int nrValues, int* v);
    Sort(int count, ...);
    Sort(const char* sir);
};