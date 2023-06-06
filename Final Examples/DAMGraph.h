#pragma once
#include "AMGraph.h"
#include <assert.h>

class DAMGraph : public AMGraph {
public:
	DAMGraph(int size, int initialValue = 0) :AMGraph(size) {};
	virtual void addEdge(int fromV, int toV);
};

void DAMGraph::addEdge(int fromV, int toV) {
	assert(fromV < n && toV < n && fromV >= 0 && toV >= 0);
	if (!edgeMember(fromV, toV)) {
		m++;
		am[fromV][toV] = 1;
	}
}