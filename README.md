# Airline Reserv Project

## Brief Description
Airline Reservation System Project (Spring 2020; C++)

## Table of Contents
* [How to Run the Program](https://github.com/jschhie/airline-reserv/#how-to-run-the-program)
  * [Supplying an Input Script](https://github.com/jschhie/airline-reserv/#supplying-an-input-script)
* [Current Implementation & its Functionality](https://github.com/jschhie/airline-reserv/#usage)
  * [Exiting the Program](https://github.com/jschhie/airline-reserv/#choice-0-exiting-the-program)
  * [Adding a New Passenger](https://github.com/jschhie/airline-reserv/#choice-1-adding-a-new-passenger)
* [I/O File Formatting](https://github.com/jschhie/airline-reserv/#input--output-file-formatting)

## How to Run the Program 
## (NOTES: Current README refers to master branch. BinaryFiles branch work in progress)
For convenience, the corresponding Makefile has been provided, as well as a sample reservations.txt file. Expected command line arguments: ```./airline.out inputFile outputFile```.

#### Supplying an Input Script
You can supply an optional script containing your choices/responses with the following command: ```cat inputScript.txt | ./airline.out inputFile.txt outputFile.txt```.

## Usage
The current implementation offers users two choices: (0) Exiting the program, and (1) Adding a passenger.

#### Choice 0. Exiting the Program
Before exiting, program automatically generates a new file with the specified name (i.e. the last command line argument). The contents reflect the changes made (if any) to the airline reservation system during runtime. Both this ```outputFile``` and ```inputFile``` share the same format as detailed [last section](https://github.com/jschhie/airline-reserv/#input--output-file-formatting).

#### Choice 1. Adding a New Passenger
Upon request, the program will display all flights, where each one is identified by their flight number. Based on the available flights, the user should provide a flight number and the passenger's name. The reservation system will then prompt the user for a valid seating request. Note that passengers are added to the flight if the requested seat is available (i.e. not already occupied, or respective plane capacity has not been reached yet). 

During these series of interactions, the user can also return back to the Main Menu by entering ```0```.

## Input & Output File Formatting
The very first line should state the total number of flights for this airline reservation system. The following descriptions apply for each flight instance. The first four lines of metadata lists the (1) flight number, (2) origin, (3) destination, and (4) the plane's seating capacity and initial number of reservations. Finally, if the flight has *k* reservations, then the immediate *k* lines will list each booked seat. 

The table below summarizes and exemplifies the formatting.

| Line # | Value(s) | Example | Extra Notes |
| :------: | :--------: | :----------- | :--------:|
| 1 | Number of flights in total |  ```4```| Single Integer |
| 2 | Flight number | ```123``` | Single Integer |
| 3 | Origin | ```San Diego``` | String |
| 4 | Destination | ```Los Angeles``` | String |
| 5 | number of rows and seats per row, followed by number of reservations (each sep. by a space)| ```10 2 3``` | Three Integers (in this example, the plane capacity is 10 * 2 = 20 passengers, and there are currently 3 reservations) |
| 6 | First Reservation (if any) | ```10B Alice Wong``` | Alice Wong has made a reservation for Row #10, Seat B (for a particular flight) |
| ...| ...| ...|...|
