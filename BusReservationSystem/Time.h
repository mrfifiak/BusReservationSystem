#ifndef TIME_H
#define TIME_H

#include <stdio.h>
#include <string>
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

	/* OPERATORS */
	bool operator == (const Time &time) const;
	bool operator != (const Time &time) const;
	bool operator > (const Time &time) const;
	Time& operator = (const Time &time);
	Time operator + (const Time &time) const;
	Time& operator += (const Time &time);

	friend ostream& operator<< (ostream&, Time const&);	// operator <<
};

#endif	// !TIME_H
