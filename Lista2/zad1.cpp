#include <iostream>

int binary_search(int t[], unsigned int n, int x, int l, int r)
{
    if (l > r)
        return -1;

    int m = (l+r)/2;

    if (t[m] == x)
        return m;

    if (t[m] > x)
        return binary_search(t, n/2, x, l, m);
    
    else
        return binary_search(t, n/2, x, m + 1, r);
}

int main()
{
    int t[] = {1,2,3,4,5};

    std::cout << binary_search(t, 5, 1, 0, 4) << std::endl;
    std::cout << binary_search(t, 5, 4, 0, 4) << std::endl;
    std::cout << binary_search(t, 5, 8, 0, 4) << std::endl;
    std::cout << binary_search(t, 5, 5, 0, 4) << std::endl;
    
    return 0;
}
