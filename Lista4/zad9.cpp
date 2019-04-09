#include <iostream>
#include <algorithm>

int partition (double t[], int n)
{
  int k = -1;
  double x = t[0]; // pivot bierzemy posrodku
  for(;;)
  {
     while (t[--n] > x);
     while (t[++k] < x);
     if (k < n) std::swap(t[k],t[n]);
     else       return k;
  }
}

void quick_sort (double t[], int n)
{
  if (n > 1)
  {
    int k = partition (t,n); //podziel na dwie czesci
    quick_sort (t,k);	     //posortuj lewa
    quick_sort (t+k,n-k);    //posortuj prawa
  }
}

int main()
{
    double t[] = {7,6,5,4,3,2,1};
    partition(t, 7);
    for (int i = 0; i < 7; i ++)
        std::cout << t[i] << " ";
}