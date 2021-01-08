#include <algorithm> // ::transform

#include "utilities.h"

using namespace std;

/* Subfunctions */

void printMenu()
{
    // Center header line and add borders
    int numReps = 43;
    cout << string(numReps, '=') << endl;
    string header = "Flight Reservation Menu";
    int numSpaces = (numReps - header.size()) / 2;
    cout << string(numSpaces, ' ') << header << endl;
    cout << string(numReps, '-') << endl;
    // Get user input for Main Menu
    cout << "0. Exit & Save Data\n1. Add New Passenger\n";
    cout << "2. Find Passenger Information\n3. Cancel Reservation\n";
    cout << string(numReps, '=') << endl;
    cout << "\nYour Choice >> ";
} // printMenu()


int checkChoice(const char* yourChoice)
{
    int length = strlen(yourChoice), idx = -1;
    if (length) 
    {
        for (int i = 0; i < length; i++)
        {
            if (isdigit(yourChoice[i]))
            {
                if (idx == -1) 
                    idx = i;
                else
                {
                    idx = -1;
                    break;
                } // Reset flag (index), digit already seen
            }
            else if (!iswspace(yourChoice[i]))
            {
                cout << "Not an available choice.\n";
                idx = -1;
                break; 
            } // Reset flag, raise error
        } // Check each character and ignore whitespaces
    } // NOTE: Available options are single digits (ie. values 0 through 3)
    
    if (idx == -1) 
        return -1;
    else
        // Otherwise, convert from char to integer value
        return (atoi(&yourChoice[idx]));
} // checkChoice()


int getChoice()
{
    char choice[80];
    int result = 0;

    while (1)
    {
        printMenu();
        cin.getline(choice, 80);
        result = checkChoice(choice);
        if (result >= 0 && result <= 3)
            break; // Valid choices are 0 through 3
        cout << "Choice must be between 0 and 3. Please try again.\n\n";
    } // while invalid choice received
    return result;
} // getChoice()


void showFlights(const Flight* currFlights, int numFlights)
{
    // Conditionally print out Flight information
    if (!currFlights || numFlights <= 0) 
    {
        cout << "Error: Flights DNE." << endl;
        return;
    }
    
    // Center header line and add borders
    char border = '=';
    int numReps = 43;
    cout << string(numReps, border) << endl;
    cout << "Flight#\t\tOrigin\t\tDestination\n";
    cout << string(numReps, '-') << endl;
     
    // Overloaded printing of 'Flight' instances 
    for (int i = 0; i < numFlights; i++)
        cout << currFlights[i];
    cout << string(numReps, border) << endl << endl;
    return;
} // showFlights()


void selectFlight(Flight* currFlights, int numFlights)
{
    char yourFlight[80] = "";
    int intFlight;
    bool validNum; 
    do 
    {
        validNum = true;
        cout << "Flight Number (Enter 0 to return to Main Menu) >> ";
        cin.getline(yourFlight, 80); 

        if (strlen(yourFlight) == 0)
        {
            // User entered newline alone
            cout << "Please try again.\n\n";
            continue;
        }

        if (strcmp(yourFlight,"0") == 0) 
            break; // Return to Main Menu

        // Check for invalid characters
        for (int i = 0; i < strlen(yourFlight); i++) 
        {
            if (!isdigit(yourFlight[i])) 
            {
                validNum = false;
                break;
            }
        }

        // Input contains only digits
        if (validNum) 
        {
            intFlight = stoi(yourFlight);
            if (findFlight(currFlights, numFlights, intFlight) != NULL) 
                break;
            else {
                cout << "We do not have a Flight Number #" << yourFlight << endl;
                validNum = false;
            }
        }

        // Default: Display error message
        cout << "Please try again.\n\n";

    } while(!validNum);
    return;
} // selectFlight()


