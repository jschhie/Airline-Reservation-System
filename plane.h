#ifndef PLANE_H
#define PLANE_H

#include <fstream>

using namespace std;

/*
typedef struct
{
    int rows;
    int width;
    int reserved; // Total reservations for Plane
    char ***passengers; // 2-dimensional array
} Plane;
*/

class Plane
{

    int rows, width, reserved;
    char** passengers; // Row-major order matrix of passenger names

public:

    Plane(int numRows, int numSeats, int numRsrv);
    ~Plane();
    int* getPlaneInfo() const;
    friend istream& operator>> (istream& is, Plane& planeRef); 

}; // Plane Class

#endif /* PLANE_H */
