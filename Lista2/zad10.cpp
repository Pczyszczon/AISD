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

void in_order(Node *& t)
{
    if (t != nullptr)
    {
        in_order(t->left);
        std::cout << t->x << " ";
        in_order(t->right);
    }
}

Node* find(Node *t, int x)
{
    while(t && t->x != x)
	{
		if(x < t->x) 
			t = t->left; 
		else
			t = t->right; 
	}
	return t;
}

void remove(Node *&t, int x)
{
	Node **t1=&t;
	while (*t1 && (*t1)->x!=x)
	{
		if(x<(*t1)->x) 
			t1=&((*t1)->left); 
		else
			t1=&((*t1)->right); 
	}
	if(*t1)
	{
		if((*t1)->right && (*t1)->left)
		{
			Node **t2=&((*t1)->right);
			while ((*t2)->left)
				t2=&((*t2)->left);
			(*t1)->x=(*t2)->x;
			t1=t2;
		}	
		if((*t1)->left==nullptr)
		{
			Node *d=(*t1)->right;
			delete *t1;
			(*t1)=d;
		}
		else
		{
		    Node *d=(*t1)->left;	
			delete *t1;
			(*t1)=d;
		}
	}
}

int main()
{
    Node *t = new Node(10);
    insert(t, 15);
    insert(t, 5);
    insert(t, 20);
    insert(t, 8);
    insert(t, 7);
    in_order(t);

    std::cout << std::endl;
    std::cout << "Node \'7\' adress:" << find(t, 7) << std::endl;
    std::cout << "Node \'10\' adress:" << find(t, 10) << std::endl;

    std::cout << "Remove node \'10\'" << std::endl;
    remove(t, 10);
    in_order(t);

    std::cout << "Remove node \'5\'" << std::endl;
    remove(t, 5);
    in_order(t);
}