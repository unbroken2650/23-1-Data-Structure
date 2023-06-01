class Graph {
public:
	Graph(int size) : n(size), m(0) {}
	virtual int vertexSize() {
		return n;
	}
	virtual int edgeSize() {
		return m;
	}
	virtual void addEdge(int fromV, int toV) = 0;
	// Graph 객체를 만들 계획이 없으므로 virtual로 abstract class 표현
protected:
	int n;
	int m;
};