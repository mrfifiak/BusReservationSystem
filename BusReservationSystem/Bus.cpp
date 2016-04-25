#include "bus.h"



int Bus::id_counter = 0;	// initializing id counter


// constructor which sets bus' capacity
Bus::Bus(int cap)
{
	capacity = cap;
	id = id_counter++;
	assigned_trip = NULL;
#ifdef _DEBUG
		cout << "Created Bus with capacity " << capacity << " (ID: " << id << ")" << endl;
#endif
}

//destructor
Bus::~Bus()
{
#ifdef _DEBUG
	cout << "Destroyed Bus with id " << id << endl;
#endif
}

// returns ID
int Bus::getID()
{
	return id;
}

// returns capacity
int Bus::getCapacity()
{
	return capacity;
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
ostream & operator<<(ostream & o, Bus const & b)
{
	o << "Bus ID: " << b.id << " capacity " << b.capacity;
	return o;
}
