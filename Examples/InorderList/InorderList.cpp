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
		L.insert(i);
		cin >> i;
	}
	cout << "Elements are : ";
	ListElementType elem;
	bool notEmpty_(L.last(elem));
	if (notEmpty_)
	{
		cout << "Last item is " << elem << endl;
	}
	bool notEmpty(L.first(elem));
	while (notEmpty) {
		cout << elem << " ";
		notEmpty = L.next(elem);
	}
	cout << endl;
	return 0;
}