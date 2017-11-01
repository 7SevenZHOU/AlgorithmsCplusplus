#include<iostream>
using namespace std;
template<class T>
struct Node
{
	T val;
	Node *left;
	Node *right;
	Node *parent;
};

template<class T>
class BSTree{
private:
	Node<T> *root;

public:
	BSTree();
	~BSTree();

	void preOrder();
	void inOrder();
	void postOrder();

	Node<T>* recursiveSearch(T key);

	Node<T>* iterativeSearch(T key)

	T Minimum();
	T Maximum();

	Node<T>* successor(Node<T> *x);
	Node<T>* predecessor(Node<T> *x);

	void insert(T key);
	void remove(T key);

	void destory();
	void print();

private:
	void preOrder(Node<T>* tree) const;
	void inOrder(Node<T>* tree) const;
	void postOrder(Node<T>* tree) const;

	Node<T>* recursiveSearch(Node<T> *tree,T key) const;
	BSTNode<T>* iterativeSearch(Node<T> *tree,T key) const;

	BSTNode<T>* Minimum(Node<T> *tree);
	BSTNode<T>* Maximum(BSTNode<T> *tree);

	void insert(Node<T> *&tree,Node<T> *z);

	Node<T>* remove(Node<T> *&tree,Node<T> *z);

	void destory(Node<T> *&tree);
	void print(Node<T> *tree,T key,int direction);

};

//preOrder
template<class T>
void BSTree<T>::preOrder(Node<T> *tree) const{
	if(tree!=NULL)
	{
		cout<<tree->key<<" ";
		preOrder(tree->left);
		preOrder(tree->right);
	}
}

template<class T>
void BSTree<T>::preOrder(){
	preOrder(root);
}


//inOrder
template<class T>
void BSTree<T>::inOrder(Node<T> *tree) const{
	if(tree!=NULL)
	{
		inOrder(tree->left);
		cout<<tree->key<<" ";
		inOrder(tree->right);
	}
}

template<class T>
void BSTree<T>::inOrder(){
	inOrder(root);
}



//postOrder
template<class T>
void BSTree<T>::postOrder(Node<T> *tree) const{
	if(tree!=NULL)
	{
		postOrder(tree->left);
		postOrder(tree->right);
		cout<<tree->key<<" ";
	}
}

template<class T>
void BSTree<T>::postOrder(){
	postOrder(root);
}



template<class T>
Node<T>* BSTree<T>::recursiveSearch(Node<T> *tree,T key) const{
	if(tree==NULL||tree->key==key)
	{
		return tree;
	}

	if(key<tree->key)
	{
		return search(tree->left,key);
	}
	else
		return search(tree->right,key);
}

template<class T>
Node<T>* BSTree<T>::recursiveSearch(T key){
	search(root,key);
}

template<class T>
Node<T>* BSTree<T>::iterativeSearch(Node<T> *tree,T key) const{
	while((tree!=NULL)&&(tree->key!=key))
	{
		if(key<tree->key)
			tree=tree->left;
		else
			tree=tree->right;
	}
	return tree;
}

template<class T>
Node<T>* BSTree<T>::iterativeSearch(T key){
	iterativeSearch(root,key);
}



template<class T>
Node<T>* BSTree<T>::Maximum(Node<T> *tree){
	if(tree==NULL)
		return NULL;
	while(tree->right!=NULL)
		tree=tree->right;
	return tree;
}

template<class T>
T BSTree<T>::Maximum(){
	Node<T> *p=Maximum(root);
	if(p!=NULL)
		return p->key;
	return (T)NULL;
}



template<class T>
Node<T>* BSTree<T>::Minimum(Node<T> *tree){
	if(tree==NULL)
		return NULL;
	while(tree->left!=NULL)
		tree=tree->left;
	return tree;
}

template<class T>
T Node<T>::Minimum(){
	Node<T> *p=Minimum(root);
	if(p!=NULL)
		return p->key;
	return (T)NULL;
}




template<class T>
Node<T>* BSTree<T>::predecessor(Node<T> *tree){
	if(tree->left!=NULL)
		return Maximum(x->left);

	Node<T> *p=tree->parent;
	while((p!=NULL)&&(tree==p->left))
	{
		tree=p;
		p=tree->parent;
	}
	return p;
}


template<class T>
Node<T>* BSTree<T>::successor(Node<T> *tree){
	if(tree->right!=NULL)
		return Minimum(tree->right);

	Node<T> *p=tree->parent;
	while((p!=NULL)&&(tree==p->right))
	{
		tree=p;
		p=tree->parent;
	}
	return p;
}



template<class T>
void BSTree<T>::insert(Node<T> *tree,Node<T> *z){
	Node<T> *x=tree;
	Node<T> *y=NULL;

	while(x!=NULL)
	{
		y=x;
		if(z->key<x->key)
			x=x->left;
		else
			x=x->right;
	}
	z->parent=y;
	if(y==NULL)
		tree=z;
	else if(z->key<y->key)
		y->left=z;
	else
		y->right=z;
}

template<class T>
void BSTree<T>::insert(T key){
	z=new Node<T>;
	z->key=key;
	insert(root,z);
}



template<class T>
Node<T>* BSTree<T>::remove(Node<T> *&tree,Node<T> *z){
	
}





int main(){
	BSTree<int> a;
	return 0;
}

