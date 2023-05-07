#include <iostream>
#include "QueueLL.h"
#include "MyClass.h"

using namespace std;

int main()
{
	string name = "Suho Han";
	int number = 20192650;

	cout << number << " " << name << endl;

	int num;
	MyClass c;
	Queue <MyClass> q;

	while (1)
	{
		cin >> num;
		c.SetNumber(num);
		if (num == 0) {
			break;
		}
		q.enqueue(c);
	}
	while (!q.isEmpty()) {
		cout << q.dequeue().GetNumber() << endl;
	}
	return 0;
}