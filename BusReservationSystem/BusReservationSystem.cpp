#include "busreservationsystem.h"


// default constructor
BusReservationSystem::BusReservationSystem()
{
	cout << "Bus Reservation System launched." << endl;
}

// destructor
BusReservationSystem::~BusReservationSystem()
{
	cout << "Bus Reservation System switching off..." << endl;
}


// adds a new client
void BusReservationSystem::new_client(string name)
{
	Client* newclient = new Client(name);
	clients.push_back(*newclient);
}

//removes a client
void BusReservationSystem::remove_client(int id)
{
	
	return_state rs;
	list<Client>::iterator remclient;

	remclient = findID(clients, id);
	if (remclient != clients.end())
	{
		rs = SUCCESS;
		clients.erase(remclient);
	}
	else rs = FAIL_NOT_FOUND;

	rstate("Client", rs);
}

// changes client's data
void BusReservationSystem::change_client_data(int id)
{
	string name, n;
	list<Client>::iterator chaclient;
	return_state rs;

	chaclient = findID(clients, id);
	if (chaclient != clients.end())
	{
		cout << "Client's new name: ";
		cin >> n;
		name = n;
		while (cin.peek() == ' ')
		{
			cin >> n;
			name = name + ' ' + n;
		}
		(*chaclient).change_data(name);
		rs = SUCCESS;
	}
	else rs = FAIL_NOT_FOUND;

	rstate("Client", rs);

}

// creates a bus
void BusReservationSystem::new_bus(int cap)
{
	Bus* newbus = new Bus(cap);
	buses.push_back(*newbus);
}

// removes a bus
void BusReservationSystem::remove_bus(int id)
{
	return_state rs;
	list<Bus>::iterator rembus;


	rembus = findID(buses, id);
	if (rembus != buses.end())
	{
		rs = SUCCESS;
		buses.erase(rembus);
	}
	else rs = FAIL_NOT_FOUND;

	rstate("Bus", rs);
}

// creates a new trip
void BusReservationSystem::new_trip(string from, string to, unsigned int di, Time dep, Time dur)
{
	Trip* newtrip = new Trip(from, to, di, dep, dur);
	trips.push_back(*newtrip);
}

// removes a trip
void BusReservationSystem::remove_trip(int id)
{
	return_state rs;
	list<Trip>::iterator remtrip;


	remtrip = findID(trips, id);
	if (remtrip != trips.end())
	{
		rs = SUCCESS;
		trips.erase(remtrip);
	}
	else rs = FAIL_NOT_FOUND;

	rstate("Trip", rs);
}

// checks if all the trips have their buses
void BusReservationSystem::check_trips()
{
	list<int> ids;
	list<Trip>::iterator ti;
	list<int>::iterator ii;

	for (ti = trips.begin(); ti != trips.end(); ++ti)
	{
		if (ti->hasbus() == false)
		{
			ids.push_back(ti->getID());
		}
	}

	if (ids.empty())
	{
		cout << endl << "All trips have buses assigned!" << endl;
	}
	else
	{
		cout << endl << "Trips with following id's have no bus assigned: " << endl;
		for (ii = ids.begin(); ii != ids.end(); ++ii)
		{
			cout << *ii << endl;
		}
	}
}

// choose a bus, then choose the trip
void BusReservationSystem::assign_bus_to_trip()
{
}

// choose the bus
void BusReservationSystem::dismiss_a_bus()
{
}

// choose a trip, then choose the bus
void BusReservationSystem::assign_trip_to_bus()
{
}

// choose the trip
void BusReservationSystem::dismiss_a_trip()
{
}

// changes trip's data
void BusReservationSystem::change_trip_data()
{
}

// prints all trips with buses and clients
void BusReservationSystem::print_trips()
{
}

// prints all trips' basic data
void BusReservationSystem::print_timetable()
{
}


