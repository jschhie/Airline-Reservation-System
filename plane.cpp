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

int Plane::getWidth() const { return width; } // getWidth()


int Plane::getRows() const { return rows; } // getRows()

/*
Plane::Plane(const Plane& rhs)
{
    rows = rhs.rows;
    width = rhs.width;
    reserved = rhs.reserved;
    
    for(int i = 0; i < rows*width; i++)
        strcpy(passengers[i], rhs.passengers[i]);
    
    cout << "Done copying Plane object." << endl;

} // Plane Copy Constructor
*/

Plane::~Plane()
{
    for (int count = 0; count < rows*width; count++)
    {
        //cout << "Contains: " << passengers[count] << endl;
        delete [] passengers[count];
    }
    delete [] passengers;
} // ~Plane() Deconstructor

/*
int* Plane::getPlaneInfo() const
{
    int* result;
    static int dimensions[2] = {rows, width};
    result = &(dimensions[0]);
    cout << "returning dimensions\n";
    return result; // [rows, width] Format
}
*/


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

} // operator<<()

ostream& operator<< (ostream& os, const Plane& planeRef)
{
    int numRows = planeRef.getRows();
    int numCols = planeRef.getWidth();

    char letters[numCols + 1]; // Account for '\0' char
    for(int c = 0; c < numCols; c++)
        letters[c] = 'A' + c;
    letters[numCols] = '\0';

    cout << "Row Number#" << setw(8) <<  letters << endl;
    
    int offset = 0; 
    char symbols[numCols+1]; // X: Reserved, -: Available seat
    for(int i = 0; i < numRows; i++)
    {
        offset = i * numCols;
        for(int j = 0; j < numCols; j++)
        {
            if(strlen(planeRef.passengers[offset+j]))
                symbols[j] = 'X';
            else
                symbols[j] = '-';
        }
        symbols[numCols] = '\0';
        cout << i+1 << setw(18) << symbols << endl;
    }
    return os;

} // operator>>()
