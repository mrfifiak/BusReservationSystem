

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
	brs.new_bus(2);
	brs.new_bus(2);
	brs.new_bus(2);
	brs.new_bus(4);
	brs.print_trips();
	cout << endl << "TEST1" << endl;
	brs.check_trips();
	brs.check_buses();
	brs.assign_bus_to_trip(0, 0);
	brs.assign_bus_to_trip(1, 3);
	brs.assign_bus_to_trip(3, 3);
	brs.assign_bus_to_trip(4, 4);
	brs.assign_bus_to_trip(4, 1);
	brs.assign_bus_to_trip(2, 15);
	brs.assign_bus_to_trip(15, 2);
	brs.assign_bus_to_trip(15, 15);
	brs.print_trips();
	cout << endl << "TEST2" << endl;
	brs.check_trips();
	brs.check_buses();
	brs.enroll_client_to_trip(0, 0);
	brs.enroll_client_to_trip(0, 3);
	brs.enroll_client_to_trip(1, 0);
	brs.enroll_client_to_trip(2, 0);
	cout << endl << "penis"<<endl;
	brs.enroll_client_to_trip(0, 1);
	brs.enroll_client_to_trip(1, 1);
	brs.enroll_client_to_trip(2, 1);
	brs.enroll_client_to_trip(3, 1);
	brs.enroll_client_to_trip(15, 0);
	brs.enroll_client_to_trip(0, 15);
	brs.print_trips();
	cout << endl << "TEST3" << endl;
	brs.print_timetable();
	brs.print_trip_clients(0);
	brs.print_trip_clients(2);
	brs.print_trip_clients(1);



	return 0;
}
