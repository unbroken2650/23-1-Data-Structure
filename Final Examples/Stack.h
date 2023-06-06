#ifndef __MB_CX8_3__
#define __MB_CX8_3__
#include <assert.h>
#include <iostream>
using namespace std;

const int maxStackSize = 1000;

template <class StackElementType>
class Stack {
public:
	Stack();
	void push(StackElementType elem);
	StackElementType pop();
	StackElementType top();
	bool isEmpty();
	bool isFull();
private:
	StackElementType stackArray[maxStackSize];
	int topIndex;
};

template <class StackElementType>
Stack <StackElementType>::Stack()
{
	topIndex = -1;
}

template <class StackElementType>
void Stack <StackElementType>::push(StackElementType elem)
{
	++topIndex;
	assert(topIndex < maxStackSize);
	stackArray[topIndex] = elem;
	//cout << elem << " at " << topIndex << endl;
}
template <class StackElementType>
StackElementType Stack <StackElementType>::pop()
{
	assert(topIndex >= 0);
	int returnIndex(topIndex);
	--topIndex;
	return stackArray[returnIndex];
}

template <class StackElementType>
StackElementType Stack <StackElementType>::top()
{
	assert(topIndex >= 0);
	return stackArray[topIndex];
}

template <class StackElementType>
bool Stack <StackElementType>::isEmpty()
{
	return bool(topIndex == -1);
}

template <class StackElementType>
bool Stack <StackElementType>::isFull()
{
	return topIndex == maxStackSize - 1;
}
#endif