/* 
 * Airline Reservation System Simulation
 * Created in Spring 2020, C++
 */

#include <iostream>
#include <fstream>
#include <string>

#include "flight.h"
#include "passenger.h"
#include "plane.h"
#include "utilities.h"

using namespace std;


/* Driver Program */
int main(int argc, char** argv)
{

    if (argc != 2)
    {
        cout << "Expected Arguments: ./airline.out <inputFileName> \n";
        return 0;
    }

    // Read given file
    string firstLine;
    ifstream fin;
    fin.open(argv[1]);

    if (!fin)
    {
        cout << "Failed to open " << argv[1] << endl;
        return 0;
    } 

    getline(fin, firstLine);

    // Program initialization
    int numFlights = stoi(firstLine);
    Flight* flights = new Flight[numFlights];

    for (int idx = 0; idx < numFlights; idx++)
    {
        fin >> flights[idx];
    }
    
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
            case 2:
                findPassengerInfo(flights, numFlights);
                break;
            default: // Invalid input
                break;
        }
        // Get next choice
        choice = getChoice();
    } // Running loop

    // Clean up 
    delete [] flights;
    return 0;

} // End of main()
