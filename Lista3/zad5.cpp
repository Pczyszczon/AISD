#include <iostream>

void merge(int arr[], int start, int mid, int end) 
{ 
    int start2 = mid + 1; 
  
    if (arr[mid] <= arr[start2]) { 
        return; 
    } 
  
    while (start <= mid && start2 <= end) { 
  
        if (arr[start] <= arr[start2]) { 
            start++; 
        } 
        else { 
            int value = arr[start2]; 
            int index = start2; 
  
            while (index != start) { 
                arr[index] = arr[index - 1]; 
                index--; 
            } 
            arr[start] = value; 
  
            start++; 
            mid++; 
            start2++; 
        } 
    } 
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l+r)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
}

int main() {
    int t[] = {9, 3, 8, 2};
    int n = sizeof(t)/sizeof(t[0]);
    mergeSort(t, 0, n-1);

    for(int x : t) {
        std::cout << x << " ";
    }
    std::cout<<std::endl;
}

