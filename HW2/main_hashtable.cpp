#include <iostream>
#include "HashTable.h"

using namespace std;

const int numberOfPeople = 7;

int main()
{
	HashTable <int, int> tableA;
	for (int i = 0; i < numberOfPeople; i++) {
		cout << "Type Key and Date of person " << i + 1 << endl;
		int key, data;
		cin >> key;
		cin >> data;
		cout << endl;
		tableA.insert(key, data);
	}
	tableA.dump();
	return 0;
}

