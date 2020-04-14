#ifndef ULTILITIES_H
#define ULTILITIES_H

#include <cctype>
#include <cstdlib>
#include <iostream>
#include <string>

#include "flight.h"

using namespace std;

/* Foward Declarations */
void printMenu();
int checkChoice(const char* yourChoice);
int getChoice();
void showFlights(const Flight* currFlights, int numFlights);
void selectFlight(Flight* currFlights, int numFlights);
bool findFlight(Flight* currFlights, int numFlights, int target);
void selectSeat(Plane* yourPlane, const char* fullName);

#endif /* ULTILITIES_H */
