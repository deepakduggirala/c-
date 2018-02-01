/*	
	Date: 19-05-2015
	Author: Deepak Duggirala
	Description: This program implements the binary search tree data structure
*/
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
	public:
		Node *root; //pointer to root
		BST();
		void inorderTT(void)	//inorder tree traversal starting at root
		{
			inorderTT(root);
		}
		//function overloading
		void inorderTT(Node* t); 	//inorder tree traversal starting at node t
		
		Node *find(int value)
		{
			return find(value,root);
		} 
		Node *find(int value, Node* t);	//search for a node containing the key as value
		
		int minVal(void)
		{
			return minVal(root);
		}
		int minVal(Node *t);
		
		int maxVal(void)
		{
			return maxVal(root);
		}
		int maxVal(Node *t);
		void insert(int z);	//insert an element with key z into the tree
		
		int succ(int t1);//return successor of t1
		int pred(int t1);//return successor of t1
		void Delete(int z)
		{
			Delete(z,root);
		}
		void Delete(int z,Node* t); //delete z from tree t
};
BST::BST()
{
	root = NULL;
}

void BST::inorderTT(Node* t)
{
	if(t != NULL)
	{
		inorderTT(t->left);
		cout<<t->key<<endl;
		inorderTT(t->right);
	}
}

Node* BST::find(int value, Node* t)
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

int BST::minVal(Node* t)
{
	//Assume t is not empty
	while(t->left != NULL)
	{
		t=t->left;
	}
	return t->key;
}

int BST::maxVal(Node* t)
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
	Node *z = new Node;
	z->key = z_key;
	z->left=NULL;
	z->right=NULL;
	Node *y,*x;
	y=NULL;
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


int BST::succ(int t1)
{
	Node *t = find(t1);
	if(t->right !=NULL)
		return minVal(t->right);
	Node* y = t->parent;
	while(y!=NULL && t == y->right)
	{
		t=y;
		y = y->parent;
	}
	return y->key;
}

int BST::pred(int t1)
{
	Node *t = find(t1);
	if(t->left !=NULL)
		return maxVal(t->left);
	Node* y = t->parent;
	while(y!=NULL && t == y->left)
	{
		t=y;
		y = y->parent;
	}
	return y->key;
}

void BST::Delete(int V, Node* t)
{
	if(t==NULL) return;
	//Recursive cases, t.value != v
	if(V < t->key)
	{
		if(t->left != NULL)
		{
			Delete(V,t->left);
		}
		return;
	}
	if(V > t->key)
	{
		if(t->right != NULL)
		{
			Delete(V,t->right);
		}
		return;
	}
	//t.value == v, delete here
	//delete root (tree has only one element)
	if(t->parent == NULL && t->left == NULL && t->right == NULL)
	{
		t = NULL;
		return;
	}
	//Delete leaf
	if(t->left == NULL && t->right == NULL)
	{
		if(t == t->parent->left)
			t->parent->left = NULL;
		else
			t->parent->right = NULL;
		return;
	}
	//Delete node with one child
	//Only left child
	if(t->left != NULL && t->right == NULL)
	{
		t->left->parent = t->parent;
		if(t = t->parent->left)
			t->parent->left = t->left;
		else
			t->parent->right = t->left;
		return;
	}
	//Delete node with one child
	//Only right child
	if(t->left == NULL && t->right != NULL)
	{
		t->right->parent = t->parent;
		if(t = t->parent->right)
			t->parent->left = t->right;
		else
			t->parent->right = t->right;
		return;
	}
	//Delete node with two children
	//copy pred(v) into currrent node
	int pv = pred(V);
	t->key = pv;
	//Delete pv from left subtree
	//pv is either leaf or has single child
	Delete(pv,t->left);
}

int main()
{

	BST btree;

	btree.insert(5);
	btree.insert(2);
	btree.insert(3);
	btree.insert(1);
	btree.insert(7);
	btree.insert(6);
	btree.insert(8);

	btree.inorderTT();
	Node *x = btree.find(3);
	cout <<"parent of 3 is "<<x->parent->key<<endl;
	cout<<"min: "<<btree.minVal()<<endl;
	cout<<"\nMax is "<<btree.maxVal()<<endl;
	cout<<"successor of 3 is "<<btree.succ(3)<<endl;
	cout<<"predessor of 5 is "<<btree.pred(5)<<endl;
	btree.Delete(5);
	btree.inorderTT();
	
}
