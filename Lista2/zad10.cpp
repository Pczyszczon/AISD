#include <iostream>

class Node
{ 
    public:
	int x;
	Node* left;
	Node* right;
	
	Node(int x0, Node* l=nullptr, Node* r=nullptr)
		:x(x0), left(l), right(r)
	{}
};


void insert(Node *& root, int x)
{
    Node* current = root;
    Node* parent = nullptr;

    if (root == nullptr)
    {
        root = new Node(x);
    }

    while (current != nullptr)
    {
        parent = current;

        if (x < current->x)
        {
            current = current->left;
        }

        else
        {
            current = current->right;
        }
    }

    if (x < parent->x)
    {
        parent->left = new Node(x);
    }

    else
    {
        parent->right = new Node(x);
    }
    
}

void insert_r(Node *& root, int x)
{
    if (root == nullptr)
    {
        root = new Node(x);
        return;
    }

    if (root->x > x)
        insert_r(root->left, x);

    else
        insert_r(root->right, x);
}

void in_order(Node *& root)
{
    if (root != nullptr)
    {
        in_order(root->left);
        std::cout << root->x << " ";
        in_order(root->right);
    }
    
}

Node* find_r(Node *& root, int x)
{
    if (root == nullptr)
        return nullptr;

    else
    {
        if (x == root->x)
            return root;
        
        else if (x < root->x)
            find_r(root->left, x);
        
        else
            find_r(root->right, x);
    }
}

Node* find(Node *& root, int x)
{
    if (root == nullptr)
        return nullptr;

    Node* current = root;

    while (current != nullptr)
    {
        if (x == current->x)
            return current;

        else if (x < current->x)
            current = current->left;
        
        else
            current = current->right;
    }
}

//zad13
void inorder_do(Node* root, void f(Node*))
{
    if (root == nullptr)
        return;

    inorder_do(root->left, f);
    f(root);
    inorder_do(root->right, f);
}

void func(Node* node)
{
    node->x = node->x + 1;
}

int height(Node* root)
{
    if (root == nullptr)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    if (left > right)
        return 1 + left;
    else
        return 1 + right;
}

int main()
{
    Node *rightChild = new Node(8);
    Node *leftChild = new Node(2);
    Node *root = new Node(5, leftChild, rightChild);

    in_order(root);

    std::cout << std::endl;
    /*
    std::cout << find(root, 8) << ", " << find(root, 5) << ", "
              << find(root, -1) << std::endl;
    */

    //removes2(root, 5);
    inorder_do(root, func);
    in_order(root);
    std::cout << height(root);
    //Complexity for find, insert, remove -> O(h)
}