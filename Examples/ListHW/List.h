#pragma once
typedef int ListElementType;

const int maxListSize = 1000;

class List {
public:
	List();
	void insert(const ListElementType& elem);
	bool first(ListElementType& elem);
	bool next(ListElementType& elem);
private:
	ListElementType listArray[maxListSize];
	int numberOfElements;
	int currentPosition;
};