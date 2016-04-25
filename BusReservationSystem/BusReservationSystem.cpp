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


void BusReservationSystem::menu()
{
}

// adds a new client
void BusReservationSystem::new_client()
{
	string name, n;
	cout << endl << "What's new client's name? ";
	cin >> n;
	name = n;
	while (cin.peek() == ' ')
	{
		cin >> n;
		name = name + ' ' + n;
	}
	Client* newclient = new Client(name);
	clients.push_back(*newclient);
}

//removes a client
void BusReservationSystem::remove_client()
{
	int id;
	return_state rs;
	list<Client>::iterator remclient;


	cout << endl << "What's the ID of the client you want to remove? ";
	cin >> id;
	while (cin.fail() || id < 0)
	{
		cout << "Please enter valid id: ";
		cin.sync();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> id;
	}

	remclient = findID(clients, id);
	if (remclient != clients.end())
	{
		rs = SUCCESS;
		clients.erase(remclient);
	}
	else rs = FAIL_NOT_FOUND;

	rstate("Client", rs);
}

// creates a bus
void BusReservationSystem::new_bus()
{
	int cap;
	cout << endl << "What's the capacity of new bus? ";
	cin >> cap;
	while (cin.fail() || cap <= 0)
	{
		cout << "Please enter valid positive capacity: ";
		cin.sync();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> cap;
	}
	Bus* newbus = new Bus(cap);
	buses.push_back(*newbus);
}

// removes a bus
void BusReservationSystem::remove_bus()
{
	int id;
	return_state rs;
	list<Bus>::iterator rembus;

	cout << endl << "What's the ID of the bus you want to remove? ";
	cin >> id;
	while (cin.fail() || id < 0)
	{
		cout << "Please enter valid id: ";
		cin.sync();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> id;
	}

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
void BusReservationSystem::new_trip()
{
}

// removes a trip
void BusReservationSystem::remove_trip()
{
}

// changes client's data
void BusReservationSystem::change_client_data()
{
	int id;
	string name, n;
	list<Client>::iterator chaclient;
	return_state rs;

	cout << endl << "What's the ID of the client whose data you want to change? ";
	cin >> id;
	while (cin.fail() || id < 0)
	{
		cout << "Please enter valid id: ";
		cin.sync();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> id;
	}

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

// choose a bus, then choose the trip
void BusReservationSystem::assign_bus_to_trip()
{
}

// choose a bus, then choose the trip
void BusReservationSystem::dismiss_bus_from_trip()
{
}

// choose a trip, then choose the bus
void BusReservationSystem::assign_trip_to_bus()
{
}

// choose a trip, then choose the bus
void BusReservationSystem::dismiss_trip_from_bus()
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

// checks if all the trips have their buses
void BusReservationSystem::check_trips()
{
}
