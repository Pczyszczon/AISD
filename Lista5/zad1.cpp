#include <cmath>
#include <iostream>

int getBucketIndex(double x, int n, int a, int b) {
    if (a > b) return -1;
    
    return (x-a)/(b-a)*n;
}

int main() {
    int a = 3;
    int b = 7;
    int n = 4;
    for (double i = a; i <= b; i+=0.20) {
        std::cout << "x = " << i << ", index = " 
            << getBucketIndex(i, n, a, b) << std::endl;
    }
}