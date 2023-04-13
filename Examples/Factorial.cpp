#include <iostream>
using namespace std;

int factorial(int n);

int main()
{
	int n;
	cout << "Put number: ";
	cin >> n;
	cout << "Factorial of " << n << " is " << factorial(n);
}

int factorial(int n)
{
	if (n <= 1)
	{
		return 1;
	}
	else {
		return n * factorial(n - 1);
	}
}