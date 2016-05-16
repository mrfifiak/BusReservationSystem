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
int Client::getID()
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

// books trip with given id
return_state Client::book_trip(int id)
{
	return return_state();
}

// cancels trip with given id
return_state Client::cancel_trip(int id)
{
	return return_state();
}

ostream & operator<<(ostream & o, Client const & c)
{
	o <<  c.id << "\t" << c.name;
	return o;
}
