# airline-reserv
## Brief Description
Airline Reservation System Project [Spring 2020; C++]

## How to Run the Program
For convenience, the corresponding Makefile has been provided, as well as a sample reservations.txt file. Expected command line arguments: './airline.out inputFile outputFile'.

## Usage
The current implementation offers users two choices: (0) Exit the program, and (1) Add a passenger.

#### Choice 0. Exiting the Program
Before exiting, program automatically generates a new file with the specified name (i.e. the last command line argument). The contents reflect the changes made (if any) to the airline reservation system during runtime. Both this 'outputFile' and 'inputFile' share the same format as detailed last section.

#### Choice 1. Adding a new Passenger
// TODO

## Expected Input/Output File Format
The I/O file format was designed by Sean Davis. The very first line states the total number of flights for this airline reservation system. The following descriptions apply for each flight instance. The first four lines of metadata lists the (1) flight number, (2) origin, (3) destination, and (4) the plane's dimensions and initial number of reservations. If the flight has any reservations, then the next set of lines lists each booked seat. 

The table below summarizes and exemplifies the formatting.

| Line # | Value(s) | Example | Extra Notes |
| ------ | -------- |  ---------| --------|
| 1 | Number of flights in total |  4| Single Integer |
| 2 | Flight number | 123 | Single Integer |
| 3 | Origin | San Diego | String |
| 4 | Destination | Los Angeles | String |
| 5 | number of rows and seats per row, followed by number of reservations (each sep. by a space)| 10 2 3 | Three Integers; plane capacity = 10 * 2 = 20 passengers |
| 6 | First Reservation (if any) | 10B Alice Wong | Alice Wong has made reservation for Row #10, Seat B |
| ...| ...| ...|...|
