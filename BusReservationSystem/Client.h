#ifndef CLIENT_H
#define CLIENT_H

#include "mylib.h"
#include "trip.h"

#include <iostream>
#include <list>
#include <string>

using namespace std;
class Trip;
enum return_state;



class Client
{

private:
	int id;	// client's identification number
	string name;	// name and surname
	list<Trip*> booked_trips;	// list of pointers to trips which the client booked

	static int id_counter;	// static variable used to assign new ids

public:
	Client(string n);	// constructor with name
	~Client();	// destructor

	return_state change_data(string newname);	// changes the name of the client
	return_state book_trip(int id);	// books trip with given id
	return_state cancel_trip(int id);	// cancels trip with given id

	friend ostream & operator<<(ostream & o, Trip const & t);	// operator <<


};


#endif // !CLIENT_H