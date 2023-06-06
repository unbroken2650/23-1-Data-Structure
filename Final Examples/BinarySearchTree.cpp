#include "BinarySearchTree.h"
#include <iostream>

using namespace std;

int main() {
	string name = "Suho Han";
	int number = 20192650;

	cout << number << " " << name << endl;

	typedef BST <int> intBST;
	typedef intBST* intBSTPtr;

	intBSTPtr b(new intBST);
	b->insert(17);
	b->insert(10);
	b->insert(26);
	b->insert(6);
	b->insert(20);
	b->insert(28);
	b->insert(11);
	b->insert(31);
	b->insert(37);
	b->insert(12);

	intBSTPtr get11((BST <int>*)b->retrieve(11));
	if (get11->isEmpty()) {
		cout << "11 is not found\n";
	}
	else {
		cout << "11 found.\n";
	}

	intBSTPtr get13((BST <int>*)b->retrieve(13));
	if (get13->isEmpty()) {
		cout << "13 is not found\n";
	}
	else {
		cout << "13 found.\n";
	}

	return 0;

}