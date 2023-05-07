#include <iostream>
#include "QueueLL.h"

using namespace std;

int main()
{
	char c;
	Queue <char> q;

	while (1)
	{
		cin >> c;
		if (c == '.') {
			break;
		}
		q.enqueue(c);
	}
	return 0;
}