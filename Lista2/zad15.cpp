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

int height(Node* t)
{
    if (t == nullptr)
        return 0;

    int left = height(t->left);
    int right = height(t->right);

    if (left > right)
        return 1 + left;
    else
        return 1 + right;
}

int main()
{
    Node *root = new Node(5);
    insert(root,3);
    insert(root,7);
    insert(root,1);
    insert(root,4);
    insert(root,10);
    insert(root,15);
    std::cout << "Height = " << height(root) << std::endl; 
}