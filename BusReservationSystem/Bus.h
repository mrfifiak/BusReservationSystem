#ifndef BUS_H
#define BUS_H

#include "trip.h"

#include <iostream>
#include<list>

using namespace std;
class Trip;

class Bus
{

private:
	int bus_id;	// bus' identification number
	int capacity;	// how many passengers can sit
	int passengers;	// number of clients who enrolled into the bus' trip
	Trip* assigned_trip;	// the trip which the bus is assigned to

public:
	Bus(int cap);	// constructor which sets bus' capacity
	~Bus();	//destructor

	bool isfull();	// returns true if passengers == capacity

};


#endif // !BUS_H