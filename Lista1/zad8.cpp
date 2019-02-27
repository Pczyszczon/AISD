#include <iostream>

class Fraction
{
    public:
    Fraction(int n, int d = 1)
    {
        int r = gcd(n, d);
        nominator = n/r;
        denominator = d/r;    
    }

    int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a%b);
    }

    int nominator;
    int denominator;
};

std::ostream& operator<<(std::ostream& stream, const Fraction& fraction)
{
    stream << fraction.nominator << "/" << fraction.denominator;
    return stream;
}

Fraction operator+(Fraction p, Fraction q)
{
    int n = p.nominator * q.denominator + q.nominator * p.denominator;
    int d = p.denominator * q.denominator;

    return Fraction(n, d);
}

Fraction operator-(Fraction p, Fraction q)
{
    int n = p.nominator * q.denominator - q.nominator * p.denominator;
    int d = p.denominator * q.denominator;

    return Fraction(n, d);
}

Fraction operator*(Fraction p, Fraction q)
{
    int n = p.nominator * q.nominator;
    int d = p.denominator * q.denominator;

    return Fraction(n, d);
}

Fraction operator/(Fraction p, Fraction q)
{
    if (q.denominator == 0)
    {
        std::cout << "Dividing by 0!" << std::endl;
        q = Fraction(1,1);
    }

    int n = p.nominator * q.denominator;
    int d = p.denominator * q.nominator;

    return Fraction(n, d);
}


int main()
{
    Fraction f(1,3);
    Fraction g(2, 3);

    std::cout << f << " + " << g << " = " << f + g <<std::endl;
    std::cout << f << " - " << g << " = " << f - g <<std::endl;
    std::cout << f << " * " << g << " = " << f * g <<std::endl;
    std::cout << f << " / " << g << " = " << f / g <<std::endl;

    return 0;
}