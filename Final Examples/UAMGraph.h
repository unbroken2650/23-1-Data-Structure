#pragma once
#include "AMGraph.h"
#include <assert.h>

class UAMGraph : public AMGraph {
public:
	UAMGraph(int size, int initialValue = 0) :AMGraph(size) {};
	virtual void addEdge(int fromV, int toV);
};

void UAMGraph::addEdge(int fromV, int toV) {
	assert(fromV < n && toV < n && fromV >= 0 && toV >= 0);
	if (!edgeMember(fromV, toV)) {
		m++;
		am[fromV][toV] = 1;
		am[toV][fromV] = 1;
	}
}