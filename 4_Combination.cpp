#include <iostream>
using namespace std;
int choose(int n, int k);
int factorial(int n);
int combination(int n, int k);

int recursion_n = 0;
int factorial_n = 0;

int main()
{
	string name = "Suho Han";
	int number = 20192650;

	cout << number << " " << name << endl;
	int n, k;
	cout << "Type N:";
	cin >> n;
	cout << "Type K:";
	cin >> k;


	cout << "choose: " << choose(n, k) << " with " << recursion_n << " times" << endl;
	cout << "combination: " << combination(n, k) << " with " << factorial_n << " times" << endl;
}

int choose(int n, int k)
{
	recursion_n++;
	if (k == 1)
		return n;
	else if (n == k)
		return 1;
	else
		return choose(n - 1, k - 1) + choose(n - 1, k);
}

int factorial(int n)
{
	factorial_n++;
	if (n <= 1)
	{
		return 1;
	}
	else {
		return n * factorial(n - 1);
	}
}

int combination(int n, int k)
{
	return factorial(n) / (factorial(n - k) * factorial(k));
}