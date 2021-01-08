#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>

#include "passenger.h"
#include "plane.h"
#include "utilities.h"

using namespace std;


Plane::Plane(int numRows, int numSeats, int numRsrv, int flightNumber) :
    rows(numRows), width(numSeats), reserved(numRsrv), flightNum(flightNumber)
{
    // Create & initialize 2-D array of offsets
    int capacity = numRows * numSeats;
    passengers = new int [capacity];
    // Let -1: Avaiable, unoccupied seat
    for (int i = 0; i < capacity; i++)
        passengers[i] = -1; 
} // Plane() Constructor 2.0


bool Plane::checkSeat(int seatIndex)
{ 
    int bytePos = passengers[seatIndex];
    if (seatIndex < (rows * width) && bytePos != -1)
    {
        // Read matching Passenger object
        ifstream is("../refs/passengers.dat", ios::in | ios::binary); 
        // NOTE: ios::in needed for seekg()
        if (is.is_open())
        {
            Passenger passenger;
            is.seekg(bytePos);
            is.read((char*) &passenger, sizeof(Passenger));
            cout << passenger << endl; 
            is.close();
            return true;
        }
    }
    return false;
} // checkSeat()


int Plane::getFlightNum() const { return flightNum; } // getFlightNum()


int Plane::getWidth() const { return width; } // getWidth()


int Plane::getRows() const { return rows; } // getRows()


int Plane::getReservations() const { return reserved; } // getReservations()


void Plane::addPassenger(int flightNumber, const char* fullName)
{
    int yourRow = -1, yourSeat = 0, index = -1;
    char line[80], seatLabel;
    cout << "\nX = reserved.\n";

    do // Get and validate row number
    {
        cout << "(Enter 0 to return to Main Menu.)\n";
        cout << "Please enter the row of the seat you wish to reserved >> ";
        cin.getline(line, 80);
        yourRow = checkChoice(line);

        if (yourRow > 0 && yourRow <= rows)
            break;
        else if (yourRow == 0) 
            return;
        else
        {
            cout << "There is no row #" << line << " on this flight.\n";
            cout << "Please try again.\n\n";
        }

    } while(1);
    
    do // Get and validate seat label
    {
        cout << "\n\n(Enter 0 to return to Main Menu.)\n";
        cout << "Please enter the seat letter you wish to reserve on row #" << yourRow << " >> ";
        cin.getline(line, 80);

        for(int c = 0; c < strlen(line); c++)
        {
            if (iswspace(line[c])) 
                continue;
            else if (isalpha(line[c]) && index == -1)
            {
                index = c;
                continue;
            }
            // Otherwise, invalid char seen
            index = -1;
            if (line[c] == '0')
                return; // Return to Main Menu
            break;
        } // Check each character, ignore whitespace

        // Outside for loop: Conditionally exit while loop
        if (index != -1)
            break;
        cout << "Invalid seat request. Please try again.\n";
    
    } while(1);

    seatLabel = toupper(line[index]);
    yourSeat = int(seatLabel) - int('A'); // Starts at index 0
    if (yourSeat >= width)
    {
        cout << "Requested seat letter does not exist for this flight.\n";
        return;
    }

    // Check if requested row and seat combo is free
    int offset = (yourRow-1) * width;
    if (passengers[offset + yourSeat] != -1)
        cout << "Requested Row, Seat: " << yourRow << ", " << seatLabel << " is already reserved.\n";
    else // Can add passenger to Plane
    {        
        // Write new binary Passenger object
        fstream fout;
        fout.open("../refs/passengers.dat", ios::out | ios::app | ios::binary);
        int pos = fout.tellg();
        passengers[offset + yourSeat] = pos;

        Passenger* passenger = new Passenger(flightNumber, yourRow, seatLabel, fullName);
        fout.write((char*) passenger, sizeof(Passenger));

        // Clean up & update total reservations
        delete passenger;
        fout.close();
        reserved += 1;

        // Generate unique Ticket Number for passenger
        int numReps = 43;
        cout << "\n" << string(numReps, '*');
        cout << "\nReservation Complete!\n";
        cout << "Please save your Ticket Number: " << flightNumber << '-' << (offset + yourSeat) << "\n";
        cout << string(numReps, '*') << "\n\n";
    }

    return;

} // addPassenger() 2.0


void Plane::removePassenger(int seatChoice)
{
    int bytePos = passengers[seatChoice];
    passengers[seatChoice] = -1; 

    // Writeback to file: Invalidate Passenger
    fstream fout("../refs/passengers.dat", ios::out | ios::in | ios::binary); 
    // ios::in needed for seekg() 
    if (fout.is_open())
    {
        // Invalidate and overwrite Passenger data 
        Passenger passenger; // Default constructor: flightNum = -1
        fout.seekg(bytePos);
        fout.write((char*) &passenger, sizeof(Passenger));
        fout.close();
        reserved -= 1;
        // Inform user of status
        int numReps = 43;
        cout << "\n" << string(numReps, '*');
        cout << "\nCancellation Complete!\nReturning to Main Menu.\n";
        cout << string(numReps, '*') << "\n\n";
    }
}


Plane::~Plane()
{
    if (passengers)
        delete [] passengers;
    else
        cout << "Plane::passengers DNE" << endl;
} // ~Plane() Deconstructor 2.0


istream& operator>> (istream& is, Plane& planeRef)
{

    ifstream inFile("../refs/passengers.dat", ios::binary);

    if (inFile.is_open())
    {
        // Init vals
        long offset = 0, fileSize = 0;
        int row, col, idx;

        // Read each Passenger object into buffer
        Passenger passenger;

        // Get fileSize
        inFile.seekg(0, inFile.end);
        fileSize = inFile.tellg();
        inFile.seekg(0, inFile.beg);

        // While looping, compare each passenger's flightNum
        int currFlightNum = planeRef.getFlightNum();
        while (offset < fileSize)
        {
            inFile.read((char*) &passenger, sizeof(Passenger));
            if (passenger.getFlightNum() == currFlightNum)
            {
                row = passenger.getSeatRow() - 1;
                col = passenger.getSeatLabel();
                idx = row * planeRef.getWidth() + col;
                planeRef.passengers[idx] = offset;
                planeRef.reserved += 1;
            }
            // Get current position of offset
            offset = inFile.tellg();
        }
        inFile.close();
    } else
        perror("Cannot open binary file.");
    
    return is;

} // operator>>() 2.0


ostream& operator<< (ostream& os, const Plane& planeRef)
{

    int numRows = planeRef.getRows();
    int numCols = planeRef.getWidth();

    char letters[numCols + 1]; // Account for '\0' char
    for (int c = 0; c < numCols; c++)
        letters[c] = 'A' + c;
    letters[numCols] = '\0';

    char rowHeader[] = "\nRow Number#";
    cout << rowHeader << setw(8) <<  letters << endl << endl;
    
    int offset = 0; 
    
    // Let X: Reserved, _: Available seat
    char symbols[numCols + 1];

    for (int i = 0; i < numRows; i++)
    {
        offset = i * numCols;
        for (int j = 0; j < numCols; j++)
        {
            if (planeRef.passengers[offset + j] != -1)
                symbols[j] = 'X';
            else
                symbols[j] = '_';
        }
        symbols[numCols] = '\0';
        cout << i+1 << setw(18) << symbols << endl;
    }

    return os;

} // operator<<() 2.0
