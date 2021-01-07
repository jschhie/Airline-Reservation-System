#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>

#include "flight.h"

using namespace std;

Flight::Flight() : flightNum(-1)
{
    strcpy(origin, "None");
    strcpy(destination, "None");
} // Flight() Constructor


Flight::~Flight()
{
    if (plane) 
        delete plane;
    else
        cout << "~Flight() Error: Plane DNE." << endl;
} // ~Flight() Deconstructor


int Flight::getFlightNum() const { return flightNum; } // getFlightNum()


string Flight::getOrigin() const { return origin; } // getOrigin()


string Flight::getDestination() const { return destination; } // getDestination()


Plane* Flight::getPlane() const { return plane; } // getPlane()


ostream& operator<< (ostream& os, const Flight& flightRef) 
{

    // Indirect access via getters
    os << flightRef.getFlightNum() << setw(20); 
    os << flightRef.getOrigin() << setw(20);
    os << flightRef.getDestination() << '\n';

    return os;

} // operator<<()


istream& operator>> (istream& is, Flight& flightRef)
{
    int numRows, numSeats;
    char line[80];

    // Parse Flight info
    is.getline(line, 80, ',');
    flightRef.flightNum = stoi(line);

    // NOTE: Flight::origin & destination initialized to 20 chars
    is.getline(line, 20, ',');
    strcpy(flightRef.origin, line);
    is.getline(line, 20, ',');
    strcpy(flightRef.destination, line);

    // Get Plane info
    is.getline(line, 80, ',');
    numRows = stoi(line);
    is.getline(line, 80); // until EOF
    numSeats = stoi(line);
    
    // Create Plane and update Plane::passengers
    flightRef.plane = new Plane(numRows, numSeats, 0, flightRef.getFlightNum());
    is >> *flightRef.plane;

    return is;

} // operator>>() 2.0
