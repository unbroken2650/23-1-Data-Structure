#include <iostream>
using namespace std;

int binarySearch(int a[], int n, int target);
int main()
{
	int n = 0;
	int target;

	cout << "Type size of array: ";
	cin >> n;
	int *nums = new int[n];

	cout << "Insert " << n << " numbers" << endl;

	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}

	cout << "Insert number to find." << endl;
	cin >> target;

	cout << target << " is in " << binarySearch(nums, n, target) + 1 << endl;

	return 0;
}

int binarySearch(int a[], int n, int target)
{
	int first(0);
	int last(n - 1);
	int mid;
	while (first <= last)
	{
		mid = (first + last) / 2;
		if (target == a[mid])
			return mid;
		else if (target < a[mid])
			last = mid;
		else
			first = mid + 1;
	}
	return -1;
}