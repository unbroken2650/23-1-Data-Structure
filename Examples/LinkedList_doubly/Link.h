#pragma once

typedef int ListElementType;

class List {
public:
	List();
	void insert(const ListElementType& elem);
	bool first(ListElementType& elem);
	bool last(ListElementType& elem);
	bool next(ListElementType& elem);
	bool previous(ListElementType& elem);
private:
	struct Node;
	typedef Node* Link;
	struct Node
	{
		ListElementType elem;
		Link next;
		Link prev;
	};
	Link head;
	Link current;
};