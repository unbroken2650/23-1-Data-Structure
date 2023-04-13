#include <iostream>
using namespace std;
typedef float mytype;

void fillArray(mytype* a, int size, int& sizeOfArray);
int partition(mytype a[], int first, int last);
void quicksort(mytype a[], int first, int last);
void swapElements(mytype a[], int first, int second);
void printArray(mytype a[], int first, int last);

int main()
{
	const int MAX_SIZE = 100;
	int sizeOfArray;
	mytype a[MAX_SIZE];
	fillArray(a, MAX_SIZE, sizeOfArray);
	quicksort(a, 0, sizeOfArray);
	printArray(a, 0, sizeOfArray);
}

void quicksort(mytype a[], int first, int last)
{
	if(first >= last)
		return;
	int split(partition(a, first, last));
	quicksort(a, first, split-1);
	quicksort(a, split + 1, last);
}

int partition(mytype a[], int first, int last)
{
	int lastSmall(first), i;
	cout << "Before partition : ";
	for (int i = first; i < last; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	for (i = first + 1; i <= last; i++)
	{
		if (a[i] <= a[first]) {
			++lastSmall;
			swapElements(a, lastSmall, i);
		}
	}
	swapElements(a, first, lastSmall);
	cout << "After partition : ";
	for (int i = first; i < last; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	cout << endl;
	return lastSmall;
}

void swapElements(mytype a[], int first, int second)
{
	mytype temp = a[first];
	a[first] = a[second];
	a[second] = temp;
}

void fillArray(mytype a[], int size, int& sizeOfArray)
{
	cout << " enter up to " << size << " nonnegative whole numbers" << endl
		<< "Mark the end of the list with a negative number" << endl;
	mytype next;
	int index = 0;
	cin >> next;
	while ((next >= 0) && (index < size))
	{
		a[index] = next;
		index++;
		cin >> next;
	}
	sizeOfArray = index -1;

}

void printArray(mytype a[], int first, int last)
{
	cout << "Sorted" << endl;
	cout << "----------------------------------------" << endl;
	for (int i = first; i < last; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}