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


	void new_client(string name);	// adds a new client
	void remove_client(int id);	// removes a client
	void change_client_data(int id);	// changes client's data

	void new_bus(int cap);	// creates a bus
	void remove_bus(int id);	// removes a bus
	void free_bus(int id);	// dismiss selected bus from the trip and vice versa

	void new_trip(string from, string to, unsigned int di, Time dep, Time dur);	// creates a new trip
	void remove_trip(int id);	// removes a trip
	void check_trips();	// checks if all the trips have their buses
	void free_trip(int id);	// dismiss selected trip from the bus and vice versa
	
	void assign_bus_to_trip(int bid, int tid);	// assigns bus to a trip and vice versa


	void change_trip_departure_time(int id, int mo, int da, int ho, int mi);	// changes trip's data
	void change_trip_departure_time(int id, int ho, int mi);	// changes trip's data
	void change_trip_date(int id, int mo, int da);	// changes trip's data
	void print_trips();	// prints all trips' data with bus ID and number of clients
	void print_trip_clients(int id);	// prints trip's basic data with list of clients
	void print_timetable();	// prints all trips' basic data

	
};


#endif // !BUSRS_H