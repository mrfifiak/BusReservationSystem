#include "busreservationsystem.h"



BusReservationSystem::BusReservationSystem()
{
}


BusReservationSystem::~BusReservationSystem()
{
}


void BusReservationSystem::menu()
{
}

// adds a new client
void BusReservationSystem::new_client()
{
}

//removes a client
void BusReservationSystem::remove_client()
{
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

	cout << endl << "What's the id of the bus you want to delete? ";
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
