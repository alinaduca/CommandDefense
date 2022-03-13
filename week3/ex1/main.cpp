#include "Math.h"

int main() {
    int int1 = 55, int2 = 22, int3 = 99;
    double double1 = 5.5, double2 = 2.2, double3 = 9.9;
    char sir1[] = "4747", sir2[] = "5151", *p1 = sir1, *p2 = sir2;

    cout << Math::Add(int1, int2) << "\n";
    cout << Math::Add(int1, int2, int3) << "\n";

    cout << Math::Add(double1, double2) << "\n";
    cout << Math::Add(double1, double2, double3) << "\n";

    cout << Math::Mul(int1, int2) << "\n";
    cout << Math::Mul(int1, int2, int3) << "\n";

    cout << Math::Mul(double1, double2) << "\n";
    cout << Math::Mul(double1, double2, double3) << "\n";

    cout << Math::Add(5, 27, 36, 45, 54, 63) << "\n";

    cout << Math::Add(p1, p2);
    return 0;
}