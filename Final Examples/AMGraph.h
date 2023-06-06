#pragma once
#include "Graph.h"
#include <assert.h>

class AMGraph : public Graph {
public:
	AMGraph(int size);
	virtual bool edgeMember(int fromV, int toV);
protected:
	int** am;
};

AMGraph::AMGraph(int size) : Graph(size) {
	int i;
	am = new int* [n];
	assert(am);

	for (i = 0; i < n; i++) {
		am[i] = new int[n];
		assert(am[i]);
		int j;
		for (j = 0; j < n; j++) {
			am[i][j] = 0;
		}
	}
}

bool AMGraph::edgeMember(int fromV, int toV) {
	assert(fromV < n && toV < n && fromV >= 0 && toV >= 0);
	return bool(am[fromV][toV] != 0);
}