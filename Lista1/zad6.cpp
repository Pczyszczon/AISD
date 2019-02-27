#include <iostream>

class Pair
{
    public:
    int min;
    int max;
};

Pair minMax(int arr[], int l, int h)
{
    Pair minmax, mml, mmr;
    int mid;
    
    if (l == h)
    {
        minmax.min = arr[l];
        minmax.max = arr[h];
        return minmax;
    }

    if (l == h - 1)
    {
        if (arr[l] > arr[h])
        {
            minmax.max = arr[l];
            minmax.min = arr[h];
        }
        else
        {
            minmax.max = arr[h];
            minmax.min = arr[l];
        }
        return minmax;
    }

    mid = (l+h)/2;
    mml = minMax(arr, l, mid);
    mmr = minMax(arr, mid + 1, h);

    if (mml.min > mmr.min)
        minmax.min = mmr.min;
    else
        minmax.min = mml.min;

    if (mml.max > mmr.max)
        minmax.max = mml.max;
    else
        minmax.max = mmr.max;
    
    return minmax;
}

int main()
{
    int arr[] = {0, 100, 20, 5, 30, 121};
    Pair minmax = minMax(arr, 0, 5);
    std::cout << "min:" << minmax.min << ", max:" << minmax.max << std::endl;
    return 0;
}