#include <iostream>
#include <cmath>

int k_th(int x, unsigned int k) {
    int length = floor(log10(x)) + 1;
    int result = 0;
    for (int i = length; i!=k; i--) {
        result = x % 10;
        x = x / 10;
    }
    return result;
}

int k_th1000(int x, unsigned int k) {
    //logb x = logk x / logk b
    //log1000 x = log2(x) / log2(b)
    int log = log2(x) / log2(10000);
    int length = floor(log) + 1;
    int result = 0;
    for (int i = length; i!=k; i--) {
        result = x % 10000;
        x = x / 10000;
    }
    return result;
}


int main() {
    int x = 56789999;
    //int n = floor(log10(x)) + 1;
    int n = 2;
    std::cout << "Length of " << x << ": " << n << std::endl;
    for (int k = 0; k<n; k++)
    {
        std::cout << k_th1000(x, k) << std::endl;
    }
}