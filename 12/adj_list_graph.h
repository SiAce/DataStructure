#include "graph.h"
#include<string>

#ifndef ADJ_LIST_GRAPH_
#define ADJ_LIST_GRAPH_

template <class TypeOfVer, class TypeOfEdge>
class adjListGraph: public graph<TypeOfEdge>
{
public:
	adjListGraph(int vSize, const TypeOfVer d[]);
	bool insert(int u, int v, TypeOfEdge w);
	bool remove(int u, int v);
	bool exist(int u, int v) const;
	void topSort() const;
	~adjListGraph();

private:
	struct edgeNode
	{
		int end;
		TypeOfEdge weight;
		edgeNode * next;

		edgeNode(int e, TypeOfEdge w, edgeNode * n = NULL)
		{
			end = e; 
			weight = w;
			next = n;
		}
	};

	struct verNode
	{
		TypeOfVer ver;
		edgeNode * head;

		verNode(edgeNode * h = NULL)
		{
			head = h;
		}
	};

	verNode * verList;
};

#endif // ADJ_LIST_GRAPH_
