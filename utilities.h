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

bool findFlight(Flight* currFlights, int numFlights, int target);

void selectSeat(Plane* yourPlane, const char* fullName);

void writeBack(const Flight* currFlights, int totalFlights, fstream& outFile);

#endif /* UTILITIES_H */
