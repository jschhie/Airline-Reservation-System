#ifndef PLANE_H
#define PLANE_H

#include <fstream>

using namespace std;


class Plane
{

    int rows, width, reserved, flightNum;
    int* passengers; // Array of offsets in binary file
    //char** passengers; // Row-major order matrix of passenger names

public:

    Plane(int numRows, int numSeats, int numRsrv, int flightNumber);
    int getFlightNum() const;
    int getWidth() const;
    int getRows() const;
    int getReservations() const;
//    void addPassenger(const char* fullName);
//    void writePlaneInfo(fstream& outFile) const;
    ~Plane();
    friend istream& operator>> (istream& is, Plane& planeRef); 
//    friend ostream& operator<< (ostream& os, const Plane& planeRef);

}; // Plane Class

#endif /* PLANE_H */
