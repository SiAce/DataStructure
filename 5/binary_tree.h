#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

template < class Type >
struct Node
{
	Node *left, *right;
	Type data;

	Node() :left(NULL), right(NULL) {}
	Node(Type item, Node *L = NULL, Node *R = NULL) :
		data(item), left(L), right(R) {}
	~Node() {}
};

template < class Type >
class BinaryTree {
private:

	Node<Type> *root;

public:
	BinaryTree() :root(NULL) {}
	BinaryTree(const Type &value) { root = new Node(value); }
	BinaryTree(Node<Type> & node) { root = &node; }
//	~BinaryTree() { clear(); }

	Node<Type> * getRoot() const { return root; }
	Type getLeft() const { return root->left->data; }
	Type getRight() const { return root->right->data; }
};

#endif // BINARY_TREE_H_