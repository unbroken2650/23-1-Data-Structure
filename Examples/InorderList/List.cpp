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
	assert(addedNode); // addedNode�� �� Node���� Ȯ��
	addedNode->elem = elem; // elem�� addedNode�� ����
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
	// �ּҿ����� 0�� NULL�� ����
	// head, tail, current, addedNode�� ��� �����Ͷ� tail->next = addedNode�� tail�� ����Ű�� Node�� addedNode�� �����ϴ� ��
}

void List::insertFront(const ListElementType& elem)
{
	Link addedNode = new Node;
	assert(addedNode);
	addedNode->elem = elem;
	if (head == 0) // List�� �ƹ� �͵� ���� ��
	{
		addedNode->next = 0;
		head = addedNode;
		tail = addedNode;
	}
	else // List�� element�� ���� ��
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