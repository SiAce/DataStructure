#include <iostream>
#include "binary_tree.h"

using namespace std;

template <class Type>
bool NodesAreSame(Node<Type> *node1, Node<Type> *node2) {

	bool left_are_same = false, data_are_same = false, right_are_same = false;

	if (node1->left == NULL && node2->left == NULL) {
		left_are_same = true;
	}
	else
	{
		if(node1->left != NULL && node2->left != NULL
			&& NodesAreSame(node1->left, node2->left)) {
			left_are_same = true;
		}
	}

	if (node1->data == node2->data) {
		data_are_same = true;
	}

	if (node1->right == NULL && node2->right == NULL) {
		right_are_same = true;
	}
	else
	{
		if (node1->right != NULL && node2->right != NULL
			&& NodesAreSame(node1->right, node2->right)) {
			right_are_same = true;
		}
	}

	return (left_are_same && data_are_same && right_are_same);
}

template <class Type>
bool TreesAreSame(BinaryTree<Type> *bt1, BinaryTree<Type> *bt2) {
	return NodesAreSame<Type>(bt1->getRoot(), bt2->getRoot());
}

int main() {
	Node<int> node1(1);
	Node<int> node2(2);
	Node<int> node3(3);
	Node<int> * p1 = &node1;
	Node<int> * p2 = &node2;
	Node<int> * p3 = &node3;
	Node<int> node4(4, p1, p2);
	Node<int> node5(4, p1, p2);
	Node<int> node6(6, p2, p3);
	BinaryTree<int> bt4(node4);
	BinaryTree<int> bt5(node5);
	BinaryTree<int> bt6(node6);

	cout << TreesAreSame(&bt4, &bt5) << endl;
	cout << TreesAreSame(&bt5, &bt6) << endl;

	return 0;
}