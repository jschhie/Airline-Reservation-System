#ifndef PASSENGER_H
#define PASSENGER_H

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

}; // Passenger Class

#endif /* PASSENGER_H */
