#pragma once


class Time {
public:
	void readTime(bool& errorFlag);
	int subtractTimes(Time t);
private:
	int minutes;
public:
	int AddTime(int nTime);
	void PrintTime();
};