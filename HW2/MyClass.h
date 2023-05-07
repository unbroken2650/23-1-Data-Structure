#pragma once
#include <string>
using namespace std;
class MyClass
{
private:
	int number;
public:
	MyClass(int num);
	MyClass();
	int GetNumber() const;
	void SetNumber(int num);
	friend istream& operator >>(istream& inputStream, MyClass& person);
	friend ostream& operator <<(ostream& outputStream, const MyClass& person);
	friend bool operator <= (const MyClass& personA, const MyClass& personB);
	friend bool operator >= (const MyClass& personA, const MyClass& personB);
};




