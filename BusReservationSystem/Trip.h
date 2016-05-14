#ifndef TRIP_H
#define TRIP_H

#include "bus.h"
#include "client.h"
#include "mylib.h"
#include "time.h"

#include <iomanip>
#include <iostream>
#include <list>
#include <string>


using namespace std;
class Client;
class Bus;




class Trip
{

private:
	int id;	// trip's identification number
	string from;	// start place
	string to;	// arrival place
	unsigned int distance;	// distance in km
	Time departure;	// departure time in mm:dd:hh:mm
	Time duration;	// duration in hh:mm
	Bus* assigned_bus;	// pointer to the bus assigned to the trip
	list<Client*> enrolled_clients;	// list of pointers to enrolled clients

	static int id_counter;	// static variable used to assign new ids

public:
	Trip(string f, string t, unsigned int di, int depmo, int depda, int depho, int depmi, int durho, int durmi);	// constructor with all attributes
	Trip(string f, string t, unsigned int di, Time dep, Time dur);
	~Trip();	// destructor

	bool isfull();	// returns true if the number of enrolled passengers passengers == bus capacity
	return_state assign_bus(int id);	// assign bus with given id
	return_state dismiss_bus();	// dismiss the assigned bus
	return_state change_departure_time(int mo, int da, int ho, int mi);	// changes all the attributes of the departure time
	return_state change_departure_time(int ho, int mi);	// changes the time (hh:mm) of the departure
	return_state change_departure_date(int mo, int da);	// changes the date of the departure
	void print_clients();	// prints enrolled clients

	friend ostream & operator<<(ostream &o, Trip const &t);	// operator <<
};


#endif // !TRIP_H