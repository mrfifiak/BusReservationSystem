#include "bus.h"


int Bus::id_counter = 0; // initializing id counter


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
int Bus::getID() const
{
	return id;
}

// returns capacity
int Bus::getCapacity() const
{
	return capacity;
}

// returns ID of assigned trip
int Bus::getTripID() const
{
	if (assigned_trip == NULL)
	{
		return -1;
	}
	else
	{
		return assigned_trip->getID();
	}
}

// assigns given trip 
void Bus::assign_trip(Trip* newtrip)
{
	assigned_trip = newtrip;
}

// dismisses the assigned trip
void Bus::dismiss_trip()
{
	assigned_trip = NULL;
}

// operator <<
ostream& operator<<(ostream& o, Bus const& b)
{
	o << "Bus ID: " << b.id << " capacity: " << b.capacity;
	return o;
}
