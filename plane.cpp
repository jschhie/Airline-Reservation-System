#include <cctype>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "plane.h"

using namespace std;


Plane::Plane(int numRows, int numSeats, int numRsrv) : 
    rows(numRows), width(numSeats), reserved(numRsrv)
{
    // Create 2-D array of strings: Row-major order
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


int Plane::getReservations() const { return reserved; } // getReservations()


void Plane::addPassenger(const char* fullName)
{
    int yourRow = 0, yourSeat = 0;
    char line[80], seatLabel;

    cout << "\nX = reserved.\n";
    cout << "Please enter the row of the seat you wish to reserved >> ";
    cin.getline(line, 80);
    
    // Check requested row
    for(int c = 0; c < strlen(line); c++)
        if(!isdigit(line[c])) return;

    yourRow = stoi(line);
    if(yourRow <= 0 || yourRow > rows)
    {
        cout << "There is no row #" << yourRow << " on this flight.\n";
        cout << "TODO: Please try again.\n";
        return;
    }
    
    // Get and validate seat label
    cout << "Please enter the seat letter you wish to reserve on row #" << yourRow << " >> ";
    cin.getline(line, 80);

    int seatChar = 0, alphaSeen = 0;
    for(int c = 0; c < strlen(line); c++)
    {
        if(isalpha(line[c]))
        {
            if(alphaSeen == 0)
            {
                seatChar = c;
                alphaSeen += 1;
            }
            else // Too many letters provided
                return;
        }
        else if(!iswspace(line[c])) // Invalid character
            return;
    }

    seatLabel = toupper(line[seatChar]);
    yourSeat = int(seatLabel) - int('A'); // Starts at index 0
    if (yourSeat >= width)
    {
        cout << "addPassenger() Error: Requested seat letter DNE on this flight.\n";
        return;
    }

    // Check if requested row and seat combo is free
    int offset = (yourRow-1) * width;
    if(strlen(passengers[offset+yourSeat]))
        cout << "Requested Row, Seat: " << yourRow << ", " << seatLabel << " is already reserved.\n";
    else // Can add passenger to Plane
    {
        strcpy(passengers[offset+yourSeat], fullName);
        reserved++;
    }

} // addPassenger()


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

        // Copy all except last character (which is the seat letter)
        strncpy(curr_row, line, length-1);
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
