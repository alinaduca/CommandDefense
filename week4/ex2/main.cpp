#include "Sort.h"

int main()
{
    Sort sir1 = { 8, 30, 100 };
    sir1.Print();
    int vect[] = { 22, 344, 66, 88, 51, 23 };
    int nr = 6;
    Sort sir2 = { nr, vect };
    sir2.Print();
    Sort sir3 = sir2;
    sir3.Print();
    Sort sir4 = { 7, 3, 4, 5, 2, 3, 1, 12 };
    sir4.Print();
    Sort sir5 = { "5,4,9,2,7,546,229,1,3" };
    sir5.Print();
    sir1.BubbleSort(1);
    sir1.Print();
    sir2.InsertSort(1);
    sir2.Print();
    sir4.QuickSort(0, 6, 1);
    sir4.Print();
    cout << "sir1.v[1]=" << sir5.GetElementFromIndex(1) << "\n";
    cout << "sir2.nrValues=" << sir4.GetElementsCount() << "\n";
    return 0;
}