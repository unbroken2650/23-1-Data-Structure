#pragma once
#ifndef __MB_CX10_1__
#define __MB_CX10_1__
#include <assert.h>
#include <iostream>
using namespace std;

const int MAX_TABLE = 11;

template<class tableKeyType, class tableDataType>
class HashTable {
public:
	HashTable();
	void insert(const tableKeyType& insertKey, const tableDataType& insertData);
	bool lookup(const tableKeyType& lookupKey, tableDataType& data);
	void deleteKey(const tableKeyType& deleteKey);
	void dump(); // table의 모든 원소를 출력
private:
	enum slotType { Empty, Deleted, InUse };
	struct slot {
		slotType slotStatus;
		tableKeyType key;
		tableDataType data;
	};
	slot T[MAX_TABLE];
	int entries;
	int hash(const tableKeyType& key);
	int probe(const int pos); // nextPos

	//hash를 통해 pos값을 받고 search + pos에 값을 할당해야 하므로 const 붙이지 않음
	int search(int& pos, const tableKeyType& target);
};


template<class tableKeyType, class tableDataType>
HashTable <tableKeyType, tableDataType>::HashTable() {
	entries = 0;
	for (int i = 0; i < MAX_TABLE; i++) {
		T[i].slotStatus = Empty;
	}
}

template<class tableKeyType, class tableDataType>
bool HashTable <tableKeyType, tableDataType>::lookup(const tableKeyType& key, tableDataType& data) {
	int pos(hash(key));
	if (search(pos, key)) {
		data = T[pos].data;
		return true;
	}
	else {
		return false;
	}
}

template<class tableKeyType, class tableDataType>
void HashTable <tableKeyType, tableDataType>::insert(const tableKeyType& key, const tableDataType& data) {
	assert(entries < MAX_TABLE - 1); // 배열에서 한 개를 비운다 b/c search()할 때 Empty를 통해 마지막 원소를 만나면 끝나도록
	int pos(hash(key));
	if (!search(pos, key)) {
		pos = hash(key);
		while (T[pos].slotStatus == InUse) {
			pos = probe(pos);
		}
		entries++;
	}
	T[pos].slotStatus = InUse;
	T[pos].key = key;
	T[pos].data = data;
}


template<class tableKeyType, class tableDataType>
void HashTable <tableKeyType, tableDataType>::deleteKey(const tableKeyType& key) {
	int pos(hash(key));
	if (search(pos, key)) {
		T[pos].slotStatus = Deleted;
		entries--;
	}
}

template<class tableKeyType, class tableDataType>
int HashTable <tableKeyType, tableDataType>::hash(const tableKeyType& key) {
	return key % MAX_TABLE;
}

template<class tableKeyType, class tableDataType>
int HashTable <tableKeyType, tableDataType>::probe(const int pos) {
	if (pos < MAX_TABLE + 1) {
		return pos + 1;
	}
	else {
		return 0;
	}
}

template<class tableKeyType, class tableDataType>
int HashTable <tableKeyType, tableDataType>::search(int& pos, const tableKeyType& target) {
	for (; T[pos].slotStatus != Empty; pos = probe(pos)) {
		if (T[pos].slotStatus == InUse && T[pos].key == target) {
			return true;
		}
	}
	return false;
}

template<class tableKeyType, class tableDataType>
void HashTable<tableKeyType, tableDataType>::dump() {
	for (int i = 0; i < MAX_TABLE; i++) {
		cout << i << '\t';
		switch (T[i].slotStatus)
		{
		case InUse:
			cout << "In Use\t" << T[i].key << endl;
			break;
		case Deleted:
			cout << "Deleted\t" << T[i].key << endl;
			break;
		case Empty:
			cout << "Empty\t" << endl;
			break;
		}
	}
	cout << "Entires= " << entries << endl << endl;
}

#endif