/* 
 * Airline Reservation System Simulation
 * Spring 2020, C++
 */

#include <iostream>
#include <fstream>
#include <string>

#include "flight.h"
#include "plane.h"
#include "ultilities.h"

using namespace std;


/* Driver Program */
int main()
{
    // Read given file
    string firstLine = "";
    ifstream fin;
    fin.open("reservations.txt");
    if(!fin)
    {
        cout << "Failed to open given file.\n";
        return 0;
    } // Terminate program early

    // Read first line of file
    getline(fin, firstLine);

    // Program initialization
    int numFlights = stoi(firstLine);
    Flight* flights = new Flight[numFlights];
    for(int i = 0; i < numFlights; i++)
        fin >> flights[i];
    
    // Done reading from given file
    fin.close();

    // Get user's input as choice
    int choice = getChoice(); 
    while(choice)
    {
        switch(choice)
        {
            case 0: 
                break;
            case 1: 
                showFlights(flights, numFlights);
                selectFlight(flights, numFlights);
                break;
            default: // Invalid input
                break;
        }
        // Get next choice
        choice = getChoice();
    } // Running loop
   
    
    // Create new file for current reservations
    
    fstream fout;
    fout.open("reservations2.txt", ios::out);
    
    if(!fout)
        cout << "Failed to create new file.\n";     
    else
    {
        cout << "Writing to new file.\n";
        // TODO 
        // Write metadata (numFlights)
        // followed by each Flight's flightNumber, etc
        // followed by each Passengers name and Seat position
        fout.close();
    }

    // Clean up and exit
    delete [] flights;    
    return 0;

} // End of main()

