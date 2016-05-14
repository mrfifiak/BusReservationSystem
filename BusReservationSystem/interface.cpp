#include "interface.h"

void new_client(BusReservationSystem& brs)
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

	brs.new_client(name);
}

void remove_client(BusReservationSystem & brs)
{
	int id;

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

	brs.remove_client(id);
}

void change_client_data(BusReservationSystem & brs)
{
	int id;

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

	brs.change_client_data(id);
}

void new_bus(BusReservationSystem & brs)
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

	brs.new_bus(cap);
}

void remove_bus(BusReservationSystem & brs)
{
	int id;

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

	brs.remove_bus(id);
}

void new_trip(BusReservationSystem & brs)
{
	string from, f, to, t;

	cout << endl << "Where does the bus start from? ";
	cin >> f;
	from = f;
	while (cin.peek() == ' ')
	{
		cin >> f;
		from = from+ ' ' + f;
	}

	cout << endl << "Where does the bus go to? ";
	cin >> t;
	to = t;
	while (cin.peek() == ' ')
	{
		cin >> t;
		to = to + ' ' + t;
	}

#ifdef _DEBUG
	cout << "From: " << from << " to " << to << endl;
#endif



	//brs.new_trip(...);
}
