#include <iostream>
#include <stack>

class Node
{
    public:
    int x;
    Node* left;
    Node* right;
  
    Node(int x, Node* left = nullptr, Node* right = nullptr) :
    x(x), left(left), right(right)
    {}

    void insert_recursive(Node *& t, int x)
    {  
	    if(t == nullptr)
		    t = new Node(x);
	    else
		    if(x<t->x)
			    insert_recursive(t->left,x); 
		    else
			    insert_recursive(t->right,x); 
    } 
};

class BstIterator
{
    private:
    std::stack<Node*> stack;

    void pushIntoStack(Node* root)
    {
        while (root != nullptr)
        {
            stack.push(root);
            root = root->left;
        }
    }

    public:
        BstIterator(Node* root)
        {
            pushIntoStack(root);
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

int main()
{
    Node* root = new Node(5);
    root->insert_recursive(root, 2);
    root->insert_recursive(root, 12);
    root->insert_recursive(root, 4);
    root->insert_recursive(root, 7);
    root->insert_recursive(root, 3);

    BstIterator it(root);
    while(it.hasNext())
    {
        std::cout << it.next()->x << " ";
    }

}