#include <iostream>

int potegowanie(int x, unsigned int n)
{
    if (n == 0)
        return 1;

    int result;

    if (n % 2 == 1)
    {
        result = potegowanie(x, (n - 1));
        return x * result;
    }

    if (n % 2 == 0)
    {
        result = potegowanie(x, n/2);
        return result * result;
    }
}

int potegowanie_iteracyjnie(int x, unsigned int n)
{
    int result = 1;

    while (n > 0)
    {
        if (n % 2 == 1)
        {
            result = result * x;
        }

        x = x * x;
        n = n / 2;
    }

    return result;
}

int main()
{
    const int endValue = 6;
    int x = 2;

    for (int i = 0; i < endValue; i++)
    {
        std::cout << "Rekurencja: " << x << " ^ " << i << " = " << potegowanie(x, i) << std::endl;
        std::cout << "Iteracja:   " << x << " ^ " << i << " = " << potegowanie_iteracyjnie(x, i) << std::endl;
    }

    return 0;
}