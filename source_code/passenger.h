#ifndef PASSENGER_H
#define PASSENGER_H

#include <iostream>

using namespace std;

class Passenger 
{

    short flightNum, seatRow;
    char seatLabel, name[30];

public:
    
    Passenger(); // Default
    Passenger(short flightNumber, short row, char label, const char* newName); // With args
    int getFlightNum() const;
    int getSeatRow() const;
    int getSeatLabel() const;
    const char* getName() const;
    friend ostream& operator<< (ostream& os, const Passenger& passRef);
}; // Passenger Class

#endif /* PASSENGER_H */
