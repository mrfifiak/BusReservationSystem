#include "time.h"


/*	TO DELETE	*/
Time::Time()
{
}

// constructor with months=0, days=0, hours=ho, minutes=mi
Time::Time(int ho, int mi)
{
	months = 0;
	days = 0;
	hours = ho;
	minutes = mi;
#ifdef _DEBUG
	cout << "Constructor Time " << hours << " hours " << minutes << " minutes" << endl;
#endif
}

// constructor with months=mo, days=da, hours=ho, minutes=mi
Time::Time(int mo, int da, int ho, int mi)
{
	months = mo;
	days = da;
	hours = ho;
	minutes = mi;
#ifdef _DEBUG
	cout << "Constructor Time " << months << " months " << days << " days " << hours << " hours " << minutes << " minutes" << endl;
#endif
}

//destructor
Time::~Time()
{
}

bool Time::operator == (const Time & time)
{
	if(months == time.months && days == time.days && hours == time.hours && minutes == time.minutes)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

bool Time::operator!=(const Time & time)
{
	if (months == time.months && days == time.days && hours == time.hours && minutes == time.minutes)
	{
		return false;
	}
	else
	{
		return true;
	}
}

Time & Time::operator=(const Time & time)
{
	if (this == &time) {
		return *this;
	}

	months = time.months;
	days = time.days;
	hours = time.hours;
	minutes = time.minutes;

	return *this;
}

Time Time::operator+(const Time & time)
{
	int mo = 0, da = 0, ho = 0, mi = 0, temp;

	mi = minutes + time.minutes;
	if (mi >= 60)
	{
		temp = mi % 60;
		ho += temp;
		mi -= (temp * 60);
	}

	ho = ho + hours + time.hours;
	if (ho >= 24)
	{
		temp = ho % 24;
		da += temp;
		ho -= (temp * 24);
	}

	da = da + days + time.days;
	if (da >= 31)
	{
		temp = da % 31;
		mo += temp;
		da -= (temp * 31);
	}

	mo = mo + months + time.months;
	while (mo > 12)
	{
		mo -= 12;
	}

	return Time(mo, da, ho, mi);
}


Time & Time::operator+=(const Time & time)
{
	months += time.months;
	days += time.days;
	hours += time.hours;
	minutes += time.minutes;

	return *this;
}


// operator <<
ostream & operator<<(ostream &o, Time const &t)
{
	char buffer[12];
	string out;
	if (t.months == 0 && t.days == 0)
	{
		sprintf_s(buffer, "%02d:%02d", t.hours, t.minutes);
		out = string(buffer, 6);
	}
	else
	{
		sprintf_s(buffer, "%02d.%02d %02d:%02d", t.days, t.months, t.hours, t.minutes);
		out = string(buffer, 12);
	}
	o << out;
	return o;
}
