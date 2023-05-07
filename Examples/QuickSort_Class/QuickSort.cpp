#include <iostream>
using namespace std;

void fillArray(int *a, int size, int &sizeOfArray);
int partition(int a[], int first, int last);
void quicksort(int a[], int first, int last);
void swapElements(int a[], int first, int second);
void printArray(int a[], int first, int last);

int main()
{
	const int MAX_SIZE = 100;
	int sizeOfArray;
	int a[MAX_SIZE];
	fillArray(a, MAX_SIZE, sizeOfArray);
	quicksort(a, 0, sizeOfArray);
	printArray(a, 0, sizeOfArray);
}

void quicksort(int a[], int first, int last)
{
	if (first >= last)
		return;
	int split(partition(a, first, last));
	quicksort(a, first, split - 1);
	quicksort(a, split + 1, last);
}

int partition(int a[], int first, int last)
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
		if (a[i] <= a[first])
		{
			++lastSmall;
			swapElements(a, lastSmall, i);
			for (int i = first; i < last; i++)
			{
				cout << a[i] << " ";
			}
			cout << endl;
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

void swapElements(int a[], int first, int second)
{
	int temp = a[first];
	a[first] = a[second];
	a[second] = temp;
}

void fillArray(int a[], int size, int &sizeOfArray)
{
	cout << " enter up to " << size << " nonnegative whole numbers" << endl
			 << "Mark the end of the list with a negative number" << endl;
	int next, index = 0;
	cin >> next;
	while ((next >= 0) && (index < size))
	{
		a[index] = next;
		index++;
		cin >> next;
	}
	sizeOfArray = index - 1;
}

void printArray(int a[], int first, int last)
{
	cout << "Sorted" << endl;
	cout << "----------------------------------------" << endl;
	for (int i = first; i < last; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}