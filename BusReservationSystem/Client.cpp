#include "client.h"

int Client::id_counter = 0;	// initializing id counter

// constructor with name
Client::Client(string n)
{
	name = n;
	id = id_counter++;
#ifdef _DEBUG
	cout << "Constructed Client " << name << " (ID: " << id << ")" << endl;
#endif
}

// destructor
Client::~Client()
{
#ifdef _DEBUG
	cout << "Destroyed Client with id " << id << endl;
#endif
}

// returns ID
int Client::getID() const
{
	return id;
}

// changes the name of the client
void Client::change_data(string newname)
{
	name = newname;
#ifdef _DEBUG
	cout << "Changed client's name to " << name << endl;
#endif
}

bool Client::is_enrolled(int tid)
{
	list<Trip*>::iterator it;

	for (it = booked_trips.begin(); it != booked_trips.end(); ++it)
	{
		if ((*it)->getID() == tid)
		{
			return true;
		}
	}
	return false;
}

bool Client::does_overlap(Time ntdep, Time ntdur)
{
	if (booked_trips.empty())
	{
		return false;
	}
	else
	{
		list<Trip*>::iterator it; 
		for (it = booked_trips.begin(); it != booked_trips.end(); ++it)
		{
			Time depar = (*it)->getDep();
			Time temp = ntdep + ntdur;
			if (depar > ntdep && temp > depar)
			{
				return true;
			}
		}
		for (it = booked_trips.begin(); it != booked_trips.end(); ++it)
		{
			Time depar = (*it)->getDep();
			Time temp = (*it)->getDep() + (*it)->getDur();
			if (ntdep > depar && temp > ntdep)
			{
				return true;
			}
		}
		return false;
	}
}

// books given trip
void Client::book_trip(Trip * newtrip)
{
	booked_trips.push_back(newtrip);
}

// cancels given trip
void Client::cancel_trip(Trip* deltrip)
{
	booked_trips.remove(deltrip);
}

ostream & operator<<(ostream & o, Client const & c)
{
	o <<  c.id << "\t" << c.name;
	return o;
}
