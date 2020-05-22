#ifndef PASSENGER_H
#define PASSENGER_H

class Passenger 
{

    short flightNum, seatRow;
    char seatLabel, name[30];

public:
    
    Passenger();
    int getFlightNum() const;
    int getSeatRow() const;
    int getSeatLabel() const;
    // char* getName() const;

}; // Passenger Class

#endif /* PASSENGER_H */
