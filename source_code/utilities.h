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

// NOTE: findFlight() has two optional params: seatChoice, readonly 
Plane* findFlight(Flight* currFlights, int numFlights,
                int target, int seatChoice=-1, bool readonly=false);

// NOTE: findPassengerInfo() is called when cancelling a reservation (cancelMe=true, in that case)
bool findPassengerInfo(Flight* currFlights, int numFlights, bool cancelMe=false);

void selectSeat(int yourFlightNum, Plane* yourPlane); //, const char* fullName);

// NOTE: confirmCancellation() returns true: Cancel, false: Quit Cancellation
bool confirmCancellation(); 

#endif /* UTILITIES_H */
