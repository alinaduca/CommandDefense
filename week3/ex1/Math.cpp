#include "Math.h"
#define _CRT_SECURE_NO_WARNINGS

int Math::Add(int x, int y) {
    return x + y;
}

int Math::Add(int x, int y, int z) {
    return x + y + z;
}

int Math::Add(double x, double y) {
    return int(x + y);
}

int Math::Add(double x, double y, double z) {
    return int(x + y + z);
}

int Math::Mul(int x, int y) {
    return x * y;
}

int Math::Mul(int x, int y, int z) {
    return x * y * z;
}

int Math::Mul(double x, double y) {
    return int(x * y);
}

int Math::Mul(double x, double y, double z) {
    return int(x * y * z);
}

int Math::Add(int count, ...) { // sums up a list of integers
    int S = 0;
    va_list args;
    va_start(args, count);
    for(int iterator = 0; iterator < count; iterator++)
        S += va_arg(args, int);
    va_end(args);
    return S;
}

char* Math::Add(const char* x, const char* y) {
    if(x == nullptr || y == nullptr)
        return nullptr;
    char* buffer;
    buffer = (char*) malloc(strlen(x) + strlen(y) + 1);
    int k = 0;
    for(int i = 0; i < strlen(x); i++, k++)
        buffer[k] = x[i];
    for(int i = 0; i < strlen(y); i++, k++)
        buffer[k] = y[i];
    buffer[k] = '\0';
    return buffer;
}