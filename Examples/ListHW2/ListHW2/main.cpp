#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	string name = "Suho Han";
	int number = 20192650;

	cout << number << " " << name << endl;

	List list;
	ListElementType i;
	cout << "Enter items to add to list, add 0 to stop: ";
	cin >> i;
	while (i != 0) {
		list.insert(i);
		cin >> i;
	}
	cout << "Here are the items in the list.\n";
	ListElementType elem;
	bool notEmpty(list.first(elem));
	while (notEmpty) {
		cout << elem << endl;
		notEmpty = list.next(elem);
	}
	return 0;

}
