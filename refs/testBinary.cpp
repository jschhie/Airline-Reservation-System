#include <cstdio>
#include <iostream>
#include <fstream>

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
    ifstream inFile("passengers.dat", ios::binary);

    if (inFile.is_open()) {
        // Read binary data into Passenger object
        Passenger passenger[3];
        
        long pos1, pos2, pos3; 
        pos1 = inFile.tellg();
        cout << "pos1: " << pos1 << endl;

        inFile.read((char*) &passenger[0], sizeof(Passenger));
        cout << passenger[0];

        pos2 = inFile.tellg();
        cout << "pos2: " << pos2 << endl;

        inFile.read((char*) &passenger[1], sizeof(Passenger));
        cout << passenger[1];
        
        pos3 = inFile.tellg();
        cout << "pos3: " << pos3 << endl;

        cout << "sizeof Pass: " << sizeof(Passenger) << endl;
        // Close input file

        // resetting via fseek
        inFile.seekg(pos2, inFile.beg);
        inFile.read((char*) &passenger[2], sizeof(Passenger));
        cout << passenger[2];

        // double check that original copy exists still
        cout << "original" << endl;
        cout << passenger[1];

        inFile.close();
    } else
        cout << "cannot open binary file" << endl;
    
    return 0;
}
