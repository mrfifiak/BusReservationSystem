#pragma once

#include <iostream>

using namespace std;


class Time
{
public:
	int months;
	int days;
	int hours;
	int minutes;

	Time();	/*	TO DELETE	*/
	Time(int ho, int mi);	// constructor with months=0, days=0, hours=ho, minutes=mi
	Time(int mo, int da, int ho, int mi);	// constructor with months=mo, days=da, hours=ho, minutes=mi
	~Time();	// destructor

	friend ostream& operator<< (ostream&, Time const&);
};

