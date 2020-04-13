#include <iostream>
#include <fstream>
#include <string>
#include "plane.h"

using namespace std;


Plane::Plane(int numRows, int numSeats, int numRsrv) : 
    rows(numRows), width(numSeats), reserved(numRsrv)
{
    // Create 2-D array of strings
    passengers = new char * [numRows*numSeats];
    int offset = 0;
    for(int i = 0; i < numRows; i++)
    {
        offset = i * width;
        for(int j = 0; j < width; j++)
            passengers[offset+j] = new char[80];
    }
} // Plane() Constructor


Plane::~Plane()
{
    for (int count = 0; count < rows*width; count++)
    {
        //cout << "Contains: " << passengers[count] << endl;
        delete [] passengers[count];
    }
    delete [] passengers;
} // ~Plane() Deconstructor


istream& operator>> (istream& is, Plane& planeRef)
{

    char line[80];
    char fullName[80];
    char curr_row[20]; // Assumes max row is 20
    
    char curr_seat;
    int length, row_num, col_num;
    
    
    for(int i = 0; i < planeRef.reserved; i++)
    {
        // Copy Seat Info
        is.getline(line, 80, ' ');
        length = strlen(line);
        strncpy(curr_row, line, length-1); // Copy all except last character (which is the seat letter)
        curr_row[length-1] = '\0';
        row_num = stoi(curr_row);
        curr_seat = char(line[length-1]); // Single letter
        col_num = int(curr_seat) - int('A');

        // Get and store full Name of Passengers
        is.getline(line, 80);
        strcpy(fullName, line);
        int offset = (row_num - 1) * planeRef.width;
        strcpy(planeRef.passengers[offset + col_num], fullName);
    }
    
    return is;

}
