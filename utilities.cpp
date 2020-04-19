#include "utilities.h"

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

    int length = strlen(yourChoice), index = -1;
    if(length) 
    {
        for(int i = 0; i < length; i++)
        {
            if(isdigit(yourChoice[i]))
            {
                if(index == -1) index = i;
                else
                {
                    index = -1;
                    break;
                } // Reset flag (index), digit already seen
            }
            else if(!iswspace(yourChoice[i]))
            {
                cout << "Not an available choice.\n";
                index = -1;
                break; 
            } // Reset flag, raise error
        } // Check each character and ignore whitespaces
    } // Note: Available options are single digits (ie. values 0 or 1)
    
    if(index == -1) return -1;
    // Otherwise, convert from char to integer value
    return (atoi(&yourChoice[index]));

} // checkChoice()


int getChoice()
{

    char choice[80];
    int result = 0;

    while(true)
    {
        printMenu();
        cin.getline(choice, 80);
        result = checkChoice(choice);
        if(result == 0 || result == 1)
            break; // Valid choices are 0 and 1
        cout << "Choice must be either 0 or 1. Please try again.\n\n";
    } // while invalid choice received
    
    return result;

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
    char yourFlight[80] = "";
    int intFlight; // Assuming valid input with all digits   
    do 
    {
        cout << "Flight Number (Enter 0 to return to Main Menu) >> ";
        cin.getline(yourFlight, 80); // To remove '\n' from buffer
        if(strlen(yourFlight) == 0)
        {
            // User entered newline alone
            cout << "Please try again.\n\n";
            continue;
        }

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


void writeBack(const Flight* currFlights, int totalFlights, fstream& outFile)
{
    outFile << totalFlights << endl;
    for(int i = 0; i < totalFlights; i++)
    {
        // Write flightNumber
        outFile << currFlights[i].getFlightNum() << endl;
        // Write origin
        outFile << currFlights[i].getOrigin() << endl;
        // Write destination
        outFile << currFlights[i].getDestination() << endl;
        // Write plane dimensions & passenger seating info
        currFlights[i].getPlane()->writePlaneInfo(outFile);
    }
} // writeBack()
