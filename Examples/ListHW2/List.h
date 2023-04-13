#pragma once
typedef int ListElementType;

const int maxListSize = 1000;

class List {
public:
	List();
	~List();
	void insert(const ListElementType& elem);
	bool first(ListElementType& elem);
	bool next(ListElementType& elem);
private:
	struct Node;
	typedef Node* Link;
	struct Node {
		ListElementType elem;
		Link next;
	};
	Link head;
	Link tail;
	Link current;
};