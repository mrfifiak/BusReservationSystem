#pragma once

#include "Bus.h"
#include "Client.h"
#include "Time.h"

#include <iostream>
#include <list>
#include <string>


using namespace std;

class Trip
{

private:
	int trip_id;	// trip's identification number
	string from;	// start place
	string to;	// arrival place
	unsigned int distance;	// distance in km
	Time departure;	// departure time in mm:dd:hh:mm
	Time duration;	// duration in hh:mm
	Bus* assigned_bus;	// pointer to the bus assigned to the trip
	list<Client*> enrolled_clients;	// list of pointers to enrolled clients

public:
	Trip(string f, string t, int di, int depmo, int depda, int depho, int depmi, int durho, int durmi);
	~Trip();
};

