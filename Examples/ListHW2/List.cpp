#include "List.h"
#include <assert.h>

List::List()
{
	head = 0;
	tail = 0;
	current = 0;
}

List::~List()
{
	head = 0;
	tail = 0;
	current = 0;
}

void List::insert(const ListElementType& elem)
{
	Link addedNode = new Node;
	assert(addedNode);
	addedNode->elem = elem;
	if (head == 0)
	{
		head = addedNode;
	}
	else
		tail->next = addedNode;
	addedNode->next = 0;
}

bool List::first(ListElementType& elem)
{
	if (head == 0)
	{
		return false;
	}
	else {
		elem = head->elem;
		current = head;
		return true;
	}
}

bool List::next(ListElementType& elem)
{
	assert(current);
	if (current -> next == 0)
	{
		return false;
	}
	else {
		current = current->next;
		elem = current->elem;
		return true;
	}
}
