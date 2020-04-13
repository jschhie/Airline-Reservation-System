#include "ultilities.h"

using namespace std;

/* Subfunctions */
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


void showFlights(const Flight* currFlights, int numFlights)
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

} // showFlights()


void selectFlight(Flight* currFlights, int numFlights)
{
    return;
} // selectFlight()
