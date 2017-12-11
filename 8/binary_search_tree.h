#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_
#include<stddef.h>

template <class Type>
class BinarySearchTree
{
private:

	struct BinaryNode
	{
		Type data;
		BinaryNode *left;
		BinaryNode *right;

		BinaryNode(const Type &thedata, BinaryNode *lt, BinaryNode *rt)
			: data(thedata), left(lt), right(rt) {}
	};

	BinaryNode *root;

public:
	BinarySearchTree(BinaryNode *t = NULL)
	{
		root = t;
	}
	~BinarySearchTree() = default;
	bool find(const Type &x) const;
	void insert(const Type &x);
	void remove(const Type &x);

};

#endif // BINARY_SEARCH_TREE_H_