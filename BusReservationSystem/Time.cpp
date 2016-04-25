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

// operator <<
ostream & operator<<(ostream &o, Time const &t)
{
	char buffer[12];
	string out;
	sprintf_s(buffer, "%02d.%02d %02d:%02d", t.days, t.months, t.hours, t.minutes);
	out = string(buffer, 12);
	o << out;
	return o;
}
