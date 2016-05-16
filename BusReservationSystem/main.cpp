//#define _BUSTEST
//#define _CLIENTTEST
#define _TRIPTEST
//#define _ASSIGNTEST

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
	change_client_data(b1);
	remove_client(b1);
#endif

#ifdef _TRIPTEST
	new_trip(b1);
	
#endif

#ifdef _ASSIGNTEST
	b1.new_bus(20);
	new_trip(b1);
	b1.assign_bus_to_trip(0, 0);
	cout << &(*b1.trips.begin());
#endif


	return 0;

}