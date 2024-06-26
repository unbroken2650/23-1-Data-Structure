#include "List.h"
#include <assert.h>

List::List()
{
	head = 0; //NULL
	tail = 0; //NULL
	current = 0; //NULL
}

List::~List()
{
	while (head != 0)
	{
		Link delNode = head;
		head = head->next;
		delete delNode;
		cout << "deleted " << head << endl;
	}
	cout << "delete completed" << endl;
}

void List::insert(const ListElementType& elem)
{
	Link addedNode = new Node;
	assert(addedNode); // addedNode가 빈 Node인지 확인
	addedNode->elem = elem; // elem를 addedNode에 배정
	if (head == 0 || elem <= head->elem) {
		addedNode->next = head;
		head = addedNode;
	}
	else {
		Link pred(head);
		while (pred->next != 0 && pred->next->elem <= addedNode->elem)
		{
			pred = pred->next;
		}
		addedNode->next = pred->next;
		pred->next = addedNode;
	}
	// 주소에서는 0이 NULL과 같음
	// head, tail, current, addedNode는 모두 포인터라서 tail->next = addedNode는 tail이 가리키는 Node에 addedNode를 배정하는 것
}

void List::insertFront(const ListElementType& elem)
{
	Link addedNode = new Node;
	assert(addedNode);
	addedNode->elem = elem;
	if (head == 0) // List에 아무 것도 없을 때
	{
		addedNode->next = 0;
		head = addedNode;
		tail = addedNode;
	}
	else // List에 element가 있을 때
	{
		addedNode->next = head;
		head = addedNode;
	}
}

bool List::first(ListElementType& elem)
{
	if (head == 0)
		return false;
	else {
		elem = head->elem;
		current = head;
		return true;
	}
}

bool List::last(ListElementType& elem)
{
	if (tail == 0)
		return false;
	else {
		elem = head->elem;
		current = head;
		return true;
	}
}

bool List::next(ListElementType& elem)
{
	assert(current);

	if (current->next == 0)
		return false;
	else {
		current = current->next;
		elem = current->elem;
		return true;
	}
}