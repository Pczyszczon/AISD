#include <iostream>

void sito(unsigned int n)
{
    bool prime[n];

    for (int i = 0; i <= n; i++)
    {
        prime[i] = true;
    }

    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i = i + p)
            {
                prime[i] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (prime[i])
            std::cout << i << std::endl;
    }
}

int main()
{
    sito(10);
    return 0;
}