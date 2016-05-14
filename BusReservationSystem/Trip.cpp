#include "trip.h"


int Trip::id_counter = 0;	// initializing id counter

// constructor with all attributes
Trip::Trip(string f, string t, unsigned int di, int depmo, int depda, int depho, int depmi, int durho, int durmi)
{
	from = f;
	to = t;
	distance = di;
	departure = Time(depmo, depda, depho, depmi);
	duration = Time(durho, durmi);
	assigned_bus = NULL;
	id = id_counter++;
#ifdef _DEBUG
	cout << "Constructor Trip " << id << ' ' << f << " -> " << t << ' ' << distance << "km " << departure << ' ' << duration << endl;
#endif
}

Trip::Trip(string f, string t, unsigned int di, Time dep, Time dur)
{
	from = f;
	to = t;
	distance = di;
	departure = dep;
	duration = dur;
	assigned_bus = NULL;
	id = id_counter++;
#ifdef _DEBUG
	cout << "Constructor Trip " << id << ' ' << f << " -> " << t << ' ' << distance << "km " << departure << ' ' << duration << endl;
#endif
}

// destructor
Trip::~Trip()
{
#ifdef _DEBUG
	cout << "Destructor Trip " << id << endl;
#endif
}


// returns true if the number of enrolled passengers == bus capacity
bool Trip::isfull()
{
	return false;
}

// assign bus with given id
return_state Trip::assign_bus(int id)
{
	return return_state();
}

// dismiss the assigned bus
return_state Trip::dismiss_bus()
{
	return return_state();
}

// changes all the attributes of the departure time
return_state Trip::change_departure_time(int mo, int da, int ho, int mi)
{
	return return_state();
}

// changes the time (hh:mm) of the departure
return_state Trip::change_departure_time(int ho, int mi)
{
	return return_state();
}

// changes the date of the departure
return_state Trip::change_departure_date(int mo, int da)
{
	return return_state();
}

// prints enrolled clients
void Trip::print_clients()
{
}

// operator <<
ostream & operator<<(ostream & o, Trip const & t)
{
	return o;
}
