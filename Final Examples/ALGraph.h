#include "Graph.h"
#include "ListIter.h"
#include <assert.h>

typedef List <int> IntList;
typedef ListIter <int> IntListIter;

class ALGraph : public Graph {
public:
	ALGraph(int size) : Graph(size) {
		vertexList = new IntList[n];
		assert(vertexList);
	}
	friend class NeighborIter;
protected:
	IntList* vertexList;
};

class NeighborIter : public IntListIter {
public:
	NeighborIter(const ALGraph& G, int startVertex) :IntListIter(G.vertexList[startVertex], G.n) {
		assert(startVertex < G.n);
	}
};