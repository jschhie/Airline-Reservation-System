#include <string>
#include "passenger.h"

Passenger::Passenger(): flightNum(-1 /* -1: Passenger DNE */) {} // Passenger() Empty Constructor

Passenger::Passenger(short flightNumber, short row, char label, char* newName): 
flightNum(flightNumber), seatRow(row), seatLabel(label) {
    strcpy(name, newName);
} // Passenger(…) Constructor 2.0

int Passenger::getFlightNum() const { return flightNum; } // getFlightNum()

int Passenger::getSeatRow() const { return seatRow; } // getSeatRow()

int Passenger::getSeatLabel() const { return (seatLabel - 'A'); } // getSeatLabel()