Plane* findFlight(Flight* currFlights, int numFlights, int target, int seatChoice, bool readonly)
{
    int flightNumber = 0;
    for (int i = 0; i < numFlights; i++)
    {
        flightNumber = currFlights[i].getFlightNum();
        if (flightNumber == target)
        {
            Plane* matchingPlane = currFlights[i].getPlane();
            if (readonly)
            {
                if (matchingPlane->checkSeat(seatChoice))
                {
                    // Print remaining Flight information
                    cout << setw(16) << "Origin City: ";
                    cout << currFlights[i].getOrigin() << endl;
                    cout << setw(16) << "Destination: ";
                    cout << currFlights[i].getDestination() << endl;
                    cout << string(43, '=') << endl << endl;
                    return matchingPlane;
                }
                return NULL;
            }

            // Otherwise, readonly=false
            selectSeat(target, matchingPlane);
            return matchingPlane;
        }
    }
    // Error: Target Flight DNE
    return NULL;
} // findFlight()


bool findPassengerInfo(Flight* currFlights, int numFlights, bool cancelMe)
{
    char ticketID[80] = "";
    cout << "Enter Your Confirmation Ticket # >> ";
    cin.getline(ticketID, 80); 
    
    bool validFormat = false;
    char* token = strchr(ticketID, '-');
    if (token)
    {
        // Ensure only one '-' token present
        char* otherToken = strrchr(ticketID, '-');
        if ((token-ticketID+1) == (otherToken-ticketID+1))
            validFormat = true;
    } 
    
    if (validFormat)
    {
        string strTicket(ticketID);
        size_t pos = strTicket.find("-");

        try
        {
            int fNumber = stoi(strTicket.substr(0, pos)); 
            int seatNumber = stoi(strTicket.substr(pos+1));
        
            // Find Flight in Flights array: returns Plane* ptr if success
            Plane* yourPlane = NULL;
            yourPlane = findFlight(currFlights, numFlights, fNumber, seatNumber, true);
            if (yourPlane != NULL)
            {
                // Checks if cancelMe flag set (true)
                string uInput;
                while(!cancelMe)
                {
                    cout << "Enter 0 to return to Main Menu >> ";
                    getline(cin, uInput);
                    uInput.erase(remove(uInput.begin(), uInput.end(),' '), uInput.end());
                    if (uInput == "0")
                        break;
                    cout << "Invalid option.\n";
                }
                
                if (cancelMe)
                {
                    if (!confirmCancellation())
                        return false;
                    yourPlane->removePassenger(seatNumber);
                }
                return true;
            }
        }
        catch (...)
        {
            // Invalid input: Contains non-digits
            // Do nothing and continue below and print error msg
        }
    }
    cout << "Invalid Ticket Number.\n\n";
    return false;
} // findPassengerInfo()


void selectSeat(int yourFlightNum, Plane* yourPlane)
{
    int capacity = yourPlane->getWidth() * yourPlane->getRows();
    int numOccupied = yourPlane->getReservations();
    
    // First check if yourPlane is full
    if (numOccupied == capacity)
        cout << "Unfortunately, the requested flight is full.\n\n"; 
    else 
    {
        // Otherwise, get passenger name and seat request
        cout << "\nFlight Number #" << yourFlightNum << " is available.\n";
        // Passenger::name is initialized to 30 chars
        char fullName[30]; 
        cout << "Please enter the name of the passenger >> ";
        cin.getline(fullName, 30);
        // Display header and Plane Seating Map 
        cout << *yourPlane;
        yourPlane->addPassenger(yourFlightNum, fullName);
    }
} // selectSeat()


bool confirmCancellation()
{
    cout << "Are you sure you want to cancel this reservation? (Y/N) >> ";
    string uInput;
    getline(cin, uInput);
    
    uInput.erase(remove(uInput.begin(), uInput.end(),' '), uInput.end());
    if (uInput.size())
    {
        transform(uInput.begin(), uInput.end(), uInput.begin(), ::tolower);
        size_t foundN = uInput.find("n"); // No
        size_t foundY = uInput.find("y"); // Yes
        if (foundN == string::npos && foundY != string::npos)
            return true;
    }
   
    // None, No, or Other choice specified
    cout << "Cancellation stopped. Returning to Main Menu. \n\n";
    return false; 
} // confirmCancellation()
