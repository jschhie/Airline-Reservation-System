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
    cout << endl;
    return;

} // showFlights()


void selectFlight(Flight* currFlights, int numFlights)
{
    char yourFlight[80];
    int intFlight; // Assuming valid input with all digits    
    do 
    {
        cout << "Flight Number (Enter 0 to return to Main Menu) >> ";
        cin >> yourFlight;
        intFlight = stoi(yourFlight);
        
        if(intFlight == 0) break;
        
        else if(intFlight > 0 && findFlight(currFlights, numFlights, intFlight)) break;

        // Default: Display error message
        cout << "We do not have a flight number #" << intFlight << endl;
        cout << "Please try again.\n\n";

    } while(intFlight);
    
    return;
        
} // selectFlight()

bool findFlight(Flight* currFlights, int numFlights, int target)
{
    int flightNumber = 0;
    for(int i = 0; i < numFlights; i++)
    {
        flightNumber = currFlights[i].getFlightNum();
        if(flightNumber == target)
        {
            char fullName[80]; // Assumes 80 chars max
            cout << "Please enter the name of the passenger >> ";
            cin.ignore(); // Flush buffer to remove '\n' char
            cin.getline(fullName, 80);
            Plane* matchingPlane = currFlights[i].getPlane();
            selectSeat(matchingPlane, fullName);
            return true;
        }
    }

    return false;
} // findFlight()


void selectSeat(Plane* yourPlane, const char* fullName)
{
    int capacity = yourPlane->getWidth() * yourPlane->getRows();
    int numOccupied = yourPlane->getReservations();

    // First check if yourPlane is full
    if (capacity == numOccupied)
    {
        cout << "Unfortunately requested Flight is full.\n\n"; 
        return;
    }
        
    // Display Header and Plane Seating Visual
    cout << *yourPlane;
    yourPlane->addPassenger(fullName);

    return;

} // selectSeat()
