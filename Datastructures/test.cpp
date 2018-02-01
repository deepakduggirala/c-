#include<iostream>
using namespace std;
struct Node
{
	Node *parent;
	Node *left;
	Node *right;
	int key;
};

class BST
{
	Node *root;
	public:
		BST();
		void inorderTT(void)
		{
			inorderTT(root);
		}
		void inorderTT(Node* &t); 	//inorder tree traversal starting at 
		
		Node *find(int value)
		{
			return find(value,root);
		} 
		Node *find(int value, Node* &t);	//search for a node containing the key as value
		
		int minVal(void)
		{
			return minVal(root);
		}
		int minVal(Node *&t);
		int maxVal(void)
		{
			return maxVal(root);
		}
		int maxVal(Node *&t);
		
		void insert(int z);	//insert an element with key z into the tree
		
};

BST::BST()
{
	root = NULL;
}
void BST::inorderTT(Node* &t)
{
	if(t != NULL)
	{
		inorderTT(t->left);
		cout<<t->key<<endl;
		inorderTT(t->right);
	}
}

Node* BST::find(int value, Node* &t)
{
	while(t!=NULL)
	{
		if(t->key == value) //found
			return t;
		if(value<t->key)
			t = t->left;
		else
			t = t->right;
	}
	return  NULL; //not found
}


int BST::minVal(Node* &t)
{
	//Assume t is not empty
	while(t->left != NULL)
	{
		t=t->left;
	}
	return t->key;
}

int BST::maxVal(Node* &t)
{
	//Assume t is not empty
	while(t->right != NULL)
	{
		t=t->right;
	}
	return t->key;
}


void BST::insert(int z_key)
{
	cout<<"got thru here";
	Node *z = new Node;
	z->key = z_key;
	Node *y,*x;
	y = NULL;
	x = root;
	
	while(x!=NULL)
	{
		y = x;
		if(z->key < x->key)
		{
			x = x->left;
		}
		else
		{
			x = x->right;
		}
	}
	z->parent = y;
	if(y == NULL)
	{
		root = z;
	}
	
	else if(z->key < y->key)
	{
		y->left = z;
	}
	else
	{
		y->right = z;
	}
	
}



int main()
{
	BST btree;
	btree.insert(1);
	btree.inorderTT();
}
