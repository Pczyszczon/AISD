#include <limits>
#include <iostream>

void insertionSort(int a[], int N) {
    int v;
    a[0] = std::numeric_limits<int>::min();

    for (int i = 2; i <= N; i++) {
        v = a[i];
        int j = i;
        while (a[j-1] > v) {
            a[j] = a[j-1];
            j--;
        }
       a[j] = v;
    }
} 

int main() {
    int tab[] = {5, 1, 11, 22, 4, 2, 3, -11};
    int k = sizeof(tab)/sizeof(tab[0]);

    insertionSort(tab, k);

    for(auto x : tab) {
        std::cout << x << " ";
    }
}