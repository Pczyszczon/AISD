#include <iostream>

class Node
{
    public:
    int data;
    Node* next;

    Node(int data, Node* next) : data(data), next(next) 
    {}
};

class LinkedList
{
    private:
    Node* head;

    public:
    LinkedList() : head(nullptr) {}

    void insert(int value) {
        Node* node = new Node(value, nullptr);
        if (head == nullptr) {
            node->next = head;
            head = node;
        }
        else {
            Node* current = head;
            while(current->next) {
                current = current->next;
            }
            current->next = node;
        }
    }

    void sortedInsert(int value) {
        Node* node = new Node(value, nullptr);
        Node* current = head;

        if (head == nullptr) {
            insert(value);
        }

        else if (head->data > value) {
            node->next = head;
            head = node;
        }
        else {
            while (current->next && current->next->data < value) {
                current = current->next;
            }
            node->next = current->next;
            current->next = node;
        }
    }

    void insertionSort(Node *& listHead) {
        LinkedList result;
        while (listHead) {
            result.sortedInsert(listHead->data);
            result.print();
            listHead = listHead->next;
        }
        head = result.head;
    }

    void print() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void sort() {
        insertionSort(head);
    }

};

int main() {
    LinkedList list;
    list.insert(9);
    list.insert(2);
    list.insert(0);
    list.insert(7);
    list.insert(144);
    list.print();

    list.sortedInsert(1);
    list.print();

    list.sortedInsert(-5);
    list.print();

    list.sortedInsert(0);
    list.print();

    std::cout << "Insertion sort steps for list \n";
    list.print();
    list.sort();

    return 0;
}