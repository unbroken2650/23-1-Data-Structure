#pragma once
#ifndef __MB_CX10_1__
#define __MB_CX10_1__

const int MAX_TABLE = 100;

template<class tableKeyType, class tableDataType>
class Table {
public:
	Table();
	bool lookup(tableKeyType lookupKey, tableDataType& data);
	void insert(tableKeyType insertKey, tableDataType insertData);
	void deleteKey(tableKeyType deleteKey);
private:
	struct item {
		tableKeyType key;
		tableDataType data;
	};
	item T[MAX_TABLE];
	int entries;
	int search(tableKeyType key);
};

template<class tableKeyType, class tableDataType>
Table <tableKeyType, tableDataType>::Table() {
	entries = 0;
}

template<class tableKeyType, class tableDataType>
void Table <tableKeyType, tableDataType>::insert(tableKeyType key, tableDataType data) {
	assert(entries < MAX_TABLE); // 꽉 차 있으면 변경도 안 된다
	int pos(search(key)); // 비어있는 위치가 반환되므로 그 자리에 새로운 데이터 바로 넣을 수 있음
	if (pos == entries) {
		entries++;
	}
	T[pos].key = key;
	T[pos].data = data;
}

template<class tableKeyType, class tableDataType>
bool Table <tableKeyType, tableDataType>::lookup(tableKeyType key, tableDataType& data) {
	assert(entries < MAX_TABLE);
	int pos(search(key));
	if (pos == entries) {
		return false;
	}
	else {
		data = T[pos].data;
		return true;
	}
}

template<class tableKeyType, class tableDataType>
void Table <tableKeyType, tableDataType>::deleteKey(tableKeyType key) {
	int pos(search(key));
	if (pos < entries) {
		--entries;
		T[pos] = T[entries];
	}
}

template<class tableKeyType, class tableDataType>
int Table <tableKeyType, tableDataType>::search(tableKeyType key) {
	int pos;
	for (pos = 0; pos < entries && T[pos].key != key; pos++);
	return pos;
}

#endif