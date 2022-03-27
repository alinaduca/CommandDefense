#include "Number.h"

Number::Number(const char *value, int base) {
    if (base < 2 || base > 16)
        return;
    this->base = base;
    this->lenght = int(strlen(value));
    this->value = new char[this->lenght];
    strcpy(this->value, value);
}

Number::~Number() {
    this->lenght = 0;
}

//Number::Number(const Number& other) : Number(other.base, other.lenght, other.value) { };

Number::Number(const char *value) {
    this->lenght = int(strlen(value));
    this->value  = new char[this->lenght];
    strcpy(this->value, value);
};

Number::Number(int value) {
    int i = 0;
    char aux[100];
    while (value) {
        aux[i++] = char(value % 10 + '0');
        value /= 10;
    }
    aux[i] = '\n';
    this->lenght = i;
    this->value  = new char[this->lenght];
    for (i = 0; i < this->lenght; i++)
        this->value[i] = aux[this->lenght - i - 1];
    this->value[this->lenght] = '\0';
};

Number::Number(const Number& other) {
    this->base   = other.base;
    this->lenght = other.lenght;
    this->value  = new char[this->lenght];
    strcpy(this->value, other.value);
};

void Number::SwitchBase(int newBase) {
    strcpy(this->value, tentob(bto10(this->value, this->base), newBase));
    this->base = newBase;
}

void Number::Print() {
    cout << this->value << "\n";
}

int Number::GetDigitsCount() {
    return int(strlen(this->value));
}

int Number::GetBase() {
    return this->base;
}

char& Number::operator[](int i) {
    return this->value[i];
}

Number& Number::operator+=(const Number& second) {
    int bfinala, a, b;
    if (second.base >= this->base)
        bfinala = second.base;
    else
        bfinala = this->base;
    this->base = bfinala;

    a = bto10(this->value, this->base);
    b = bto10(second.value, second.base);
    strcpy(this->value, tentob(a + b, bfinala));
    return *this;
}

Number& Number::operator-=(const Number& second) {
    int bfinala, a, b;
    if (second.base >= this->base)
        bfinala = second.base;
    else
        bfinala = this->base;
    this->base = bfinala;

    a = bto10(this->value, this->base);
    b = bto10(second.value, second.base);
    strcpy(this->value, tentob(a - b, bfinala));
    return *this;
}

Number& Number::operator--() {
    strcpy(this->value, this->value + 1);
    return *this;
}

Number& Number::operator--(int) {
    this->value[strlen(this->value) - 1] = '\0';
    return *this;
}

Number& Number::operator=(const Number& other) {
    this->value = other.value;
    this->base = other.base;
    this->lenght = int(strlen(other.value));
    return *this;
}

int Number::bto10(const char* value, int base)
{
    int p = 1, n = 0;
    for (int i = int(strlen(value)) - 1; i >= 0; i--) {
        n += (value[i] - '0') * p;
        p *= base;
    }
    return n;
}

const char* Number::tentob(int nr, int base){
    char aux[100] = "";
    unsigned i = 0, n;
    while (nr) {
        aux[i++] += char(nr % base + '0');
        nr /= base;
    }
    aux[i] = '\0';
    n = i;
    for (i = 0; i < n / 2; i++) {
        char c = aux[i];
        aux[i] = aux[n - i - 1];
        aux[i] = c;
    }
    return aux;
}
