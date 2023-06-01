#pragma once
#include <assert.h>

template <class ListElementType>
class ListIter;

template <class ListElementType>
class List {
public:
	List() : head(0) {}
	virtual void insert(const ListElementType& elem);
	friend class ListIter <ListElementType>;
protected:
	struct Node;
	typedef Node* Link;
	struct Node {
		ListElementType elem;
		Link next;
	};
	Link head;
};

template <class ListElementType>
class ListIter {
public:
	ListIter(const List <ListElementType>& l, ListElementType endFlag) : myList(l), myEndFlag(endFlag), iterPtr(0) {}
	virtual ListElementType operator++();
protected:
	const List <ListElementType>& myList; // 친구 리스트의 주소값
	typename List <ListElementType>::Link iterPtr;
	ListElementType myEndFlag;
};

template <class ListElementType>
ListElementType
ListIter <ListElementType> ::operator++() {
	if (iterPtr == 0) {
		iterPtr = myList.head;
	}
	else {
		iterPtr = iterPtr->next;
	}
	if (iterPtr) {
		return iterPtr->elem;
	}
	else {
		return myEndFlag;
	}
}

template <class ListElementType>
void
List<ListElementType>::insert(const ListElementType& elem) {
	Link addedNode = new Node;
	assert(addedNode);
	addedNode->elem = elem;
	addedNode->next = head;
	head == addedNode;
}