#include "binary_search_tree.h"
#include <iostream>

using namespace std;

template <class Type>
bool BinarySearchTree<Type>::find(const Type &x) const
{
	if (root == NULL)
	{
		return false;
	}
	else
	{
		BinaryNode *t = root;
		while (t != NULL)
		{
			if (x == t->data)
			{
				return true;
			}
			else if (x < t->data)
			{
				t = t->left;
			}
			else if (x > t->data)
			{
				t = t->right;
			}
		}
		return false;
	}
}

template<class Type>
void BinarySearchTree<Type>::insert(const Type & x)
{
	if (root == NULL)
	{
		root = new BinaryNode(x, NULL, NULL);
	}
	else 
	{
		BinaryNode *t = root;
		while (t != NULL)
		{
			if (x == t->data)
			{
				cout << "Can't insert a same data"
					<< endl;
				return;
			}
			else if (x < t->data)
			{
				if (t->left == NULL)
				{
					t->left = new BinaryNode(x, NULL, NULL);
					return;
				}
				else {
					t = t->left;
				}				
			}
			else if (x > t->data)
			{
				if (t->right == NULL)
				{
					t->right = new BinaryNode(x, NULL, NULL);
					return;
				}
				else {
					t = t->right;
				}
			}
		}
	}
}

template<class Type>
void BinarySearchTree<Type>::remove(const Type & x)
{
	BinaryNode *t = root;
	BinaryNode *p = t;
	bool leftorright = 0;

	if (t == NULL)
	{
		return;
	}
	else
	{
		while (t != NULL)
		{
			if (x < t->data)
			{
				p = t;
				leftorright = 0;
				t = t->left;
			}
			else if (x > t->data)
			{
				p = t;
				leftorright = 1;
				t = t->right;
			}
			else if (x == t->data)
			{
				if (t->left != NULL && t->right != NULL)
				{
					BinaryNode * tmp = t->right;
					while (tmp->left != NULL)
					{
						tmp = tmp->left;
					}
					t->data = tmp->data;
					if (tmp->right != NULL)
					{
						BinaryNode * son = tmp->right;
						if (leftorright == 0) {
							p->left = son;
						}
						else
						{
							p->right = son;
						}
						delete t;
						return;
					}
					else
					{
						if (leftorright == 0) {
							p->left = NULL;
						}
						else
						{
							p->right = NULL;
						}
						delete t;
						return;
					}
				}
				else if (t->left != NULL || t->right != NULL)
				{
					BinaryNode * son = (t->left != NULL) ? t->left : t->right;
					if (leftorright == 0) {
						p->left = son;
					}
					else
					{
						p->right = son;
					}
					delete t;
					return;
				}
				else
				{
					if (leftorright == 0) {
						p->left = NULL;
					}
					else
					{
						p->right = NULL;
					}
					delete t;
					return;
				}
			}
		}
	}
}

int main()
{
	int a[] = { 10,8,6,21,87,56,4,0,11,3,22,7,5,34,1,2,9 };
	BinarySearchTree<int> tree;

	for (int i = 0; i < 17; ++i)
	{
		tree.insert(a[i]);
	}
	cout << "find 2 is " << (tree.find(2) ? "true" : "false") << endl;
	tree.remove(2);
	cout << "after delete 2, find 2 is " << (tree.find(2) ? "true" : "false") << endl;

	cout << "find 3 is " << (tree.find(3) ? "true" : "false") << endl;
	tree.remove(3);
	cout << "after delete 3, find 3 is " << (tree.find(3) ? "true" : "false") << endl;

	cout << "find 1 is " << (tree.find(1) ? "true" : "false") << endl;
	cout << "find 22 is " << (tree.find(22) ? "true" : "false") << endl;
	cout << "find 56 is " << (tree.find(56) ? "true" : "false") << endl;

	return 0;
}