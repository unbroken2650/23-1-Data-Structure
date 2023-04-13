#include "List.h"
#include <assert.h>
#include <iostream>
using namespace std;

List::List() {
	head = 0;
	current = 0;
}

void List::insert(const ListElementType& elem)
{
	Link addedNode = new Node;
	assert(addedNode);
	addedNode->elem = elem;
	addedNode->next = head;
	if (head) {
		head->prev = addedNode;
	}
	addedNode->prev = 0;
	head = addedNode;
}

bool List::previous(ListElementType& elem) {
	assert(current);
	if (current->prev == 0) {
		return false;
	}
	else {
		current = current->prev;
		elem = current->elem;
		return true;
	}

}

bool List::next(ListElementType& elem) {
	assert(current);
	if (current->next == 0) {
		return false;
	}
	else {
		current = current->next;
		elem = current->elem;
		return true;
	}

}


bool List::first(ListElementType& elem) {
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


bool List::last(ListElementType& elem) {
	assert(head);
	if (head->next == 0) {
		return false;
	}
	else {
		current = head->next;
		elem = current->elem;
		return true;
	}
}

