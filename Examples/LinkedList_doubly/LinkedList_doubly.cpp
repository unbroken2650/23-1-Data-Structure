#include <iostream>
using namespace std;
#include "List.h"

int main()
{
    List l;
    ListElementType i; // header file defines this to be int

    cout << "Enter items to add to list, add 0 to stop: ";
    cin >> i;

    while (i != 0) {
        l.insert(i);
        cin >> i;
    }
    cout << "Here are the items in the list.\n";

    ListElementType elem;
    bool notEmpty(l.first(elem));
    while (notEmpty) {
        cout << elem << endl;
        notEmpty = l.next(elem);
    }

    cout << "Here are the items in the list in backward.\n";
    notEmpty = l.previous(elem);
    notEmpty = l.next(elem);
    while (notEmpty) {
        cout << elem << endl;
        notEmpty = l.previous(elem);
    }

	return 0;
}
