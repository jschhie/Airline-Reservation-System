#include <cstdio>
#include <iostream>
//#include <fstream>

using namespace std;

class Passenger {
    short flightNum, row;
    char seat, name[30];
public:
    friend ostream& operator<< (ostream& os, const Passenger& passengerRef);
};

ostream& operator<< (ostream& os, const Passenger& passengerRef) {
    os << "flightNum: " << passengerRef.flightNum << endl;
    os << "row: " << passengerRef.row << endl;
    os << "seat: " << passengerRef.seat << endl;
    os << "name: " << passengerRef.name << endl;
    return os;
}

int main() {
    //ifstream inFile("passengers.dat", ios::binary);
    FILE* inFile;
    inFile = fopen("passengers.dat", "rb");

    //if (inFile.is_open()) {
    if (inFile) {
        cout << "open success" << endl;
        // Read binary data into Passenger object
        
        long pos1, pos2;
        pos1 = ftell(inFile);
        cout << "pos1: " << pos1 << endl;

        // get file size
        fseek(inFile, 0, SEEK_END);
        long fileSize = ftell(inFile);
        rewind(inFile);
    
        // alloc mem to contain whole file
        char* buffer;
        buffer = (char*) malloc(sizeof(char)*fileSize);
        if (buffer == NULL) {
            perror("Error");
            fclose(inFile);
            return 0;
        }

        fread(buffer, fileSize, 1, inFile);

        pos2 = ftell(inFile);
        cout << "pos2: " << pos2 << endl;
        
        cout << buffer << endl;

        // Close input file
        //inFile.close();
    } else
        perror("cannot open binary file");
    
    fclose(inFile);

    return 0;
}
