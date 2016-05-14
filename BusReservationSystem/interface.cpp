#include "interface.h"

void menu()
{
}

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
	int di, depmo, depda, depho, depmi, durho, durmi;


#pragma region places
	cout << endl << "Where does the trip start? ";
	cin >> f;
	from = f;
	while (cin.peek() == ' ')
	{
		cin >> f;
		from = from+ ' ' + f;
	}

	cout << endl << "Where does the trip end? ";
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
#pragma endregion

	cout << endl << "What's the distance of the trip? ";
	cin >> di;
	while (cin.fail() || di <= 0)
	{
		cout << "Please enter valid positive distance: ";
		cin.sync();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> di;
	}

#pragma region departure
	cout << endl << "Enter departure data using numbers:" << endl;
	cout << "Month(1-12): ";
	cin >> depmo;
	while (cin.fail() || depmo <= 0 || depmo > 12)
	{
		cout << "Please enter valid month (1-12): ";
		cin.sync();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> depmo;
	}

	cout << "Day(1-31): ";
	cin >> depda;
	while (cin.fail() || depda <= 0 || depda > 31)
	{
		cout << "Please enter valid day (1-31): ";
		cin.sync();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> depda;
	}

	cout << "Hour (1-24): ";
	cin >> depho;
	while (cin.fail() || depho <= 0 || depho > 24)
	{
		cout << "Please enter valid hour (1-24): ";
		cin.sync();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> depho;
	}

	cout << "Minutes(0-59): ";
	cin >> depmi;
	while (cin.fail() || depmi <= 0 || depmi > 59)
	{
		cout << "Please enter valid month (0-59): ";
		cin.sync();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> depmi;
	}

	Time dep = Time(depmo, depda, depho, depmi);

#ifdef _DEBUG
	cout << "Departure: " << dep << endl;
#endif  
#pragma endregion

#pragma region duration
	cout << endl << "Enter duration data of the trip:" << endl;
	cout << "Hours (1-24): ";
	cin >> durho;
	while (cin.fail() || durho <= 0 || durho > 24)
	{
		cout << "Please enter valid hour (1-24): ";
		cin.sync();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> durho;
	}

	cout << "Minutes(0-59): ";
	cin >> durmi;
	while (cin.fail() || durmi <= 0 || durmi > 59)
	{
		cout << "Please enter valid month (0-59): ";
		cin.sync();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> durmi;
	}

	Time dur = Time(durho, durmi);

#ifdef _DEBUG
	cout << "Duration: " << dur << endl;
#endif   
#pragma endregion

	brs.new_trip(from, to, di, dep, dur);
}

void remove_trip(BusReservationSystem & brs)
{
	int id;

	cout << endl << "What's the ID of the trip you want to remove? ";
	cin >> id;
	while (cin.fail() || id < 0)
	{
		cout << "Please enter valid id: ";
		cin.sync();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> id;
	}

	brs.remove_trip(id);
}
