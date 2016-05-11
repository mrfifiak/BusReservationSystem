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
