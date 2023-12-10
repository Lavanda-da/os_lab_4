#include "first.h"

double E(int x)
{
    return pow((1 + 1.0 / x), x);
}

bool isPrime(int x) {
    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}

int primeCount(int a, int b)
{
    int count = 0;
    for (int i = a; i <= b; ++i)
    {
        if (isPrime(i))
        {
            ++count;
        }
    }
    return count;
}
