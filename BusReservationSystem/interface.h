#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <limits>	// for safe data input
#include <string>

#include "busreservationsystem.h"

void menu(); // main menu

void new_client(BusReservationSystem& brs);
void remove_client(BusReservationSystem& brs);
void change_client_data(BusReservationSystem& brs);

void new_bus(BusReservationSystem& brs);
void remove_bus(BusReservationSystem& brs);

void new_trip(BusReservationSystem& brs);
void remove_trip(BusReservationSystem& brs);

#endif
