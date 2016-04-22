#ifndef CLIENT_H
#define CLIENT_H

#include "trip.h"

#include <iostream>
#include <list>
#include <string>

using namespace std;
class Trip;

class Client
{

private:
	int client_id;	// client's identification number
	string name;	// name and surname
	list<Trip*> booked_trips;	// list of pointers to trips which the client booked


public:
	Client(string n);
	~Client();
};


#endif // !CLIENT_H