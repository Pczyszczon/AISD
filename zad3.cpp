#include <iostream>

double oblicz(double a[], unsigned int n, int x)
{
    if (n == 0) {return 0;}
 
    int result = a[0];
    if (n == 1) {return result*x;}

    for (int i = 1 ; i < n; i++)
    {
        result = result*x + a[i];
    }

    return result;
}

int main()
{
    double coefficients[] = {7, 3, 1};

    std::cout<< oblicz(coefficients, 3, 1) << std::endl;

    return 0;
}