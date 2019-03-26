#include <iostream>
#include <queue>

class Node
{
    public:
    int x;
    Node *left;
    Node *right;

    Node(int x0, Node *l = nullptr, Node *r = nullptr)
        : x(x0), left(l), right(r)
    {
    }
};

void insert(Node *&t, int x)
{
    Node **t1 = &t;
    while (*t1)
        if (x < (*t1)->x)
            t1 = &((*t1)->left);
        else
            t1 = &((*t1)->right);
    *t1 = new Node(x);
}

int getLevel(Node *root, int data, int level)
{
    if (root == nullptr)
        return 0;
    if (root->x == data)
        return level;
    
    int down = getLevel(root->left, data, level+1);
    if (down != 0)
        return down;
    
    down = getLevel(root->right, data, level+1);
    return down;
}

int getLevelIter(Node* root, int data)
{
    std::queue<Node*> q;
    q.push(root);
    int level = 1;
    q.push(nullptr);

    while (!q.empty())
    {
        Node* current = q.front();
        q.pop();
        if (current == nullptr)
        {
            if (q.front() != nullptr)
            {
                q.push(nullptr);
            }
            level += 1;
        }
        else
        {
            if (current->x == data)
                return level;
            if (current->left != nullptr)
                q.push(current->left);
            if (current->right != nullptr)
                q.push(current->right);
        } 
    }

    return 0;
}

int main()
{
    Node* root = new Node(5);
    insert(root,1);
    insert(root,8);
    insert(root,3);
    insert(root,0);
    insert(root,9);
    std::cout << "Recursive\n";
    std::cout << "Level of 0 = " << getLevel(root, 0, 1) << std::endl;
    std::cout << "Level of 5 = " << getLevel(root, 5, 1) << std::endl;
    std::cout << "Level of 8 = " << getLevel(root, 8, 1) << std::endl;
    std::cout << "Level of 3 = " << getLevel(root, 3, 1) << std::endl;
    std::cout << "Level of 9 = " << getLevel(root, 9, 1) << std::endl;

    std::cout << "Iterative\n";
    std::cout << "Level of 0 = " << getLevelIter(root, 0) << std::endl;
    std::cout << "Level of 5 = " << getLevelIter(root, 5) << std::endl;
    std::cout << "Level of 8 = " << getLevelIter(root, 8) << std::endl;
    std::cout << "Level of 3 = " << getLevelIter(root, 3) << std::endl;
    std::cout << "Level of 9 = " << getLevelIter(root, 9) << std::endl;
}