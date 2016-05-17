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

// dismisses selected bus from the trip and vice versa
void BusReservationSystem::free_bus(int id)
{
	list<Bus>::iterator fbus = findID(buses, id);
	return_state rs;
	if (fbus == buses.end())
	{
		rs = FAIL_NOT_FOUND;
	}
	else
	{
		list<Trip>::iterator ftrip = findID(trips, fbus->getTripID());
		fbus->dismiss_trip();
		ftrip->dismiss_bus();
		rs = SUCCESS;
	}

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

// dismisses selected trip from the bus and vice versa
void BusReservationSystem::free_trip(int id)
{
	list<Trip>::iterator ftrip = findID(trips, id);
	return_state rs;
	if (ftrip == trips.end())
	{
		rs = FAIL_NOT_FOUND;
	}
	else
	{
		list<Bus>::iterator fbus = findID(buses, ftrip->getBusID());
		ftrip->dismiss_bus();
		fbus->dismiss_trip();
		rs = SUCCESS;
	}

	rstate("Trip", rs);
}

// changes trip's data
void BusReservationSystem::change_trip_departure_time(int id, int mo, int da, int ho, int mi)
{
	list<Trip>::iterator trip = findID(trips, id);
	return_state rs;
	if (trip == trips.end())
	{
		rs = FAIL_NOT_FOUND;
	}
	else
	{
		trip->change_departure_time(mo, da, ho, mi);
		rs = SUCCESS;
	}
	rstate("Trip", rs);
}

// changes trip's data
void BusReservationSystem::change_trip_departure_time(int id, int ho, int mi)
{
	list<Trip>::iterator trip = findID(trips, id);
	return_state rs;
	if (trip == trips.end())
	{
		rs = FAIL_NOT_FOUND;
	}
	else
	{
		trip->change_departure_time(ho, mi);
		rs = SUCCESS;
	}
	rstate("Trip", rs);
}

// changes trip's data
void BusReservationSystem::change_trip_date(int id, int mo, int da)
{
	list<Trip>::iterator trip = findID(trips, id);
	return_state rs;
	if (trip == trips.end())
	{
		rs = FAIL_NOT_FOUND;
	}
	else
	{
		trip->change_departure_date(mo, da);
		rs = SUCCESS;
	}
	rstate("Trip", rs);
}

// assigns bus to a trip and vice versa
void BusReservationSystem::assign_bus_to_trip(int bid, int tid)
{
	list<Bus>::iterator asbus = findID(buses, bid);
	list<Trip>::iterator astrip = findID(trips, tid);
	return_state rs;
	int temp;

	/* dealing with cases when there's no such bus/trip */
	if (asbus == buses.end())
	{
		rs = FAIL_NOT_FOUND;
		rstate("Bus", rs);
		if (astrip == trips.end())
		{
			rstate("Trip", rs);
		}
		return;
	}
	if (astrip == trips.end())
	{
		rs = FAIL_NOT_FOUND;
		rstate("Trip", rs);
		return;
	}

	/* dealing with old buses and trips assigned */
	temp = astrip->getBusID();
	if (temp != -1)
	{
		list<Bus>::iterator oldbus = findID(buses, temp);
		oldbus->dismiss_trip();
	}
	temp = asbus->getTripID();
	if (temp != -1)
	{
		list<Trip>::iterator oldtrip = findID(trips, temp);
		oldtrip->dismiss_bus();
	}

	Trip* newtrip = &(*astrip);
	Bus* newbus = &(*asbus);

	asbus->assign_trip(newtrip);
	astrip->assign_bus(newbus);

}

// enrolls client to a trip and vice versa
void BusReservationSystem::enroll_client_to_trip(int cid, int tid)
{
	list<Client>::iterator elclient = findID(clients, cid);
	list<Trip>::iterator eltrip = findID(trips, tid);
	return_state rs;
	int temp;

	/* dealing with cases when there's no such client/trip */
	if (elclient == clients.end())
	{
		rs = FAIL_NOT_FOUND;
		rstate("Client", rs);
		if (eltrip == trips.end())
		{
			rstate("Trip", rs);
		}
		return;
	}
	if (eltrip == trips.end())
	{
		rs = FAIL_NOT_FOUND;
		rstate("Trip", rs);
		return;
	}

	/* checks if the trip has bus assigned */
	if (eltrip->getBusID() == -1)
	{
		rs = FAIL_NO_BUS;
	}
	/* checks if the trip is full */
	else if (eltrip->isfull())
	{
		rs = FAIL_FULL;	
	}
	/* checks if the trip overlaps with another one */
	else if(elclient->does_overlap(eltrip->getDep(), eltrip->getDur()))
	{
		rs = FAIL_OVERLAP;
	}

	else
	{
		Trip* newtrip = &(*eltrip);
		Client* newclient = &(*elclient);

		elclient->book_trip(newtrip);
		eltrip->enroll_client(newclient);
		rs = SUCCESS;
	}
	rstate("Trip", rs);
}

// cancels given trip for given client
void BusReservationSystem::cancel_trip(int cid, int tid)
{
	list<Client>::iterator canclient = findID(clients, cid);
	list<Trip>::iterator cantrip = findID(trips, tid);
	return_state rs;

	/* checks if such client and trip exist */
	if (canclient == clients.end())
	{
		rs = FAIL_NOT_FOUND;
		rstate("Client", rs);
		if (cantrip == trips.end())
		{
			rstate("Trip", rs);
		}
		return;
	}
	else if (cantrip == trips.end())
	{
		rs = FAIL_NOT_FOUND;
		rstate("Trip", rs);
		return;
	}
	/* checks if the client is enrolled to the trip */
	else if ()
	{
		rs = FAIL_NOT_BOOKED
	}
	else
	{
		Trip* deltrip = &(*cantrip);
		Client* delclient = &(*canclient);

		canclient->cancel_trip(deltrip);
		cantrip->delete_client(delclient);
		rs = SUCCESS;
	}

}


// prints all trips with bus ID and number of clients
void BusReservationSystem::print_trips()
{
}

// prints trip's basic data with list of clients
void BusReservationSystem::print_trip_clients(int id)
{
}

// prints all trips' basic data
void BusReservationSystem::print_timetable()
{
}
