//#define _BUSTEST
#define _CLIENTTEST

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
	b1.new_bus();
	cout << "DEBUG1" << endl;
	b1.new_bus();
	b1.new_bus();
	b1.remove_bus();
	cout << "DEBUG2" << endl;
#endif

#ifdef _CLIENTTEST
	new_client(b1);
	change_client_data(b1);
	remove_client(b1);
#endif

	Trip t = Trip("Warsaw", "Cracow", 400, 12, 04, 12, 00, 4, 0);



	return 0;

}