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
    // Read first line of file
    string firstLine = "";
    ifstream fin;
    fin.open("reservations.txt");
    getline(fin, firstLine);

    // Program initialization
    int numFlights = stoi(firstLine);
    Flight* flights = new Flight[numFlights];
    for(int i = 0; i < numFlights; i++)
        fin >> flights[i];
    
    // Done reading from file
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
    
    delete [] flights;
    return 0;

} // End of main()

