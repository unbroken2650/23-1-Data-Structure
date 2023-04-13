#include <iostream>
using namespace std;

void insertNextItem(int a[], int i);
void insertionSort(int a[], int n);

int main()
{
    int n = 0;
    cin >> n;
    int nums[n];

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    insertionSort(nums, n);
    return 0;
}

void insertionSort(int a[], int n)
{
    int i;
    for (i = 1; i < n; i++)
    {
        insertNextItem(a, i);
    }
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

void insertNextItem(int a[], int i)
{
    int newItem(a[i]), insertPos(i);
    for (; insertPos && newItem < a[insertPos - 1]; insertPos--)
    {
        a[insertPos] = a[insertPos - 1];
        a[insertPos - 1] = newItem;
    }
}