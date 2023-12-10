#include <vector>

extern "C" {
    int fact(int n)
    {
        int res = 1;
        for (int i = 1; i <= n; ++i) {
            res *= i;
        }
        return res;
    }
}

extern "C" {
    double E(int x) // formula Teylora
    {
        double sum = 1;
        for (int i = 1; i <= x; ++i) 
        {
            sum += (1.0 / fact(i));
        }
        return sum;
    }
}

extern "C" {
    int sum(std::vector<int> & v) 
    {
        int n = v.size();
        int count = 0;
        for (int i = 0; i < n; ++i) 
        {
            count += v[i];
        }
        return count;
    }
}

extern "C" {
    int primeCount(int a, int b) // sieve of Eratosthenes
    {
        std::vector<int> numbers(b + 1, 1);
        for (int i = 2; i * i <= b; ++i) 
        {
            for (int j = i + 1; j <= b; ++j)
            {
                if (j % i == 0) 
                {
                    numbers[j] = 0;
                }
            }
        }
        return sum(numbers) - 1;
    }
}
