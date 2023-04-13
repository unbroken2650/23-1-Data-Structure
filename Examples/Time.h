#pragma once


class Time {
	//
	// Characteristics:
	//
	//   A Time consists of some number of hours and minutes, and is either before noon
	//   (AM) or after noon (PM). 
	//
	//   Twelve Noon is 12:00 PM and Twelve Midnight is 12:00 AM. 
	//
	//   All Times are assumed to fall on the same day.
	//
public:
	void readTime(bool& errorFlag);
	//   Precondition: Standard input has characters available.
	//   Postconditions: Leading whitespace characters are ignored; 
	//      readTime attempts to read, from standard input, a time in 
	//      the format <HH>:<MM><A>, where <HH> is an integer between 
	//      1 and 12, <MM> is an integer between 0 and 59, and <A> is 
	//      either "AM" or "PM". If a properly formatted time can be 
	//      read, errorFlag is set to false, and the value of the Time
	//      variable is set to the time read; otherwise, errorFlag is 
	//      set to true.
	int subtractTimes(Time t);
	//   Precondition: This Time variable contains a proper value.
	//   Postcondition: None.
	//   Returns: The difference, in minutes, between this Time and Time t. 
	//      If this Time occurs prior to Time t, the returned difference 
	//      is negative.

	// **** the rest of the class declaration is private
private:
	int minutes;
public:
	int AddTime(int nTime);
	void PrintTime();
};
