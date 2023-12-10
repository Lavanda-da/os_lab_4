#include <iostream>
#include <string>
#include <cmath>
#include <typeinfo>

#include "first.h"

int StringToInt(std::string s)
{
    int res = 0;
    int n = s.size();
    for (size_t i = 0; i < n; ++i)
    {
        res += ((s[i] - '0') * pow(10, n - 1 - i));
    }
    return res;
}

int main(int argc, char *argv[])
{
    std::string mode = argv[1];
    if (mode == "1") 
    {
        int x = StringToInt(std::string(argv[2]));
        std::cout << E(x) << std::endl;
    } else if (mode == "2")
    {
        int a = StringToInt(std::string(argv[2])), b = StringToInt(std::string(argv[3]));
        std::cout << primeCount(a, b) << std::endl;
    } else 
    {
        std::cout << typeid(argv[1]).name() << " nothing\n";
    }
    return 0;
}
