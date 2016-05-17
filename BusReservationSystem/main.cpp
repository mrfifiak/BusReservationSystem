

#include "busreservationsystem.h"
#include "bus.h"
#include "client.h"
#include "interface.h"
#include "trip.h"

using namespace std;

int main()
{
	BusReservationSystem brs;

	brs.new_client("Filip Stolarczuk");
	brs.new_client("Joanna Kamelska");
	brs.new_client("Mateusz Roszkowski");
	brs.new_client("Michal Bator");
	brs.new_trip("Warsaw", "Cracow", 300, 5, 20, 16, 30, 4, 20);
	brs.new_trip("Warsaw", "Cracow", 300, 5, 21, 14, 30, 4, 20);
	brs.new_trip("Warsaw", "Cracow", 300, 5, 22, 12, 30, 4, 20);
	brs.new_trip("Poznan", "Wroclaw", 170, 5, 20, 15, 00, 3, 10);
	brs.new_trip("Poznan", "Wroclaw", 170, 5, 21, 18, 30, 3, 10);
	brs.new_trip("Poznan", "Wroclaw", 170, 5, 21, 20, 15, 3, 10);
	brs.new_bus(2);
	brs.new_bus(5);
	brs.new_bus(2);
	brs.new_bus(2);
	brs.check_trips();
	brs.assign_bus_to_trip(0, 0);
	brs.enroll_client_to_trip(0, 0);
	cout << brs.trips.front() << endl;
	brs.trips.front().print_clients();
	brs.cancel_trip(0, 0);
	cout << brs.trips.front() << endl;
	brs.trips.front().print_clients();



	return 0;
}
