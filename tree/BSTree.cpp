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







};

int main(){
	BSTree<int> a;
	return 0;
}

