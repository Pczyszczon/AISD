#include <iostream>
#include <limits>

int maxSum(int T[], int n, int k) {
    if (k > n) {
        std::cout << "Invalid data" << std::endl;
        return std::numeric_limits<int>::min();
    }

    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += T[i];
    }

    int currentSum = sum;
    for (int i = k; i < n; i++) {
        currentSum -= T[i-k];
        currentSum += T[i];

        if (currentSum > sum) {
            sum = currentSum;
        }
    }

    return sum;
}

int main() {
    int t[] = {1, 2, 3, 4, 5, 6, 7, 8, -1, 100, 2, 5};
    std::cout << "Max sum = " << maxSum(t, 12, 3) << std::endl;
}