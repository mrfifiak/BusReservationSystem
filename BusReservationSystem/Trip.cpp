#include "trip.h"


int Trip::id_counter = 0;	// initializing id counter

// constructor with all attributes
Trip::Trip(string f, string t, unsigned int di, int depmo, int depda, int depho, int depmi, int durho, int durmi)
{
	from = f;
	to = t;
	distance = di;
	departure = Time(depmo, depda, depho, depmi);
	duration = Time(durho, durmi);
	assigned_bus = NULL;
	id = id_counter++;
#ifdef _DEBUG
	cout << "Constructor Trip " << id << ' ' << f << " -> " << t << ' ' << distance << "km " << departure << ' ' << duration << endl;
#endif
}

Trip::Trip(string f, string t, unsigned int di, Time dep, Time dur)
{
	from = f;
	to = t;
	distance = di;
	departure = dep;
	duration = dur;
	assigned_bus = NULL;
	id = id_counter++;
#ifdef _DEBUG
	cout << "Constructor Trip " << id << ' ' << f << " -> " << t << ' ' << distance << "km " << departure << ' ' << duration << endl;
#endif
}

// destructor
Trip::~Trip()
{
#ifdef _DEBUG
	cout << "Destructor Trip " << id << endl;
#endif
}

// generic getter
Time Trip::getDep()
{
	return departure;
}

// generic getter
Time Trip::getDur()
{
	return duration;
}

// returns true if the number of enrolled passengers >= bus capacity
bool Trip::isfull()
{
	if (enrolled_clients.size() >= assigned_bus->getCapacity())
	{
		return true;
	}
	else
	{
		return false;
	}
}

// returns true if the trip has a bus assigned
bool Trip::hasbus()
{
	if (assigned_bus != NULL)
	{
		return true;
	}
	return false;
}

//generic getter
int Trip::getID()
{
	return id;
}

// returns assigned bus' ID, -1 if no bus assigned
int Trip::getBusID()
{
	if (assigned_bus == NULL)
	{
		return -1;
	}
	else
	{
		return assigned_bus->getID();
	}
}

// assign bus with given id
void Trip::assign_bus(Bus *newbus)
{
	assigned_bus = newbus;
}

// dismiss the assigned bus
void Trip::dismiss_bus()
{
	assigned_bus = NULL;
}

// changes all the attributes of the departure time
void Trip::change_departure_time(int mo, int da, int ho, int mi)
{
	departure.months = mo;
	departure.days = da;
	departure.hours = ho;
	departure.minutes = mi;
}

// changes the time (hh:mm) of the departure
void Trip::change_departure_time(int ho, int mi)
{
	departure.hours = ho;
	departure.minutes = mi;
}

// changes the date of the departure
void Trip::change_departure_date(int mo, int da)
{
	departure.months = mo;
	departure.days = da;
}

// prints enrolled clients
void Trip::print_clients()
{
	if (enrolled_clients.empty())
	{
		cout << "No clients enrolled for this trip." << endl;
	}
	else
	{
		list<Client*>::iterator it = enrolled_clients.begin();
		cout << "ID\tName" << endl;
		while (it != enrolled_clients.end())
		{
			cout << **it << endl;
			++it;
		}
	}
}

// operator <<
ostream & operator<<(ostream & o, Trip const & t)
{
	if (t.assigned_bus)
	{
		o << t.id << "\t" << t.from << "\t" << t.to << "\t" << t.distance << "km\t" << t.departure << "\t" << t.duration << "\t" << t.assigned_bus->getID() << "\t" << t.enrolled_clients.size();
	}
	else
	{
		o << t.id << "\t" << t.from << "\t" << t.to << "\t" << t.distance << "km\t" << t.departure << "\t" << t.duration << "\tNO BUS\t" << t.enrolled_clients.size();
	}
	return o;
}
