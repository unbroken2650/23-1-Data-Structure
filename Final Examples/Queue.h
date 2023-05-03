#ifndef __MB_CX9_2__
#define __MB_CX9_2__
#include <assert.h>

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
	bool isFull();
	int getnElement();
	void setnElement();
private:
	int f;
	int r;
	int nElement;
	queueElementType elements[maxQueue];
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
	nElement = 0;
}

template <class queueElementType>
Queue <queueElementType>::~Queue()
{
}


template <class queueElementType>
void Queue <queueElementType>::enqueue(queueElementType e)
{
	//assert(nettPos(r) != f);

	//pos 올리고 Queue에 삽입
	/*assert(!isFull());
	r = nextPos(r);
	elements[r] = e;*/

	//Queue에 삽입하고 pos 올림(0부터 삽입 가능)
	assert(!isFull());
	elements[r] = e;
	r = nextPos(r);

	nElement++;
}

template <class queueElementType>
queueElementType Queue <queueElementType>::dequeue()
{
	//assert(f == r);
	assert(!isEmpty());

	//기존 코드
	/*f = nextPos(f);
	return elements[f];*/

	//변경 코드
	queueElementType elem;
	elem = elements[f];
	f = nextPos(f);

	nElement--;

	return elem;
}

template <class queueElementType>
queueElementType Queue <queueElementType>::front()
{
	//assert(f != r);
	assert(!isEmpty());

	//기존코드
	/*return elements[nextPos(f)];*/

	//변경코드
	return elements[f];
}

template <class queueElementType>
bool Queue <queueElementType>::isEmpty()
{
	//return bool(f == r);

	return bool(nElement == 0);
}

template <class queueElementType>
bool Queue <queueElementType>::isFull()
{
	//return bool(nextPos(r) == f);

	return bool(nElement == maxQueue - 1);
}

template <class queueElementType>
int Queue <queueElementType>::getnElement()
{
	return nElement;
}
template <class queueElementType>
void Queue <queueElementType>::setnElement()
{
	nElement++;
}
#endif

