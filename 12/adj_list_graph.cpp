#include "adj_list_graph.h"
#include "link_queue.h"
#include <iostream>
#include <string>

using namespace std;

template<class TypeOfVer, class TypeOfEdge>
adjListGraph<TypeOfVer, TypeOfEdge>::adjListGraph(int vsize, const TypeOfVer d[])
{
	Vers = vsize;
	Edges = 0;
	verList = new verNode[vsize];

	for (int i = 0; i < Vers; ++i)
	{
		verList[i].ver = d[i];
	}
}

template<class TypeOfVer, class TypeOfEdge>
adjListGraph<TypeOfVer, TypeOfEdge>::~adjListGraph()
{
	int i;
	edgeNode * p;
	for (i = 0; i < Vers; ++i)
	{
		while ((p = verList[i].head) != NULL)
		{
			verList[i].head = p->next;
			delete p;
		}
	}

	delete[] verList;
}

template<class TypeOfVer, class TypeOfEdge>
bool adjListGraph<TypeOfVer, TypeOfEdge>::insert(int u,int v, TypeOfEdge w)
{
	verList[u].head = new edgeNode(v, w, verList[u].head);
	++Edges;
	return true;
}

template<class TypeOfVer, class TypeOfEdge>
bool adjListGraph<TypeOfVer, TypeOfEdge>::remove(int u, int v)
{
	edgeNode *p = verList[u].head, *q;

	if (p == NULL) return false;

	if (p->end == v)
	{
		verList[u].head = p->next;
		delete p;
		--Edges;
		return true;
	}

	while (p->next != NULL && p->next->end != v) p = p->next;

	if (p->next == NULL) return false;
	q = p->next;
	p->next = q->next;
	delete q;
	--Edges;
	return true;
}

template<class TypeOfVer, class TypeOfEdge>
bool adjListGraph<TypeOfVer, TypeOfEdge>::exist(int u, int v) const
{
	edgeNode *p = verList[u].head;
	while (p != NULL && p->end != v) p = p->next;
	if (p == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}

template<class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::topSort() const
{
	linkQueue <int> q;
	edgeNode *p;
	int current;
	int semester = 1;
	int *inDegree = new int[Vers];

	for (int i = 0; i < Vers; ++i) inDegree[i] = 0;
	for (int i = 0; i < Vers; ++i)
	{
		for (p = verList[i].head; p != NULL; p = p->next)
		{
			++inDegree[p->end];
		}
	}

	for (int i = 0; i < Vers; ++i)
	{
		if (inDegree[i] == 0)
		{
			q.enQueue(i);
		}
	}

	cout << "Top Sort:" << endl;
	while (!q.isEmpty())
	{
		cout << semester << ": ";
		while (!q.isEmpty())
		{
			current = q.deQueue();
			--inDegree[current];
			cout << verList[current].ver << '\t';
			for (p = verList[current].head; p != NULL; p = p->next)
			{
				--inDegree[p->end];
			}
		}

		for (int i = 0; i < Vers; ++i)
		{
			if (inDegree[i] == 0)
			{
				q.enQueue(i);
			}
		}

		cout << endl;
		semester++;
	}

}

int main()
{
	string arr[7] = { "数学","程序设计","离散数学","软件工程","数据结构","数据库","编译原理" };
	adjListGraph<string, int> alg(7, arr);
	alg.insert(0, 1, 1);
	alg.insert(0, 2, 1);
	alg.insert(1, 3, 1);
	alg.insert(1, 4, 1);
	alg.insert(1, 5, 1);
	alg.insert(2, 4, 1);
	alg.insert(2, 6, 1);
	alg.insert(4, 5, 1);
	alg.insert(4, 6, 1);
	alg.insert(5, 3, 1);
	alg.topSort();

	return 0;
}