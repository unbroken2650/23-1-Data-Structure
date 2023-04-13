#include <string>
#include <iostream>
#include "CPerson.h"
using namespace std;

void fillArray(CPerson* names, int size, int& sizeOfArray);
int partition(CPerson names[], int first, int last);
void quicksort(CPerson names[], int first, int last);
void swapElements(CPerson names[], int first, int second);
void printArray(CPerson names[], int first, int last);

int main()
{
	const int MAX_SIZE = 100;
	int sizeOfArray;
	CPerson names[MAX_SIZE];
	fillArray(names, MAX_SIZE, sizeOfArray);
	quicksort(names, 0, sizeOfArray - 1);
	printArray(names, 0, sizeOfArray);
}

void quicksort(CPerson names[], int first, int last)
{
	if (first >= last)
		return;
	int split(partition(names, first, last));
	quicksort(names, first, split - 1);
	quicksort(names, split + 1, last);
}

int partition(CPerson names[], int first, int last)
{
	int lastSmall(first), i;
	cout << "Before partition : ";
	for (int i = first; i <= last; i++)
	{
		cout << names[i].GetName() << " ";
		cout << names[i].GetAge() << " ";
	}
	cout << endl;
	for (i = first + 1; i <= last; i++)
	{
		if (names[i].GetAge() <= names[first].GetAge()) {
			++lastSmall;
			swapElements(names, lastSmall, i);
		}
	}
	swapElements(names, first, lastSmall);
	cout << "After partition : ";
	for (int i = first; i < last; i++)
	{
		cout << names[i].GetName() << " ";
		cout << names[i].GetAge() << " ";
	}
	cout << endl;
	cout << endl;
	return lastSmall;
}

void swapElements(CPerson names[], int first, int second)
{
	CPerson temp = names[first];
	names[first] = names[second];
	names[second] = temp;
}

void fillArray(CPerson names[], int size, int& sizeOfArray)
{
	cout << " enter up to " << size << " nonnegative whole numbers" << endl
		<< "Mark the end of the list with names negative number" << endl;
	CPerson next;
	int index = 0;
	cin >> next;
	while (index < size)
	{
		names[index] = next;
		if (next.GetAge() < 0)
		{
			sizeOfArray = index;
			cout << "size of array is " << index << endl;
			break;
		}
		index++;
		cin >> next;
	}
	sizeOfArray = index - 1;

}

void printArray(CPerson names[], int first, int last)
{
	cout << "Sorted" << endl;
	cout << "----------------------------------------" << endl;
	for (int i = first; i <= last; i++)
	{
		cout << names[i].GetName() << " ";
		cout << names[i].GetAge() << " ";
	}
	cout << endl;
}

istream& operator >>(istream& inputStream, CPerson& person)
{
	string tempName;
	int tempAge;
	inputStream >> tempName;
	inputStream >> tempAge;
	person.SetName(tempName);
	person.SetAge(tempAge);
	return inputStream;
}

ostream& operator <<(ostream& outputStream, const CPerson& person)
{
	string tempName = person.GetName();
	int tempAge = person.GetAge();
	outputStream << tempName << " ";
	outputStream << tempAge << " ";
	if (tempAge < 0) {
		return outputStream;
	}
	return outputStream;
}

bool operator <=(const CPerson& personA, const CPerson& personB)
{
	return personA.GetAge() <= personB.GetAge();
}

bool operator >=(const CPerson& personA, const CPerson& personB)
{
	return personA.GetAge() >= personB.GetAge();
}