#pragma once
#include <iostream>
using namespace std;

typedef int ListElementType;

class List
{
public:
	List();
	void insert(const ListElementType& elem);
	bool first(ListElementType& elem);
	void remove(const ListElementType& target);
	bool next(ListElementType& elem);
private:
	struct Node; // 19번 줄에서 next를 정의하기 위해 Node를 먼저 선언해주었음
	typedef Node* Link; // Node의 포인터(Node*)를 간략하게 표현
	struct Node
	{
		ListElementType elem;
		Link next;
	};
	Link head;
	Link current;
};

