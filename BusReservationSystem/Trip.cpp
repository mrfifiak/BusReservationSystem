#include "trip.h"




// constructor with all attributes
Trip::Trip(string f, string t, int di, int depmo, int depda, int depho, int depmi, int durho, int durmi)
{
}

// destructor
Trip::~Trip()
{
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

// operator <<
ostream & operator<<(ostream & o, Trip const & t)
{
	return o;
}
