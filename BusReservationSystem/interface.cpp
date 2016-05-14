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
