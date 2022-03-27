#include "Complex.h"
#include <iostream>
int main()
{
    Complex a{ 1, 2 };
    /* if (double_equals(a.real(), 1))
        printf("da");*/
    check(double_equals(a.real(), 1));
    check(double_equals(a.imag(), 2));

    Complex b{ 2, 3 };
    Complex c = a + b;
    check(double_equals(c.real(), 3));
    check(double_equals(c.imag(), 5));

    Complex d = c - a;
    check(b == d);

    Complex e = (a * d).conjugate();
    check(double_equals(e.imag(), -7));

    /// incrementeaza partea reala
    e++;
    ++e;
    check(double_equals(e.real(), -2));

    //// decrementeaza partea reala
    e--;
    --e;
    check(double_equals(e.real(), -4));

    Complex f = (a + b - d) * c;
    if (f != Complex{ 1, 2 })
    {
    //    // printeaza in formatul a +/i bi
    //    // daca a sau b sunt 0, nu vor fi printate
    //    // daca ambele sunt zero, se va printa doar partea reala
    //    // exemplu:                  5 + 4i
    //    // sau:                     -3 - 2i
    //    // daca e real:             -6
    //    // daca nu are parte reala: 5i
        std::cout << f << '\n' << a << '\n';
        std::cout << Complex{ 1, 2 } << '\n'
            << Complex{ 1, -2 } << '\n'
            << Complex{ 0, 5 } << '\n'
            << Complex{ 7, 0 } << '\n'
            << Complex{ 0, 0 } << '\n';
    }

    //// op() va updata partea reala si partea imaginara
    //// practic il folosim ca un setter pentru ambele numere
    Complex g = f(-1, -2)(-2, -3)(-4, -5);
    Complex h = { -4, -5 };
    check(g == h);

    Complex i = h - (h + 5) * 2;
    check(double_equals(i.real(), -6));

    // operatorul - unar
    Complex j = -i + i;
    check(double_equals(j.abs(), 0));

    return 0;
}