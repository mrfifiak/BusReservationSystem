#ifndef BUSRS_H
#define BUSRS_H

#include "bus.h"
#include "client.h"
#include "mylib.h"
#include "trip.h"

#include <iostream>
#include <list>

using namespace std;

class BusReservationSystem
{
private:
	static bool compareTrips(const Trip& t1, const Trip& t2); // return true if t1 starts before t2

public:
	list<Bus> buses; // list of all buses
	list<Trip> trips; // list of all trips
	list<Client> clients; // list of all clients

	BusReservationSystem(); // default constructor
	~BusReservationSystem(); // destructor


	void new_client(string name); // adds a new client
	void remove_client(int id); // removes a client
	void change_client_data(int id); // changes client's data

	void new_bus(int cap); // creates a bus
	void remove_bus(int id); // removes a bus
	void free_bus(int id); // dismisses selected bus from the trip and vice versa
	void check_buses(); // checks if all the buses have a trip assigned

	void new_trip(string from, string to, unsigned int di, Time dep, Time dur); // creates a new trip
	void new_trip(string from, string to, unsigned int di, int depmo, int depda, int depho, int depmi, int durho, int durmi); // creates a new trip
	void remove_trip(int id); // removes a trip
	void check_trips(); // checks if all the trips have their buses
	void free_trip(int id); // dismisses selected trip from the bus and vice versa
	void change_trip_departure_time(int id, int mo, int da, int ho, int mi); // changes trip's data
	void change_trip_departure_time(int id, int ho, int mi); // changes trip's data
	void change_trip_date(int id, int mo, int da); // changes trip's data

	void assign_bus_to_trip(int bid, int tid); // assigns bus to a trip and vice versa
	void enroll_client_to_trip(int cid, int tid); // enrolls client to a trip and vice versa
	void cancel_trip(int cid, int tid); // cancels given trip for given client

	void print_trips(); // prints all trips' data with bus ID and number of clients
	void print_trip_clients(int id); // prints trip's basic data with list of clients
	void print_timetable(); // prints all trips' basic data
};


#endif // !BUSRS_H
