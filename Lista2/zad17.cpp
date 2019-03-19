#include <iostream>
#include <stack>
#include <iterator>

class Node
{
    public:
    int x;
    Node* left;
    Node* right;
  
    Node(int x, Node* left = nullptr, Node* right = nullptr) :
    x(x), left(left), right(right)
    {}
};

class BST
{
    private:
    Node* root;

    public:

    class Iterator;

    Iterator begin()
    {
        return Iterator(root);
    }

    Iterator end()
    {
        return Iterator(nullptr);
    }

    BST()
    {
        root = nullptr;
    }

    void insert(int x)
    {
        Node **t1=&root;
        while(*t1)
            if(x<(*t1)->x)
                t1=&((*t1)->left);
            else
                t1=&((*t1)->right);
        *t1=new Node(x);
    }

    void display(Node *node)
    {
        if (node)
        {
            display(node->left);
            std::cout << node->x << " ";
            display(node->right);
        }
    }

    void display()
    {
        display(root);
        std::cout << std::endl;
    }

    class Iterator
    {
        public: 
        Iterator(Node* root)
        {
            pushIntoStack(root);
            current = root;
        }
  
        Iterator& operator=(Node* root) 
        { 
            this->current = root; 
            return *this; 
        }

        Iterator operator++(int) 
        { 
            if (hasNext())
            {
                current = next();
                //std::cout << "Current = " << current->x << std::endl;
            }

            else
                current = nullptr; 
             
            return *this; 
        } 
  
        bool operator!=(const Iterator& iterator) 
        { 
            return current != iterator.current; 
        } 
  
        Node* operator*() 
        { 
            return current; 
        } 
  
        private: 
        Node* current;
        std::stack<Node*> stack;

        void pushIntoStack(Node* root)
        {
            while (root != nullptr)
            {
                stack.push(root);
                root = root->left;
            }
        }

        bool hasNext()
        {
            return !stack.empty();
        }

        Node* next()
        {
            Node* current = stack.top();
            stack.pop();
            pushIntoStack(current->right);
            return current;
        } 
    };
};

int main()
{
    BST bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(1);
    bst.insert(7);
    bst.insert(4);
    //bst.display();

    for (BST::Iterator it = (bst.begin())++; it!=bst.end(); it++)
    {
        std::cout << (*it)->x << " ";
    }

}