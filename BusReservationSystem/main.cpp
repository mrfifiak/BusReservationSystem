#include "busreservationsystem.h"
#include "bus.h"
#include "client.h"
#include "interface.h"
#include "trip.h"

using namespace std;

int main()
{
	BusReservationSystem brs;

	brs.print_timetable();
	brs.print_trips();
	brs.print_trip_clients(0);
	cout << endl;
	cout << endl << "TEST0" << endl;
	cout << endl;
	brs.new_client("Filip Stolarczuk");
	brs.new_client("Joanna Kamelska");
	brs.new_client("Mateusz Roszkowski");
	brs.new_client("Michal Baktor");
	brs.change_client_data(3, "Michal Bator");
	brs.change_client_data(15, "Karol Karolak");
	brs.new_trip("Warsaw", "Cracow", 300, 5, 20, 16, 30, 4, 20);
	brs.new_trip("Warsaw", "Cracow", 300, 5, 21, 14, 30, 4, 20);
	brs.new_trip("Warsaw", "Cracow", 300, 5, 22, 12, 30, 4, 20);
	brs.new_trip("Poznan", "Wroclaw", 170, 5, 20, 15, 00, 3, 10);
	brs.new_trip("Poznan", "Wroclaw", 170, 5, 21, 18, 30, 3, 10);
	brs.new_trip("Poznan", "Wroclaw", 170, 5, 21, 8, 00, 3, 10);
	brs.new_bus(2);
	brs.new_bus(2);
	brs.new_bus(2);
	brs.new_bus(2);
	brs.new_bus(4);
	brs.print_trips(); 
	cout << endl;
	cout << endl << "TEST1" << endl;
	cout << endl;
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
	brs.check_trips();
	brs.check_buses();
	cout << endl;
	cout << endl << "TEST2" << endl;
	cout << endl;
	brs.enroll_client_to_trip(0, 0);
	brs.enroll_client_to_trip(0, 3);
	brs.enroll_client_to_trip(1, 0);
	brs.enroll_client_to_trip(2, 0);
	brs.enroll_client_to_trip(0, 1);
	brs.enroll_client_to_trip(1, 1);
	brs.enroll_client_to_trip(2, 1);
	brs.enroll_client_to_trip(3, 1);
	brs.enroll_client_to_trip(15, 0);
	brs.enroll_client_to_trip(0, 15);
	brs.print_trips();
	cout << endl;
	cout << endl << "TEST3" << endl;
	cout << endl;
	brs.print_timetable();
	brs.print_trip_clients(0);
	brs.print_trip_clients(2);
	brs.print_trip_clients(1);
	cout << endl;
	cout << endl << "TEST4" << endl;
	cout << endl;
	brs.cancel_trip(2, 1);
	brs.remove_client(1);
	brs.print_trip_clients(0);
	brs.print_trip_clients(1);
	brs.remove_trip(1);
	brs.print_trip_clients(1);
	brs.enroll_client_to_trip(2, 0);
	brs.remove_bus(0);
	brs.print_trip_clients(0);
	cout << endl;
	cout << endl << "TEST5" << endl;
	cout << endl;
	brs.assign_bus_to_trip(2, 0);
	brs.print_trips();
	brs.free_bus(3);
	brs.free_trip(0);
	brs.change_trip_date(0, 5, 23);
	brs.change_trip_departure_time(2, 5, 23, 17, 30);
	brs.change_trip_departure_time(5, 9, 30);
	brs.print_trips();


	return 0;
}
