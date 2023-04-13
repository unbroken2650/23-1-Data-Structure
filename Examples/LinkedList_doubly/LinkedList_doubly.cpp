
#include <iostream>
using namespace std;
#include "Link.h"

int main()
{
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
    notEmpty = list.first(elem);
    notEmpty = list.next(elem);
    notEmpty = list.previous(elem);
    cout << elem << endl;
    return 0;
}
