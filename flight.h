#ifndef FLIGHT_H
#define FLIGHT_H

#include <fstream>
#include "plane.h"

using namespace std;

/*
typedef struct
{
    int flightNum;
    char origin[20];
    char destination[20];
    Plane *plane;
} Flight;
*/

class Flight
{

    int flightNum;
    char origin[20];
    char destination[20];
    Plane* plane;

public:
    Flight();
    ~Flight();
    int getFlightNum() const;
    int* getPlaneCapacity() const;
    friend ostream& operator<< (ostream& os, const Flight& flightRef);
    friend istream& operator>> (istream& is, Flight& flightRef);

}; // Flight Class

#endif /* FLIGHT_H */
