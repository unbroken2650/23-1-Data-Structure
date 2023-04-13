#pragma once
#include <string>
using namespace std;
class CPerson
{
private:
	string m_strName;
	int m_nAge;
public:
	CPerson(string strName, int nAge);
	CPerson();
	string GetName() const;
	void SetName(string strName);
	int GetAge() const;
	void SetAge(int nAge);
	friend istream& operator >>(istream& inputStream, CPerson& person);
	friend ostream& operator <<(ostream& outputStream, const CPerson& person);
	friend bool operator <= (const CPerson& personA, const CPerson& personB);
	friend bool operator >= (const CPerson& personA, const CPerson& personB);
};




