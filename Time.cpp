#include "Time.h"
#include <iostream>
using namespace std;

void Time::readTime(bool &errorFlag)
{
	enum AM_PM
	{
		AM,
		PM
	} AM_or_PM;
	int hour, minute;
	const char delimiter = ':';

	errorFlag = true;
	if (!(cin >> hour))
		return;
	if (hour < 0 || hour > 12)
		return;
	char c;
	cin >> c;
	if (c != delimiter)
		return;
	if (!(cin >> minute)) 
		return;
	if (minute < 0 || minute > 59)
		return;
	cin >> c;
	if (c == 'A' || c == 'a')
		AM_or_PM = AM;
	else if (c == 'P' || c == 'p')
		AM_or_PM = PM;
	else
		return;
	cin >> c;
	if (c != 'M' && c != 'm')
		return;
	errorFlag = false;

	if (hour == 12)
		minutes = minute;
	else
		minutes = hour * 60 + minute;
	if (AM_or_PM == PM)
		minutes += 60 * 12;
}

int Time::subtractTimes(Time t)
{
	return minutes - t.minutes;
}

int Time::AddTime(int nTime)
{
	minutes += nTime;
	return minutes + nTime;
}

void Time::PrintTime()
{
	int hour(0), minute(minutes);
	enum AM_PM
	{
		AM,
		PM
	} AM_or_PM;
	hour = minute / 60;
	if (hour > 12)
	{
		hour -= 12;
		AM_or_PM = PM;
	}
	else
	{
		AM_or_PM = AM;
	}
	minute = minute % 60;
	cout << hour << ":" << minute;
	if (AM_or_PM)
	{
		cout << "PM";
	}
	else
	{
		cout << "AM";
	}
}