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
int main(int argc, char** argv)
{
    if(argc != 3)
    {
        cout << "Expected Arguments: ./airline.out <inputFileName> <outputFileName>\n";
        return 0;
    }

    // Read given file
    string firstLine;
    ifstream fin;
    fin.open(argv[1]);

    if(!fin)
    {
        cout << "Failed to open " << argv[1] << endl;
        return 0;
    } 

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
    fout.open(argv[2], ios::out | ios::trunc);
    
    if(!fout)
        cout << "Failed to create new file.\n";     
    else
    {
        writeBack(flights, numFlights, fout);
        fout.close();
    }

    // Clean up and exit
    delete [] flights;    
    return 0;

} // End of main()
