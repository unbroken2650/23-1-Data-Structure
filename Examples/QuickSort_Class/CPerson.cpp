#include "CPerson.h"
#include <string>
#include <iostream>

CPerson::CPerson()
{
	m_strName = "";
	m_nAge = 0;
}

CPerson::CPerson(string strName, int nAge)
{
	m_strName = strName;
	m_nAge = nAge;
}

string CPerson::GetName() const
{
	return m_strName;
}

void CPerson::SetName(string strName)
{
	m_strName = strName;
}

int CPerson::GetAge() const
{
	return m_nAge;
}

void CPerson::SetAge(int nAge)
{
	m_nAge = nAge;
}


