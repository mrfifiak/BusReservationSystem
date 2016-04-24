#include "busreservationsystem.h"
#include "bus.h"
#include "client.h"
#include "trip.h"

using namespace std;

int main()
{

	BusReservationSystem b1;
	b1.new_bus();
	cout << "DEBUG1" << endl;
	b1.remove_bus();
	cout << "DEBUG2" << endl;
	


/*
#ifdef _WIN32
	system("Pause");
#endif
*/

	return 0;

}