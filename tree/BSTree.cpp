#include<iostream>
#include<iomanip>
using namespace std;

template<class T>
struct Node
{
	T key;
	Node *left;
	Node *right;
	Node *parent;
};

template<class T>
class BSTree {
private:
	Node<T> *root;

public:
	BSTree();
	~BSTree();

	void preOrder();
	void inOrder();
	void postOrder();

	Node<T>* recursiveSearch(T key);
	Node<T>* iterativeSearch(T key);

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

	Node<T>* recursiveSearch(Node<T> *tree, T key) const;
	Node<T>* iterativeSearch(Node<T> *tree, T key) const;

	Node<T>* Minimum(Node<T> *tree);
	Node<T>* Maximum(Node<T> *tree);

	void insert(Node<T> *&tree, Node<T> *z);

	void transplant(Node<T> *oldNode, Node<T> *newNode);
	Node<T>* remove(Node<T> *&tree, Node<T> *z);

	void destory(Node<T> *&tree);
	void print(Node<T> *tree, T key, int direction);

};

template<class T>
BSTree<T>::BSTree() :root(NULL) {

}

template<class T>
BSTree<T>::~BSTree() {
	destory();
}




//preOrder
template<class T>
void BSTree<T>::preOrder(Node<T> *tree) const {
	if (tree != NULL)
	{
		cout << tree->key << " ";
		preOrder(tree->left);
		preOrder(tree->right);
	}
}

template<class T>
void BSTree<T>::preOrder() {
	preOrder(root);
}


//inOrder
template<class T>
void BSTree<T>::inOrder(Node<T> *tree) const {
	if (tree != NULL)
	{
		inOrder(tree->left);
		cout << tree->key << " ";
		inOrder(tree->right);
	}
}

template<class T>
void BSTree<T>::inOrder() {
	inOrder(root);
}



//postOrder
template<class T>
void BSTree<T>::postOrder(Node<T> *tree) const {
	if (tree != NULL)
	{
		postOrder(tree->left);
		postOrder(tree->right);
		cout << tree->key << " ";
	}
}

template<class T>
void BSTree<T>::postOrder() {
	postOrder(root);
}



template<class T>
Node<T>* BSTree<T>::recursiveSearch(Node<T> *tree, T key) const {
	if (tree == NULL || tree->key == key)
	{
		return tree;
	}

	if (key<tree->key)
	{
		return recursiveSearch(tree->left, key);
	}
	else
		return recursiveSearch(tree->right, key);
}

template<class T>
Node<T>* BSTree<T>::recursiveSearch(T key) {
	search(root, key);
}

template<class T>
Node<T>* BSTree<T>::iterativeSearch(Node<T> *tree, T key) const {
	while ((tree != NULL) && (tree->key != key))
	{
		if (key<tree->key)
			tree = tree->left;
		else
			tree = tree->right;
	}
	return tree;
}

template<class T>
Node<T>* BSTree<T>::iterativeSearch(T key) {
	iterativeSearch(root, key);
}



template<class T>
Node<T>* BSTree<T>::Maximum(Node<T> *tree) {
	if (tree == NULL)
		return NULL;
	while (tree->right != NULL)
		tree = tree->right;
	return tree;
}

template<class T>
T BSTree<T>::Maximum() {
	Node<T> *p = Maximum(root);
	if (p != NULL)
		return p->key;
	return (T)NULL;
}



template<class T>
Node<T>* BSTree<T>::Minimum(Node<T> *tree) {
	if (tree == NULL)
		return NULL;
	while (tree->left != NULL)
		tree = tree->left;
	return tree;
}

template<class T>
T BSTree<T>::Minimum() {
	Node<T> *p = Minimum(root);
	if (p != NULL)
		return p->key;
	return (T)NULL;
}




template<class T>
Node<T>* BSTree<T>::predecessor(Node<T> *tree) {
	if (tree->left != NULL)
		return Maximum(x->left);

	Node<T> *p = tree->parent;
	while ((p != NULL) && (tree == p->left))
	{
		tree = p;
		p = tree->parent;
	}
	return p;
}


