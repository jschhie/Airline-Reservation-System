#include <string>
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
    if(plane) 
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

    os << flightRef.flightNum << "\t\t";
    os << flightRef.origin << "\t\t\t\t";
    os << flightRef.destination << '\n';

    return os;

} // operator<<()


istream& operator>> (istream& is, Flight& flightRef)
{

    int numRows, numSeats, numReserved;
    char line[80];

    while(is.getline(line, 80))
    {
        // Copy over Flight Info
        flightRef.flightNum = stoi(line);
        is.getline(line, 20);
        line[strlen(line)-1] = '\0'; // ADDED
        strcpy(flightRef.origin, line);
        is.getline(line, 20);
        line[strlen(line)-1] = '\0'; // ADDED
        strcpy(flightRef.destination, line);
        
        // Copy over Plane Info
        is.getline(line, 80, ' ');
        numRows = stoi(line);
        is.getline(line, 80, ' ');
        numSeats = stoi(line);
        is.getline(line, 80);
        numReserved = stoi(line);

        flightRef.plane = new Plane(numRows, numSeats, numReserved);
        is >> *flightRef.plane;
        
        break; // Stop reading rest of file contents

    } // while more line in the reservations.txt

    return is;

} // operator>>()
