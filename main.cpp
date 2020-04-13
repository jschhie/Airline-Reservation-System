/* 
 * Airline Reservation System Simulation
 * Spring 2020, C++
 */

#include <cctype>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

#include "flight.h"
#include "plane.h"
#include "ultilities.h"

using namespace std;


void printMenu()
{
    cout << "Flight Reservation Menu" << endl;
    cout << "0. Exit\n1. Add Passenger " << endl;
    cout << "\nYour Choice >> ";
} // printMenu()


int checkChoice(const char* yourChoice)
{
    int length = strlen(yourChoice);
    int intChoice;
    
    if (length != 1 || !isdigit(yourChoice[0]))
        cout << "Not an available choice." << endl;
    else
    {
        intChoice = atoi(&yourChoice[0]);
        if (intChoice == 0 || intChoice == 1)
            return intChoice; // Selected valid option
    } // Note: Available options are single digits (ie. values 0 or 1)
    
    cout << "Choice must be either 0 or 1. Please try again.\n" << endl;
    return -1; // Invalid option

} // checkChoice()


int getChoice()
{
    char choice[80];
    int result = 0;

    while(true)
    {
        printMenu();
        cin >> choice;
        
        result = checkChoice(choice);
        if(result != -1)
            break;

    } // while invalid choice received

    return result; // Valid input received

} // getChoice()


void showFlights(Flight* currFlights, int numFlights)
{

    if(!currFlights || numFlights <= 0) 
    {
        cout << "Error: Flights DNE." << endl;
        return;
    }
    
    // Otherwise, print out each Flight's number, origin, and destination
    cout << "Flight#\t\tOrigin\t\tDestination" << endl;
    cout << "------------------------------------------------" << endl;
    
    for(int i = 0; i < numFlights; i++)
        cout << currFlights[i];   
    
    return;

}


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
                break;
            default: // Invalid input
                break;
        }
        choice = getChoice(); // Get next choice
    } // Running loop
    
    delete [] flights;
    return 0;

} // Driver Program main()
