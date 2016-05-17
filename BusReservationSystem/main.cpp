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
	BusReservationSystem brs;


#ifdef _ENROLLTEST
	brs.new_client("Filip Stolarczuk");
	new_trip(brs);
	brs.new_bus(20);
	brs.assign_bus_to_trip(0, 0);
	brs.enroll_client_to_trip(0, 0);
	cout << brs.trips.front() << endl;
	brs.trips.front().print_clients();
	brs.cancel_trip(0, 0);
	cout << brs.trips.front() << endl;
	brs.trips.front().print_clients();

#endif


	return 0;
}
