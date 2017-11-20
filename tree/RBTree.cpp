#include<iostream>
using namespace std;

enum RBColor{RED,BLACK};


template<class T>
class Node{
public:
	T key;
	RBColor color;
	Node *left;
	Node *right;
	Node *parent;

	Node(T val,RBColor c,Node *l,Node *r,Node *p):key(val),color(c),left(l),right(r),parent(p){}
};

template<class T>
class RBTree{
private:
	Node<T> *root;

public:
	RBTree();
	~RBTree();

	void preOrder();
	void inOrder();
	void postOrder();

	Node<T>* recusiveSearch(T key);
	Node<T>* iterativeSearch(T key);

	T Minimum();
	T Maximum();

	Node<T>* successor(Node<T> *x);
	Node<T>* predecessor(Node<T> *x);

	void insert(T key);
	void remove(T key);

	void destroy();

	void print();

private:
	void preOrder(Node<T> *tree) const;
	void inOrder(Node<T> *tree) const;
	void postOrder(Node<T> *tree) const;

	Node<T>* recusiveSearch(Node<T> *x,T key) const;
	Node<T>* iterativeSearch(Node<T> *x,T key) const;

	Node<T>* Minimum(Node<T> *tree);
	Node<T>* Maximum(Node<T> *tree);

	void leftRotate(Node<T> *&tree,Node<T> *x);
	void rightRotate(Node<T> *&tree,Node<T> *x);

	void insert(Node<T> *&tree,Node<T> *x);
	void insertFixUp(Node<T> *&tree,Node<T> *x);
	void remove(Node<T> *&tree,Node<T> *x);

	void destroy(Node<T> *&tree);

	void print(Node<T> *&tree,T key,int direction);

}

void RBTree<T>::leftRotate(Node<T> *&tree,Node<T> *x){
	Node<T> *y=x->right;
	x->right=y->left;
	if(y->left!=NULL)
		y->left->parent=x;
	y->parent=x->parent;
	if(x->parent==NULL)
		root=y;
	else
	{
		if(x->parent->left==x)
			x->parent->left=y;
		else
			x->parent->right=y;
	}
	y->left=x;
	x->parent=y;
}

void RBTree<T>::rightRotate(Node<T> *&tree,Node<T> *x){
	Node<T> *y=x->left;
	x->left=y->right;
	if(y->right!=NULL)
		y->right->parent=x;
	y->parent=x->parent;
	if(x->parent==NULL)
		root=y;
	else if(x=x->parent->left)
		x->parent->left=y;
	else 
		x->parent->right=y;

	y->right=x;
	x->parent=y;
}

template<class T>
void RBTree<T>::insert(Node<T> *&tree,Node<T> *x){
	Node<T> *y=NULL;
	Node<T> *z=tree->root;
	while(z!=NULL)
	{
		y=z;
		if(x->key<z->key)
			z=z->left;
		else
			z=z->right;
	}
	x->parent=y;
	if(y==NULL)
		root=x;
	else if(x->key<y->key)
		y->left=x;
	else
		y->right=x;
	x->color=RED;
	insertFixUp(root,x);
}

template<class T>
void RBTree<T>::insert(key T){
	Node<T> *z=new Node<T>(key,BLACK,NULL,NULL,NULL);
	insert(root,z);
}



template<class T>
void insertFixUp(Node<T> *&tree,Node<T> *x){
	while(x->parent&&x->parent->color==RED)
	{
		if(x->parent==x->parent->parent->left)
		{
			Node<T> *y=x->parent->parent->right;
			if(y->color==RED)
			{
				x->parent->color=BLACK;
				x->parent->parent->color=RED;
				y->color=BLACK;
				x=x->parent->parent;
			}
			else if(x=x->parent->right)
			{
				x=x->parent;
				leftRotate(root,x);
			}
			else
			{
				x->parent->color=BLACK;
				x->parent->parent->color=RED;
				rightRotate(root,x->parent->parent);
			}


		}
		else
		{
			Node<T> *y=x->parent->parent->left;
			if(y->color==RED)
			{
				x->parent->color=BLACK;
				x->parent->parent->color=RED;
				y->color=BLACK;
				x=x->parent->parent;
			}
			else if(x=x->parent->left)
			{
				x=x->parent;
				rightRotate(root,x);
			}
			else
			{
				x->parent->color=BLACK;
				x->parent->parent->color=BLACK;
				leftRotate(root,x->parent->parent);
			}

		}
	}
	root->color=BLACK;
}




