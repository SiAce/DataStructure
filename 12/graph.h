#include<string>

#ifndef GRAPH_
#define GRAPH_

template <class TypeOfEdge>
class graph
{
public:
	virtual bool insert(int u, int v, TypeOfEdge w) = 0;
	virtual bool remove(int u, int v) = 0;
	virtual bool exist(int u, int v) const = 0;
	virtual int numOfVer() const { return Vers; }
	virtual int numOfEdge() const { return Edges; }

protected:
	int Vers, Edges;
};

#endif // GRAPH_