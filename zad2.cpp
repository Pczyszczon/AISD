#include <iostream>
#include <cmath>

double f(double x)
{
    return x*x - 3;
}

void findRoot(double a, double b)
{
    const double eps = 0.00000001;
    const int maxIterations = 1000;
    int iterations = 0;
    double c = a;

    while ( /*fabs(b - a) >= eps && */ iterations < maxIterations)
    {
        c = (a + b)/2;

        if (fabs(f(c)) < eps)
        {
            std::cout << "x = " << c << std::endl;
            break;
        }
            

        else if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;

        iterations++;
    }

    if (iterations >= maxIterations) {std::cout << "Wykryto zapętlenie, liczba iteracji: " << iterations << std::endl;}

}

int main()
{
    findRoot(1, 4);
    findRoot(0, 3);
    findRoot(-4, -1);
}