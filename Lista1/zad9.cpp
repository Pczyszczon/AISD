#include <iostream>
#include <fstream>
#include <string>

int* countOccurences(std::string fileName)
{
    std::ifstream file(fileName);
    const int N = 128;
    char c;
    int* map = new int[N];

    for (int i = 0; i < N; i++)
        map[i] = 0;

    while (file.get(c))
    {
        //std::cout << c << "->" << (int)c << std::endl;
        map[(int)c]++;
    }
        
    file.close();

    return map;
}

void print(int data[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "Ascii code: " << i << ", occurences: " << data[i] << std::endl;
    }
}

int main()
{
    int* result = countOccurences("ascii.txt");

    print(result, 128);

    return 0;
}