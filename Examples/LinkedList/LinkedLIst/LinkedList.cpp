#include <iostream>
using namespace std;
#include "List.h"

int main()
{
	List L;
	ListElementType i;
	cout << "Enter: ";
	cin >> i;

	while (i != 0)
	{
		L.insertFront(i);
		cin >> i;
	}
	cout << "Elements are : ";
	ListElementType elem;
	bool notEmpty(L.first(elem));
	while (notEmpty) {
		cout << elem << " ";
		notEmpty = L.next(elem);
	}
	cout << endl;
	return 0;
}