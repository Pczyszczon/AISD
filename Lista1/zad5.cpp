#include <iostream>

struct lnode
{
    int key;
    lnode *next;
};

int nty(int n, lnode *key)
{
    int counter = -1;

    lnode *temp = key;
    while (temp != NULL)
    {
        counter++;
        if (counter == n)
        {
            return temp->key;
        }
        temp = temp->next;
    }

    //if (counter > n) {return -1;}

    return -1;
}

int main()
{
    lnode head;
    head.key = 1;
    lnode l1, l2, l3;
    l1.key = 2;
    l2.key = 3;
    l3.key = 4;

    head.next = &l1;
    l1.next = &l2;
    l2.next = &l3;

    for (int i = 0; i < 6; i++)
    {
        std::cout << "Nr:" << i << " " << nty(i, &head) << std::endl;
    }

    return 0;
}