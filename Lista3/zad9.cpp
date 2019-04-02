#include <iostream>

int T(int n)
{
    if (n < 0) 
        return -1;
    else if (n == 0 || n == 1)
        return 1;
    else
    {
        int result = 0;
        for (int i = 1; i <= n; i++)
            result += T(i-1) * T(n-i);
        return result;
    }
}

int T_iter(int n, long results[])
{
    results[0] = 1;
    results[1] = 1;
    int res = 0;
    for (int j = 1; j <= n; j++)
    {
        res += results[j-1]*results[n-j];
    }
    results[n] = res;    
}

void fillWithZeroes(long array[], int size)
{
    for (int i=0; i<size; i++)
        array[i] = 0;
}

int main()
{
    int N = 20;
    long res[N];
    fillWithZeroes(res, N);
    for (int i = 0; i < N; i++)
    {
        std::cout << i << ": result = " << T(i);
        T_iter(i, res);
        std::cout << ", Iter result = " << res[i] << std::endl;
    }
}