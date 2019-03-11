#include <iostream>

class Node
{
    public:
    int x;
    Node* left;
    Node* right;
    Node* parent;

    Node(int x, Node* left = nullptr, Node* right = nullptr, Node* parent = nullptr) :
    x(x), left(left), right(right), parent(parent)
    {}
};

void inorder_do(Node* root, void f(Node*))
{
    bool leftDone = false;

    while(root != nullptr){
        if (!leftDone)
        {
            while (root->left != nullptr)
                root = root->left;
        }

        f(root);
        leftDone = true;

        if (root->right != nullptr)
        {
            leftDone = false;
            root = root->right;
        }

        else if (root->parent != nullptr)
        {
            while(root->parent != nullptr && root == root->parent->right){
                root = root->parent;
            }

            if (root->parent == nullptr)
                break;
            root = root->parent;
        }
        else
            break;
    }
    
}

void func(Node* node)
{
    if (node != nullptr)
        std::cout << node->x << std::endl;
}

int main()
{
    Node* left1 = new Node(5);
    Node* right1 = new Node(100);

    Node* root = new Node(10, left1, right1);
    left1->parent = root;
    right1->parent = root;

    Node* left2 = new Node(80, nullptr, nullptr, right1);
    Node* right2 = new Node(120, nullptr, nullptr, right1);
    right1->left = left2;
    right1->right = right2;
    inorder_do(root, func);
}