#include <iomanip>
#include <string>
#include "passenger.h"

Passenger::Passenger(): flightNum(-1 /* -1: Passenger DNE */) {} // Passenger() Empty Constructor


Passenger::Passenger(short flightNumber, short row, 
                        char label, const char* newName): 
    flightNum(flightNumber), seatRow(row), seatLabel(label) {
    strcpy(name, newName);
} // Passenger() Constructor 2.0


int Passenger::getFlightNum() const { return flightNum; } // getFlightNum()


int Passenger::getSeatRow() const { return seatRow; } // getSeatRow()


int Passenger::getSeatLabel() const { return (seatLabel - 'A'); } // getSeatLabel()


const char* Passenger::getName() const { return name; } // getName()

ostream& operator<< (ostream& os, const Passenger& passRef)
{
    cout << "\n\t\tRESERVATION DETAILS" << endl;
    cout << "------------------------------------------------" << endl;

    cout << "Passenger Name: ";
    cout << passRef.getName() << endl;
    cout << setw(16) << "Flight Number: " << passRef.getFlightNum() << endl;

    int index = passRef.getSeatLabel() + 1;
    char seatChar = static_cast<char>('A' - 1 + index);
    cout << setw(16) << "Reserved Seat: ";
    cout << passRef.getSeatRow() << seatChar;
    
    return os;
}
