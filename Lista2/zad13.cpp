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

void func2(Node* node)
{
    std::cout << node->x << " ";
}

void insert(Node *& t, int x)
{
    Node **t1=&t;
	while(*t1)
		if(x<(*t1)->x)
			t1=&((*t1)->left);
		else
			t1=&((*t1)->right);
	*t1=new Node(x);
}

int main()
{
    Node *root = new Node(10);
    insert(root, 15);
    insert(root, 5);
    insert(root, 20);
    insert(root, 8);
    insert(root, 7);

    inorder_do(root, func2);
    std::cout << std::endl;

    inorder_do(root, func);
    std::cout << std::endl;
    
    inorder_do(root, func2);
    std::cout << std::endl;

}