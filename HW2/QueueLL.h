#ifndef __MB_CX9_2__
#define __MB_CX9_2__
#include <assert.h>
#include <iostream>
using namespace std;

const int maxQueue = 200;

template <class queueElementType>
class Queue {
public:
	Queue();
	~Queue();
	void enqueue(queueElementType e);
	queueElementType dequeue();
	queueElementType front();
	bool isEmpty();
private:
	struct Node;
	typedef Node* nodePtr;
	struct Node {
		queueElementType data;
		nodePtr next;
	};
	nodePtr f;
	nodePtr r;
};

int nextPos(int p)
{
	if (p == maxQueue - 1) {
		return 0;
	}
	else {
		return p + 1;
	}
}

template <class queueElementType>
Queue <queueElementType>::Queue()
{
	f = 0;
	r = 0;
}

template <class queueElementType>
Queue <queueElementType>::~Queue()
{
	while (f != 0) {
		nodePtr n(f->next);
		cout << "Delete " <<f << endl;
		cout << "Data was " <<f->data << endl;
		delete f;
		f = n;
	}
}


template <class queueElementType>
void Queue <queueElementType>::enqueue(queueElementType e)
{
	//Node 생성
	nodePtr n(new Node);
	assert(n);

	// Node의 next와 data 배정
	n->next = 0;
	n->data = e;

	// 비어있는지 확인
	if (f != 0) {
		r->next = n;
		r = n;
	}
	else {
		f = n;
		r = n;
	}
}

template <class queueElementType>
queueElementType Queue <queueElementType>::dequeue()
{
	assert(f);
	nodePtr n(f);
	queueElementType frontElement(f->data);
	f = f->next;
	delete n;
	if (f == 0)
	{
		r = 0;
	}
	return frontElement;
}

template <class queueElementType>
queueElementType Queue <queueElementType>::front()
{
	assert(f);
	return f->data;
}

template <class queueElementType>
bool Queue <queueElementType>::isEmpty()
{
	return bool(f == 0);
}

#endif