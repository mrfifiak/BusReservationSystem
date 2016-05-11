#ifndef BUSRS_H
#define BUSRS_H

#include "bus.h"
#include "client.h"
#include "mylib.h"
#include "trip.h"

#include <iostream>
#include <limits>	// for safe data input
#include <list>

using namespace std;

class BusReservationSystem
{
public:
	list<Bus> buses;	// list of all buses
	list<Trip> trips;	// list of all trips
	list<Client> clients;	// list of all clients

	BusReservationSystem();	// default constructor
	~BusReservationSystem();	// destructor

	void menu();	// main menu
	void new_client(string name);	// adds a new client
	void remove_client();	// removes a client
	void new_bus();	// creates a bus
	void remove_bus();	// removes a bus
	void new_trip();	// creates a new trip
	void remove_trip();	// removes a trip
	void change_client_data();	// changes client's data
	void assign_bus_to_trip();	// choose a bus, then choose the trip
	void dismiss_a_bus();	// choose the bus
	void assign_trip_to_bus();	// choose a trip, then choose the bus
	void dismiss_a_trip();	// choose the trip
	void change_trip_data();	// changes trip's data
	void print_trips();	// prints all trips with buses and clients
	void print_timetable();	// prints all trips' basic data
	void check_trips();	// checks if all the trips have their buses
};


#endif // !BUSRS_H