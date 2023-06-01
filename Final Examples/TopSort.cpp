#include "DALGraph.h"
#include "Queue.h"
#include "Stack.h"
#include <iostream>
#include <fstream>
#include <assert.h>

using namespace std;

int main() {
	const char* inFileName = "graph.dat";
	ifstream ifs(inFileName);
	assert(ifs);
	int n;
	ifs >> n;
	DALGraph G(n);
	cout << "Created graph; n= " << G.vertexSize() << endl;

	int u, v;
	while (ifs >> u) {
		ifs >> v;
		G.addEdge(u, v);
	}
	cout << "Edges in graph; m= " << G.edgeSize() << endl;

	int* vertices(new int[n]);
	assert(vertices);
	for (u = 0; u < n; u++) {
		vertices[u] = 0;
	}
	for (u = 0; u < n; u++) {
		NeighborIter ni(G, u);
		while ((v = ++ni) != n) {
			vertices[v]++;
		}
	}

	Stack <int> s;
	for (u = 0; u < n; u++) {
		if (vertices[u] == 0) {
			s.push(u);
		}
	}
	if (s.isEmpty()) {
		cout << "graph has a cycle!\n";
		return 0;
	}

	int count = 0;
	Queue <int> sortedEdges;
	while (!s.isEmpty()) {
		count++;
		u = s.pop();
		sortedEdges.enqueue(u);
		NeighborIter ni(G, u);

		while ((v = ++ni) != n) {
			--vertices[v];
			if (vertices[v] == 0) {
				s.push(v);
			}
		}
	}

	if (count < n) {
		cout << "Couldn't complete top sort -- cycle present.\n";
	}
	cout << "Oredering for top sort: \n";
	while (!sortedEdges.isEmpty()) {
		cout << sortedEdges.dequeue() << '/t';
	}
	cout << endl;
	return n;


}