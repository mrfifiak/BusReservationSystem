#include "bus.h"


int Bus::id_counter = 0;	// initializing id counter


// constructor which sets bus' capacity
Bus::Bus(int cap)
{
}

//destructor
Bus::~Bus()
{
}

// returns true if passengers == capacity
bool Bus::isfull()
{
	return false;
}

// assigns trip with given id
return_state Bus::assign_trip(int id)
{
	return return_state();
}

// dismisses the assigned trip
return_state Bus::dismiss_trip()
{
	return return_state();
}

// operator <<
ostream & operator<<(ostream & o, Bus const & t)
{
	return o;
}
