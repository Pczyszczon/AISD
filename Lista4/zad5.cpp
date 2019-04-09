#include <iostream>

using namespace std;

void przesiej (double t[],int i, int n)
{
  int k;  // syn większy od ojca i brata
  double x = t[i]; //przesiewany element
  while(
        ( (k=2*i+2) < n && t[k] > x && t[k] > t[k-1] ) 
        || 
        (   --k < n && t[k] > x)
    )
    {
        t[i] = t[k];
        i  =   k;
    }
 
   t[i] = x;
}

void przesiej_w_gore (double t[],int i, double x)
{
  // początkowo x = t[i] 
  int k; // ojciec i 
  while( i && t[k=(i-1)/2] < x )
  {
       t[i] = t[k];
       i  =   k;
  }
  t[i] = x;
}

class heap
{
    double *t;
    int n;
    public:
    
    heap(double *t0, int n0=0):t(t0),n(n0)
    {
        build_heap();
    }

    void build_heap()
    {
        int i=n/2; // budowa kopca 
        while(i) 
            przesiej (t, --i, n);
    }
    
    void insert(double x)
    {
        przesiej_w_gore(t,n++,x);
    }

    double max()
    {
        return t[0];
    }

    double get_max()
    {
        double res=t[0];
        t[0]=t[--n];
        przesiej(t,0,n);
        return res;
    }
    
};

class priorityQueue
{
    private:
    double *t;
    int n;
    int capacity;

    public:

    priorityQueue(double *t0, int capacity, int n0=0):t(t0),n(n0)
    {
        build_heap();
        this->capacity = capacity;
    }

    void build_heap()
    {
        int i=n/2;
        while(i) 
            przesiej (t, --i, n);
    }
    
    void put(double x)
    {
        przesiej_w_gore(t, n++, x);
        std::cout << "Current size:" << n << std::endl;
    }

    double get_max()
    {
        double res=t[0];
        t[0]=t[--n];
        przesiej(t,0,n);
        return res;
    }

    double max()
    {
        return t[0];
    }
    bool is_empty()
    {
        return n <= 0;
    }
    bool is_full()
    {
        return n >= capacity;
    }
};

int main()
{
    const int N = 4;
    double t[N];
    priorityQueue *q = new priorityQueue(t, N);
    /*
    q->put(2);
    std::cout << "full: " << q->is_full() << std::endl;
    q->put(3);
    std::cout << "full: " << q->is_full() << std::endl;
    q->put(1);
    std::cout << "full: " << q->is_full() << std::endl;
    q->put(4);
    std::cout << "full: " << q->is_full() << std::endl;

    std::cout << "Max:" << q->get_max() << ", empty: " <<q->is_empty() << std::endl;
    std::cout << "full: " << q->is_full() << std::endl;
    q->put(4);
    std::cout << "full: " << q->is_full() << std::endl;
    std::cout << "Max:" << q->get_max() << ", empty: " <<q->is_empty() << std::endl;
    std::cout << "Max:" << q->get_max() << ", empty: " <<q->is_empty() << std::endl;
    */
    q->put(1);
    q->put(2);
    q->put(3);;

    while(!q->is_empty()) {
        std::cout<<q->get_max();
    }
}