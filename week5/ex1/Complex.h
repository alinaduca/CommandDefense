#pragma once
#define _CRT_SECURE_NO_WARNINGS

// operatori care trebuie implementati:
// 1. op+, op-, op*
// care sa accepte doua numere complexe, un numar complex si un numar real, sau un numar real si un numar complex
// (9 in total)
// 2. op- unar
// 3. op== si op!=
// 4. op<< de streamuri pentru afisare
// 5. op++ prefixat si postfixat si op-- prefixat si postfixat
// 6. op() cu semnificatia de mai jos
// total: 18 operatori

// op++ postfixat TREBUIE sa foloseasca op++ prefixat
// op-- postfixat TREBUIE sa foloseasca op-- prefixat

// op+, op-, op* care iau un numar real TREBUIE sa foloseasca respectivii care iau numere complexe
// eg: op+(Complex, double) va apela op+(Complex, Complex)

#include <ostream>

bool double_equals(double l, double r);

#define check(x) if (!(x)) printf("at line #%d -> `%s` is not satisfied\n", __LINE__, #x); return 1; 

class Complex
{
private:
    double real_data;
    double imag_data;
public:
    Complex();
    Complex(double real, double imag);

    // daca numarul are doar o parte reala
    bool is_real() const;

    double real() const;
    double imag() const;
    // absolutul numarului
    double abs() const;
    // conjugatul
    Complex conjugate() const;
    
    Complex& operator++();
    Complex operator++(int);
    Complex& operator--();
    Complex operator--(int);
};

Complex operator+(const Complex& l, const Complex& r);
Complex operator+(const Complex& l, double r);
Complex operator+(double l, const Complex& r);

Complex operator-(const Complex& obj);

Complex operator-(const Complex& l, const Complex& r);
Complex operator-(const Complex& l, double r);
Complex operator-(double l, const Complex& r);

Complex operator*(const Complex& l, const Complex& r);
Complex operator*(const Complex& l, double r);
Complex operator*(double l, const Complex& r);

bool operator==(const Complex& l, const Complex& r);
bool operator!=(const Complex& l, const Complex& r);

std::ostream& operator<<(std::ostream& out, const Complex& complex);