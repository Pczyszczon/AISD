#include <iostream>
#include <fstream>
#include <string>

int* multiply(int a[], int b[], int n, int m)
{
    int* c = new int[m+n-1];

    for (int i = 0; i < (m + n - 1); i++) 
        c[i] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            c[i+j] += a[i] * b[j];
        }
    }

    return c;
}

int getSizeFromFile(std::string name)
{
    std::string line;
    std::ifstream myfile (name);
    if (myfile.is_open())
    {
        int counter = 0;
        std::string::size_type sz;
        while (getline(myfile, line, ' '))
        {
            counter++;
        }
        myfile.close();
        return counter;
    }

    else 
        std::cout << "Unable to open file";
    return -1;
}

void readFromFile(int destinationArray[], std::string name)
{
    std::string line;
    std::ifstream myfile (name);
    if (myfile.is_open())
    {
        int counter = 0;
        std::string::size_type sz;
        while (getline(myfile, line, ' '))
        {
            //std::cout << line << '\n';
            destinationArray[counter] = std::stoi(line, &sz);
            counter++;
        }
        myfile.close();
    }

    else 
        std::cout << "Unable to open file";
}

int main()
{
    std::string fileA = "a.txt";
    std::string fileB = "b.txt";

    int n = getSizeFromFile(fileA);
    int m = getSizeFromFile(fileB);
    int a[n];
    int b[m];

    readFromFile(a, "a.txt");
    readFromFile(b, "b.txt");

    int* c = multiply(a, b, n, m);

    for(int i = 0; i < (m + n - 1); i++)
    {
        std::cout << c[i] << " ";
    }

    std::cout << std::endl;
    return 0;
}