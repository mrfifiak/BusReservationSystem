#ifndef BUS_H
#define BUS_H

#include "mylib.h"
#include "trip.h"


#include <iostream>
#include <list>

using namespace std;
class Trip;
enum return_state;


class Bus
{

private:
	int id;	// bus' identification number
	int capacity;	// how many passengers can sit
	Trip* assigned_trip;	// the trip which the bus is assigned to

	static int id_counter;	// static variable used to assign new ids

public:
	Bus(int cap);	// constructor which sets bus' capacity
	~Bus();	//destructor

	int getID();	// returns ID
	int getCapacity();	// returns capacity
	int getTripID();	// returns ID of assigned trip, -1 if no trip assigned 
	void assign_trip(Trip* newtrip);	// assigns trip with given id
	void dismiss_trip();	// dismisses the assigned trip

	friend ostream & operator<<(ostream &o, Bus const &b);	// operator <<

};


#endif // !BUS_H