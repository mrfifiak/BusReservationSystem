#ifndef CLIENT_H
#define CLIENT_H

#include "mylib.h"
#include "time.h"
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
	int id; // client's identification number
	string name; // name and surname
	list<Trip*> booked_trips; // list of pointers to trips which the client booked

	static int id_counter; // static variable used to assign new ids

public:
	explicit Client(string n); // constructor with name
	~Client(); // destructor

	int getID() const; // returns ID
	void change_data(string newname); // changes the name of the client
	bool is_enrolled(int tid); // checks if the client is enrolled to the trip with given ID
	bool does_overlap(Time ntdep, Time ntdur); // checks if the trip with ntdep and ntdur values overlaps with the trips the client already enrolled to
	void book_trip(Trip* newtrip); // books given trip
	void cancel_trip(Trip* deltrip); // cancels given trip
	void cancel_all_trips(); // cancels all trips

	friend ostream& operator<<(ostream& o, Client const& c); // operator <<
	
};


#endif // !CLIENT_H
