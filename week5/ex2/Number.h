#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

class Number
{
private:
    int base = 10, lenght;
    char *value;
    
    static int bto10(const char* value, int base); //pentru convertirea din baza b in baza 10
    static const char* tentob(int nr, int base); //pentru convertirea din baza 10 in baza b
    
public:
    Number(const char* value, int base); // where base is between 2 and 16
    ~Number();
    
    Number(const Number& other);
    Number(const char* value);
    Number(int value);
    
    void SwitchBase(int newBase);
    void Print();
    int  GetDigitsCount(); // returns the number of digits for the current number
    int  GetBase(); // returns the current base

    char& operator[](int i);
    Number& operator--();
    Number& operator--(int);

    Number& operator+=(const Number& second);
    Number& operator-=(const Number& second);
    Number& operator=(const Number& other);

    friend Number operator+(Number left, const Number& right) {
      left += right;
      return left;
    }
    
    friend Number operator-(Number left, const Number& right) {
      left -= right;
      return right;
    }
    
    friend bool operator<(Number const& left, Number const& right) {
        int a, b;
        a = bto10(left.value, left.base);
        b = bto10(right.value, right.base);
        return (a < b);
    }

    friend bool operator>(Number const& lhs, Number const& rhs) {
        int a, b;
        a = bto10(lhs.value, lhs.base);
        b = bto10(rhs.value, rhs.base);
        return (a > b);
    }

    friend bool operator<=(Number const& left, Number const& right) {
        int a, b;
        a = bto10(left.value, left.base);
        b = bto10(right.value, right.base);
        return (a <= b);
    }

    friend bool operator>=(Number const& left, Number const& right) {
        int a, b;
        a = bto10(left.value, left.base);
        b = bto10(right.value, right.base);
        return (a >= b);
    }

    friend bool operator==(Number const& left, Number const& right) {
        int a, b;
        a = bto10(left.value, left.base);
        b = bto10(right.value, right.base);
        return ((a == b) && (left.base == right.base));
    }

    friend bool operator!=(Number const& left, Number const& right) {
        int a, b;
        a = bto10(left.value, left.base);
        b = bto10(right.value, right.base);
        return !((a == b) && (left.base == right.base));
    }
};
