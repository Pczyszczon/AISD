#include <iostream>

class Node
{
    public:
    int value;
    Node *next;

    Node(int val, Node* nextNode) : value(val), next(nextNode)
    {}
};

void Print(Node *& head)
{
    Node* temp = head;
    while (temp != nullptr)
    {
        std::cout << temp->value << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

void Reverse(Node *& L)
{
    Node* current = L;
    Node* prev = nullptr;
    Node* next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    L = prev;
}

Node* Merge(Node *& L1, Node *& L2)
{
    Node* result = new Node(0, nullptr);
    Node* tail = result;

    while (1)
    {
        if (L1 == nullptr)
        {
            tail->next = L2;
            break;
        }

        else if (L2 == nullptr)
        {
            tail->next = L1;
            break;
        }

        if (L1->value >= L2->value)
        {
            tail->next = L2;
            L2 = L2->next;
        }

        else
        {
            tail->next = L1;
            L1 = L1->next;
        }

        tail = tail->next;
    }

    return result->next;
}

int main()
{
    Node* head = new Node(1, nullptr);
    Node* second = new Node(3, nullptr);
    Node* third = new Node(5, nullptr);

    head->next = second;
    second->next = third;

    //Print(head);

    //Reverse(head);

    //Print(head);


    Node* head2 = new Node(2, nullptr);
    Node* second2 = new Node(3, nullptr);
    Node* third2 = new Node(4, nullptr);

    head2->next = second2;
    second2->next = third2;

    Node* merged = Merge(head, head2);
    Print(merged);
}