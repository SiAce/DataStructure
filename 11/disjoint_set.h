#ifndef DISJOINT_SET_H_
#define DISJOINT_SET_H_

class DisjointSet
{
private:
	int size;
	int * parent;

public:
	DisjointSet(int s);
	DisjointSet(int s, int * arr);
	~DisjointSet();
	void Union(int root1, int root2);
	int Find(int x);
};

DisjointSet::DisjointSet(int n)
{
	size = n;
	parent = new int[size];
	for (int i =0;i<size;i++) 
	{
		parent[i] = -1;
	}
}

DisjointSet::DisjointSet(int n, int * arr)
{
	size = n;
	parent = new int[size];
	for (int i = 0; i<size; i++)
	{
		parent[i] = arr[i];
	}
}

DisjointSet::~DisjointSet()
{
	delete[] parent;
}

#endif // DISJOINT_SET_H__