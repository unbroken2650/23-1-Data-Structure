#pragma once
#include <iostream>
using namespace std;

typedef int ListElementType;

class List
{
public:
	List();
	~List();
	void insert(const ListElementType& elem);
	void insertFront(const ListElementType& elem);
	bool first(ListElementType& elem);
	bool next(ListElementType& elem);
private:
	struct Node; // 19�� �ٿ��� next�� �����ϱ� ���� Node�� ���� �������־���
	typedef Node* Link; // Node�� ������(Node*)�� �����ϰ� ǥ��
	struct Node
	{
		ListElementType elem;
		Link next;
	};
	Link head;
	Link tail;
	Link current;
};

