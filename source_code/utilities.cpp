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
    cout << "0. Exit & Save Data\n1. Add New Passenger\n2. Find Passenger Information" << endl;
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
    } // Note: Available options are single digits (ie. values 0, 1, or 2)
    
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
        if (result >= 0 && result <= 2)
            break; // Valid choices are 0, 1, and 2
        cout << "Choice must be either 0, 1, or 2. Please try again.\n\n";
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
        cin.getline(yourFlight, 80); // To remove '\n' from buffer

        if (strlen(yourFlight) == 0)
        {
            // User entered newline alone
            cout << "Please try again.\n\n";
            continue;
        }

        if (strcmp(yourFlight,"0") == 0) break; // Return to Main Menu

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
            if (findFlight(currFlights, numFlights, intFlight)) 
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


bool findFlight(Flight* currFlights, int numFlights, int target, int seatChoice, bool readonly)
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
                    return true;
                }
                return false;
            }

            // Otherwise, get passenger name and seat request
            cout << "\nFlight Number #" << flightNumber << " is available.\n";
            char fullName[30]; // Passenger::name is initialized to 30 chars
            cout << "Please enter the name of the passenger >> ";
            cin.getline(fullName, 30); 
            selectSeat(target, matchingPlane, fullName);
            return true;
        }
    }
    // Error: Target Flight DNE
    return false;
} // findFlight()


void findPassengerInfo(Flight* currFlights, int numFlights)
{
    char ticketID[80] = "";
    cout << "Enter Your Confirmation Ticket # >> ";
    cin.getline(ticketID, 80); // To remove '\n' from buffer
    
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
        
            // Find Flight in Flights array
            if (findFlight(currFlights, numFlights, fNumber, seatNumber, true))
            {
                // User decides when to return back to Main Menu
                //char uInput[20] = "";
                string uInput;
                while (1)
                {
                    cout << "Enter 0 to return to Main Menu >> ";
                    getline(cin, uInput);
                    uInput.erase(remove(uInput.begin(), uInput.end(),' '), uInput.end());
                    if (uInput == "0")
                        break;
                    cout << "Invalid option.\n";
                }
                return;
            }
        }
        catch (...)
        {
            // Invalid input: Contains non-digits
            // Do nothing and continue below and print error msg
        }
    }
    cout << "Invalid Ticket Number.\n\n";
    return;
    
} // findPassengerInfo()


void selectSeat(int yourFlightNum, Plane* yourPlane, const char* fullName)
{

    int capacity = yourPlane->getWidth() * yourPlane->getRows();
    int numOccupied = yourPlane->getReservations();
    
    // First check if yourPlane is full
    if (capacity == numOccupied)
        cout << "Unfortunately, the requested Flight is full.\n\n"; 
    else 
    {
        // Display Header and Plane Seating Visual
        cout << *yourPlane;
        yourPlane->addPassenger(yourFlightNum, fullName);
    }

} // selectSeat()
