#ifndef BUS_H
#define BUS_H

#include "trip.h"

#include <iostream>
#include <list>

using namespace std;
class Trip;
enum return_state;


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
	return_state assign_trip(int id);	// assigns trip with given id
	return_state dismiss_trip();	// dismisses the assigned trip

	friend ostream & operator<<(ostream &o, Bus const &t);	// operator <<

};


#endif // !BUS_H