template<class T>
Node<T>* BSTree<T>::successor(Node<T> *tree) {
	if (tree->right != NULL)
		return Minimum(tree->right);

	Node<T> *p = tree->parent;
	while ((p != NULL) && (tree == p->right))
	{
		tree = p;
		p = tree->parent;
	}
	return p;
}



template<class T>
void BSTree<T>::insert(Node<T> *&tree, Node<T> *z) {
	Node<T> *x = tree;
	Node<T> *y = NULL;

	while (x != NULL)
	{
		y = x;
		if (z->key<x->key)
			x = x->left;
		else
			x = x->right;
	}
	z->parent = y;
	if (y == NULL)
		tree = z;
	else if (z->key<y->key)
		y->left = z;
	else
		y->right = z;
}

template<class T>
void BSTree<T>::insert(T key) {
	Node<T> *z = new Node<T>;
	z->key = key;
	z->left = NULL;
	z->right = NULL;
	z->parent = NULL;
	insert(root, z);
}

template<class T>
void BSTree<T>::transplant(Node<T> *oldNode, Node<T> *newNode) {
	if (oldNode->parent == NULL)
		root = newNode;
	else if (oldNode == oldNode->parent->left)
		oldNode->parent->left = newNode;
	else
		oldNode->parent->right = newNode;
	if (newNode != NULL)
		newNode->parent = oldNode->parent;
}

template<class T>
Node<T>* BSTree<T>::remove(Node<T> *&tree, Node<T> *z) {
	if (z->left == NULL)
		transplant(z, z->right);
	else if (z->right == NULL)
		transplant(z, z->left);
	else
	{
		Node<T> *y = Minimum(z->right);
		if (y != z->right)
		{
			transplant(y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}

		transplant(z, y);
		y->left = z->left;
		y->left->parent = y;
	}
	return z;
}

template<class T>
void BSTree<T>::remove(T key) {
	Node<T> *z,*node;
	if ((z = recursiveSearch(root, key))!= NULL)
		if ((node = remove(root, z)) != NULL)
			delete node;
}

template<class T>
void BSTree<T>::print(Node<T> *tree, T key, int direction) {
	if (tree != NULL)
	{
		if (direction == 0)
			cout << setw(2) << tree->key << " is root" << endl;
		else if (direction == 1)
			cout << setw(2) << tree->key << " is" << setw(3) << key << "'s" << setw(12) << "right child" << endl;
		else
			cout << setw(2) << tree->key << " is" << setw(3) << key << "'s" << setw(12) << "left child" << endl;

		print(tree->left, tree->key, -1);
		print(tree->right, tree->key, 1);
	}
}

template<class T>
void BSTree<T>::print() {
	if (root != NULL)
		print(root, root->key, 0);
}

template<class T>
void BSTree<T>::destory(Node<T> *&tree) {
	if (tree == NULL)
		return;
	if (tree->left != NULL)
		return destory(tree->left);
	if (tree->right != NULL)
		return destory(tree->right);
	delete tree;
	tree = NULL;
}

template <class T>
void BSTree<T>::destory() {
	destory(root);
}



int main() {
	BSTree<int> *ptree = new BSTree<int>;
	int a;
	for (int i = 0; i<15; i++) {
		cout << "input a integer: ";
		cin >> a;
		ptree->insert(a);
	}

	cout << "\nPreOrder:";
	ptree->preOrder();

	cout << "\nInOrder:";
	ptree->inOrder();

	cout << "\nPostOrder:";
	ptree->postOrder();

	cout << "\nMaximum:";
	cout<<ptree->Maximum();

	cout << "\nMinmum:";
	cout<<ptree->Minimum()<<endl;

	cout << "\nTree Structure:"<<endl;
	ptree->print();

	cout << "delete a node:";
	cin >> a;
	ptree->remove(a);

	cout << "\nInOrder:";
	ptree->inOrder();
	cout << endl;
	ptree->print();

	ptree->destory();

	cout << "press a key to exit." << endl;
	cin.get();
	cin.get();
	return 0;

}

