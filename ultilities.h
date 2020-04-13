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
void selectFlight(const Flight* currFlights, int numFlights);
void findFlight(const Flight* currFlights, int numFlights, int target);

#endif /* ULTILITIES_H */
