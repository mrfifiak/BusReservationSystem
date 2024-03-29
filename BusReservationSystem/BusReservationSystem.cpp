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
		remclient->cancel_all_trips();
		clients.erase(remclient);
		rs = SUCCESS;
	}
	else rs = FAIL_NOT_FOUND;

	rstate("Client", rs);
}

// changes client's data
void BusReservationSystem::change_client_data(int id, string name)
{
	list<Client>::iterator chaclient;
	return_state rs;

	chaclient = findID(clients, id);
	if (chaclient != clients.end())
	{
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
		int tid = rembus->getTripID();
		if (tid != -1)
		{
			list<Trip>::iterator ti;
			ti = findID(trips, tid);
			ti->dismiss_bus();
		}
		buses.erase(rembus);
		rs = SUCCESS;
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

// checks if all the buses have a trip assigned
void BusReservationSystem::check_buses()
{
	list<int> ids;
	list<Bus>::iterator bi;
	list<int>::iterator ii;

	for (bi = buses.begin(); bi != buses.end(); ++bi)
	{
		if (bi->getTripID() == -1)
		{
			ids.push_back(bi->getID());
		}
	}

	if (ids.empty())
	{
		cout << endl << "All buses have a trip assigned!" << endl;
	}
	else
	{
		cout << endl << "Buses with following id's have no trip assigned: " << endl;
		for (ii = ids.begin(); ii != ids.end(); ++ii)
		{
			cout << *ii << endl;
		}
	}
}

// creates a new trip
void BusReservationSystem::new_trip(string from, string to, unsigned int di, Time dep, Time dur)
{
	Trip* newtrip = new Trip(from, to, di, dep, dur);
	trips.push_back(*newtrip);
}

// creates a new trip
void BusReservationSystem::new_trip(string from, string to, unsigned int di, int depmo, int depda, int depho, int depmi, int durho, int durmi)
{
	Trip* newtrip = new Trip(from, to, di, Time(depmo, depda, depho, depmi), Time(durho, durmi));
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
		remtrip->delete_all_clients();
		trips.erase(remtrip);
		rs = SUCCESS;
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

	rs = SUCCESS;
	rstate("", rs);
}

// enrolls client to a trip and vice versa
void BusReservationSystem::enroll_client_to_trip(int cid, int tid)
{
	list<Client>::iterator elclient = findID(clients, cid);
	list<Trip>::iterator eltrip = findID(trips, tid);
	return_state rs;

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
	else if (elclient->does_overlap(eltrip->getDep(), eltrip->getDur()))
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
	else if (!canclient->is_enrolled(cantrip->getID()))
	{
		rs = FAIL_NOT_BOOKED;
	}
	else
	{
		Trip* deltrip = &(*cantrip);
		Client* delclient = &(*canclient);

		canclient->cancel_trip(deltrip);
		cantrip->delete_client(delclient);
		rs = SUCCESS;
	}

	rstate("Trip", rs);
}

// prints all trips with bus ID and number of clients
void BusReservationSystem::print_trips()
{
	if (trips.empty())
	{
		cout << "There are no trips to be printed." << endl;
		return;
	}

	list<Trip>::iterator it;
	cout << "Trip ID\tFrom\tTo\tDist.\tDeparture\tDur.\tBus ID\tPassengers" << endl;
	for (it = trips.begin(); it != trips.end(); ++it)
	{
		cout << *it << endl;
	}
}

// prints trip's basic data with list of clients
void BusReservationSystem::print_trip_clients(int id)
{
	list<Trip>::iterator it;
	it = findID(trips, id);
	if (it == trips.end())
	{
		rstate("Trip", FAIL_NOT_FOUND);
	}
	else
	{
		cout << "Trip ID\tFrom\tTo\tDist.\tDeparture\tDur.\tBus ID\tPassengers" << endl;
		cout << *it << endl;
		(*it).print_clients();
	}
}

// prints all trips' basic data
void BusReservationSystem::print_timetable()
{
	if (trips.empty())
	{
		cout << "There are no trips to be printed." << endl;
		return;
	}

	list<Trip>::iterator it;
	trips.sort();

	cout << "Departure\tFrom\tTo\tTrip ID" << endl;
	for (it = trips.begin(); it != trips.end(); ++it)
	{
		cout << (*it).getDep() << "\t" << (*it).getFrom() << "\t" << (*it).GetTo() << "\t" << (*it).getID() << endl;
	}
}
