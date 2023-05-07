#include <iostream>
using namespace std;

void insertionSort(int a[], int n);
void insertNextItem(int a[], int i, int n);

int main()
{
	int n = 0;
	string name = "Suho Han";
	int number = 20192650;

	cout << number << " " << name << endl;

	cout << "Type size of array: ";
	cin >> n;
	int *nums = new int[n];

	cout << "Insert " << n << " numbers" << endl;

	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}
	cout << "Sorted: ";
	insertionSort(nums, n);
	cout << endl;
	return 0;
}

void insertionSort(int a[], int n)
{
	int i;
	for (i = 1; i < n; i++)
	{
		insertNextItem(a, i, n);
	}
	for (i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}

void insertNextItem(int a[], int i, int n)
{
	int newItem(a[i]), insertPos(i);
	for (; insertPos && newItem < a[insertPos - 1]; insertPos--)
	{
		a[insertPos] = a[insertPos - 1];
		a[insertPos - 1] = newItem;
		for (i = 0; i < n; i++)
		{
			cout << a[i] << " ";
		}
		cout << endl;
	}
}
