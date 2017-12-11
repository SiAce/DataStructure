#include "disjoint_set.h"
#include<iostream>

using namespace std;

int DisjointSet::Find(int x)
{
	if (parent[x] < 0)
	{
		return x;
	}
	else
	{
		if (parent[parent[x]] >= 0)
		{
			parent[x] = parent[parent[x]];
		}
		return Find(parent[x]);
	}
}

void DisjointSet::Union(int root1, int root2)
{
	if (root1 == root2)
	{
		return;
	}

	if (parent[root1] > parent[root2])
	{
		parent[root1] = root2;
	}
	else
	{
		parent[root2] = root1;
	}
}

int main()
{
	int arr[15]{ -2,0,0,0,-2,4,-2,6,6,-4,9,9,11,12,12 };
	DisjointSet disjoint_set{ 15, arr };
	cout << disjoint_set.Find(7) << endl;
	cout << disjoint_set.Find(14) << endl;
	disjoint_set.Union(6, 9);
	cout << disjoint_set.Find(7) << endl;
	cout << disjoint_set.Find(14) << endl;
	return 0;
}
