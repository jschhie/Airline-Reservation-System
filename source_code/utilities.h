#ifndef UTILITIES_H
#define UTILITIES_H

#include <cctype>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

#include "flight.h"

using namespace std;

/* Foward Declarations */
void printMenu();

int checkChoice(const char* yourChoice);

int getChoice();

void showFlights(const Flight* currFlights, int numFlights);

void selectFlight(Flight* currFlights, int numFlights);

bool findFlight(Flight* currFlights, int numFlights, int target, int seatChoice=-1, bool readonly=false);

void findPassengerInfo(Flight* currFlights, int numFlights);

void selectSeat(int yourFlightNum, Plane* yourPlane, const char* fullName);

#endif /* UTILITIES_H */
