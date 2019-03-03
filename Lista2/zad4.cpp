#include <iostream>

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void shift2(int A[], int n, int k)
{
    for (int i = 1; i < n; i++)
    {
        int temp = A[i];
        int next = (i + k) % n;
        A[i] = A[next];
        A[next] = temp;
    }
}

void shift(int A[], int n, int k)
{
    int cycle_length, cycle_number, current, next, temp;

    cycle_number = gcd(n,k);
    cycle_length = n / cycle_number;
    std::cout << "Cycle number: " << cycle_number << ", length: " << cycle_length << std::endl;

    for (int i = 0; i < cycle_number; i++)
    {
        current = A[i];
        next = (i + k) % n;

        for (int j = 1; j < cycle_length + 1; j++)
        {
            temp = A[next];
            A[next] = current;
            current = temp;
            next = (next + k) % n;
        }
    }
}

int main()
{
    int A[] = {1,2,3,4,5,6,7,8,9,10};
    shift(A, 10, 6);
    for (int i = 0; i < 10; i++)
        std::cout << A[i] << " ";
    std::cout << std::endl;

    int B[] = {1,2,3,4,5,6};
    shift2(B, 6, 5);
    for (int i = 0; i < 6; i++)
        std::cout << B[i] << " ";
    std::cout << std::endl;


    return 0;
}