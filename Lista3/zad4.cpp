#include <iostream>
#include <cmath>

class Node
{
  public:
    int data;
    Node *next;

    Node(int data, Node *next) : data(data), next(next)
    {
    }
};

class LinkedList
{
  public:
    LinkedList() : head(nullptr) {}

    LinkedList(Node *head) : head(head) {}

    void insert(int value)
    {
        Node *node = new Node(value, nullptr);
        if (head == nullptr)
        {
            node->next = head;
            head = node;
        }
        else
        {
            Node *current = head;
            while (current->next)
            {
                current = current->next;
            }
            current->next = node;
        }
    }

    void sortedInsert(int value)
    {
        Node *node = new Node(value, nullptr);
        Node *current = head;

        if (head == nullptr)
        {
            insert(value);
        }

        else if (head->data > value)
        {
            node->next = head;
            head = node;
        }
        else
        {
            while (current->next && current->next->data < value)
            {
                current = current->next;
            }
            node->next = current->next;
            current->next = node;
        }
    }

    void insertionSort(Node *&listHead)
    {
        LinkedList result;
        while (listHead)
        {
            result.sortedInsert(listHead->data);
            result.print();
            listHead = listHead->next;
        }
        head = result.head;
    }

    void print()
    {
        Node *current = head;
        while (current)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void sort()
    {
        insertionSort(head);
    }

    int length()
    {
        Node *tmp = head;
        int length = 0;
        while (tmp)
        {
            length++;
            tmp = tmp->next;
        }
        return length;
    }

    Node *head;
};

int length(Node *head)
{
    int length = 0;
    while (head)
    {
        length++;
        head = head->next;
    }
    return length;
}

Node *merge(Node *L1, Node *L2)
{
    Node *result = new Node(-9999, nullptr);
    Node **tail = &result;

    while (1)
    {
        if (L1 == nullptr)
        {
            (*tail)->next = L2;
            break;
        }

        else if (L2 == nullptr)
        {
            (*tail)->next = L1;
            break;
        }

        if (L1->data >= L2->data)
        {
            (*tail)->next = L2;
            L2 = L2->next;
        }

        else
        {
            (*tail)->next = L1;
            L1 = L1->next;
        }

        tail = &((*tail)->next);
    }

    return result->next;
}

void splitInHalf(Node *source, Node *&leftHalf, Node *&rightHalf)
{

    if (source == nullptr || source->next == nullptr)
    {
        leftHalf = source;
        rightHalf = nullptr;
    }

    Node *slowPointer = source;
    Node *fastPointer = source->next;

    while (fastPointer != nullptr)
    {
        fastPointer = fastPointer->next;
        if (fastPointer != nullptr)
        {
            fastPointer = fastPointer->next;
            slowPointer = slowPointer->next;
        }
    }

    leftHalf = source;
    rightHalf = slowPointer->next;
    slowPointer->next = nullptr;
}

Node *getListSlice(Node *head, int left, int right)
{
    Node *current = head;
    int counter = 0;

    while (counter < left && current != nullptr)
    {
        counter++;
        current = current->next;
    }

    //std::cout<< "n = " << right - left << std::endl;
    //std::cout <<"Current ";

    LinkedList result;
    for (int i = 0; i < right - left; i++)
    {
        //std::cout << current->data << " ";
        if (current)
            result.insert(current->data);
        current = current->next;
    }

    return result.head;
}

void mergeSort(Node *&source)
{
    Node *head = source;
    Node *left;
    Node *right;

    if (head == nullptr || head->next == nullptr)
    {
        return;
    }

    splitInHalf(head, left, right);
    mergeSort(left);
    mergeSort(right);

    source = merge(left, right);
}

void Print(Node *head)
{
    while (head)
    {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

void iterMergeSort(Node *&head, int n)
{
    int size = length(head);
    while(size > 1) {
        int mid = size/2;
        Node* l = getListSlice(head, 0, mid);
        Print(l);
        Node* r = getListSlice(head, mid, size);
        Print(r);
        size = length(l);
    }
}

int main()
{
    LinkedList l1, l2;

    l1.insert(11);
    l1.insert(8);
    l1.insert(517);

    l2.insert(12);
    l2.insert(2);
    l2.insert(0);
    l2.insert(19);

    Node *result = merge(l1.head, l2.head);
    LinkedList resultList(result);
    resultList.print();

    iterMergeSort(resultList.head, resultList.length());
    resultList.print();
}