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
    cout << "Memory for Flight Number " << flightNum << " will be deallocated." << endl;

    if(plane) // Check before deallocating
        delete plane;
    else
        cout << "Error: Plane DNE." << endl;
}


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
        strcpy(flightRef.origin, line);
        is.getline(line, 20);
        strcpy(flightRef.destination, line);
        
        //cout << "origin: " << flightRef.origin << endl;
        //cout << "dest: " << flightRef.destination << endl;

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
