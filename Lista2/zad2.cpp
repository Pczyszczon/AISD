#include <iostream>

// max = M(1) -> jedna zmienna na maximum
// max = O(n) -> n - 1 porównań w najgorszym przypadku
int max(int t[], int n)
{
    int x=t[--n];
    while(n--)
        if(t[n] > x) 
            x = t[n];
    return x;
}

// max_r = M(n) -> 1 zmienna max, lecz tworzona n razy
// max_r = O(n) -> n - 1 porównań
int max_r(int t[], int n)
{
    if (n==1)
        return t[0];

    double max = max_r(t, n-1);

    if (t[n] > max)
        return t[n];

    return max;
}
//liczba porownan na kazda pare -> 3
//liczba par -> ceil(n/2)
//liczba porownan 3n/2
//pamiec -> 3 zmienne na kazda pare, stad 3n/2 -> M(n)
int max_r2(int t[], int n, int l, int r)
{
    if (n < 1)
        return -1;
    if (n == 1)
        return t[0];

    int max;

    if (n == 2)
    {
        max = t[l];
        if (t[r] > max)
            max = t[r];
        
        return max;
    }

    int m = (l+r)/2;
    int max1 = max_r2(t, n/2, l, m);
    int max2 = max_r2(t, n/2, m + 1, r);

    if (max1 > max2)
        max = max1;
    else
        max = max2;
    return max;
}

int main()
{
    int t1[] = {2, 5, 6, 10, 11, 205, 206, 3, -100, 300};
    int m1 = max_r2(t1, 10, 0, 9);

    std::cout << "max z t1 = " << m1 << std::endl;

    return 0;
}