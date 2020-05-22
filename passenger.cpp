#include "passenger.h"

Passenger::Passenger(): flightNum(-1 /* -1: Passenger DNE */) {} // Passenger() Constructor

int Passenger::getFlightNum() const { return flightNum; } // getFlightNum()

int Passenger::getSeatRow() const { return seatRow; } // getSeatRow()

int Passenger::getSeatLabel() const { return (seatLabel - 'A'); } // getSeatLabel()

