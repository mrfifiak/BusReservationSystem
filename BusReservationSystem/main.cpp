//#define _BUSTEST
//#define _CLIENTTEST
//#define _TRIPTEST
//#define _ASSIGNTEST
#define _ENROLLTEST

#include "busreservationsystem.h"
#include "bus.h"
#include "client.h"
#include "interface.h"
#include "trip.h"

using namespace std;

int main()
{

	BusReservationSystem b1;
#ifdef _BUSTEST
	new_bus(b1);
	remove_bus(b1);
	cout << "DEBUG2" << endl;
#endif

#ifdef _CLIENTTEST
	new_client(b1);
	cout << b1.clients.front();
	change_client_data(b1);
	remove_client(b1);
#endif

#ifdef _TRIPTEST
	new_trip(b1);
	cout << b1.trips.front() << endl;
	b1.trips.front().change_departure_time(6, 6, 6, 6);
	cout << b1.trips.front() << endl;
	b1.trips.front().print_clients();
#endif

#ifdef _ASSIGNTEST
	b1.new_bus(20);
	new_trip(b1);
	b1.assign_bus_to_trip(1, 1);
	cout << b1.trips.front();
	b1.check_trips();
	b1.assign_bus_to_trip(0, 0);
	b1.check_trips();
#endif

#ifdef _ENROLLTEST
	b1.new_client("Filip Stolarczuk");
	new_trip(b1);
	b1.new_bus(20);
	b1.assign_bus_to_trip(0, 0);
	b1.enroll_client_to_trip(0, 0);
	cout << b1.trips.front() << endl;
	b1.trips.front().print_clients();
	b1.cancel_trip(0, 0);
	cout << b1.trips.front() << endl;
	b1.trips.front().print_clients();

#endif


	return 0;

}