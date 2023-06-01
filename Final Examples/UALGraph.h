#pragma once
#include "ALGraph.h"
#include <assert.h>

class UALGraph : public ALGraph {
public:
	UALGraph(int size) : ALGraph(size) {}
	virtual void addEdge(int fromV, int toV);
};

void UALGraph::addEdge(int fromV, int toV) {
	assert(fromV < n && fromV >= 0 && toV < n && toV >= 0);
	vertexList[fromV].insert(toV);
	vertexList[toV].insert(fromV);
	m++;
}