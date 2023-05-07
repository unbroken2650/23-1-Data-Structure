#include "MyClass.h"
#include <string>
#include <iostream>

MyClass::MyClass()
{
	number = 0;
}

MyClass::MyClass(int num)
{
	number = num;
}

int MyClass::GetNumber() const
{
	return number;
}

void MyClass::SetNumber(int num)
{
	number = num;
}


