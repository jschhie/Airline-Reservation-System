# Airline Reservation System
> Created in Spring 2020 as an independent project (ongoing). Written in C++.


## Project Overview
This program simulates an airline reservation system. 

### Features:
- Adds new passengers while detecting duplicate requests
- Maintains various seating capacities across multiple flights
- Allows for reservation lookups

A visual demo can be found [here](https://github.com/jschhie/airline-reserv/#visual-demo).


## Table of Contents
* [How to Run the Program](https://github.com/jschhie/airline-reserv/#how-to-run-the-program)
  * [Input CSV File Formatting](https://github.com/jschhie/airline-reserv/#input-csv-file-formatting)
  * [Supplying an Input Script](https://github.com/jschhie/airline-reserv/#supplying-an-input-script)
* [Current Implementation & its Functionality](https://github.com/jschhie/airline-reserv/#program-usage)
  * [Exiting the Program](https://github.com/jschhie/airline-reserv/#choice-0-exiting-the-program)
  * [Adding a New Passenger](https://github.com/jschhie/airline-reserv/#choice-1-adding-a-new-passenger)
  * [Reservation Lookups](https://github.com/jschhie/airline-reserv/#choice-2-looking-up-reservation-details)
* [Visual Demo](https://github.com/jschhie/airline-reserv/#visual-demo)
* [Acknowledgments](https://github.com/jschhie/airline-reserv/#acknowledgments)


## How to Run the Program  
For convenience, the corresponding ```Makefile``` has been provided. The user should *first* go into the /source_code/ directory and then run the command: ```make all``` to create the program executable called ```airline.out```.

Next, this program expects two command line arguments as follows: ```./airline.out filepath/csv_file.csv```. The CSV file is to contain information for each flight instance. The expected CSV format is detailed in the [next section](https://github.com/jschhie/airline-reserv/#input-csv-file-formatting).

Lastly, a sample ```flights.csv``` and a ```passengers.dat``` file can be found in the /refs/ directory. The latter is a binary file with sample flight reservations prior to runtime. The user may also replace this with an empty file to simulate complete vacancy for each flight. In this case, each flight would be initialized with zero passengers. 


#### Input CSV File Formatting
The very first line must state the total number of flights, *k*, for this airline reservation system. The subsequent *k* lines specify each flight's associated flight number, origin, destination, and plane dimensions. Note that only the flight numbers need to be unique. 

The table below summarizes and exemplifies the formatting.
| Line # | Value(s) | Example | Extra Notes |
| :------: | :--------: | :-----------: | :--------:|
| 1 | Number of flights in total |  ```4```| Single Integer, *k* |
| 2 | First Flight's flight number, origin, destination, total rows, total seats per row | ```815, Reno, San Diego, 5, 6``` | Flight #815 has a seating capacity of 30 (i.e., 5 rows * 6 seats per row) |
| ...| ...| ...|...|
| *k*+1 | Last Flight's flight number, origin, destination, total rows, total seats per row | ```512, Davis, Reno, 4, 4 ```| The last flight has a seating capacity of 16 (i.e., 4 rows * 4 seats per row) | 

> REMARK: For the sake of readability, the values listed have been separated by a comma followed by a single whitespace. The actual CSV format requires that they are separated by just a comma. 


#### Supplying an Input Script
You can supply an optional script containing your choices/responses with the following command: ```cat inputScript.txt | ./airline.out flights.csv```.


## Program Usage
The current implementation offers users the following choices: (0) Exiting and saving the program, (1) Adding a passenger, and (2) Looking up reservation details. 


#### Choice 0. Exiting the Program
This program does not generate any new files. Instead, it updates/appends to the said ```passengers.dat``` file. The file's contents reflect the changes made (if any) to the airline reservation system during runtime. 


#### Choice 1. Adding a New Passenger
Upon request, the program will display all flights, where each one is identified by their flight number. Based on the available flights, the user should provide a flight number and the passenger's name. The reservation system will then prompt the user for a valid seating request. Note that passengers are added to the flight if the requested seat is available (i.e. not already occupied, or respective plane capacity has not been reached yet). 

Once the user has successfully booked their reservation, the program will generate a unique Ticket Number, which can later be used for looking up their flight details. 

During these series of interactions, the user can also return back to the Main Menu by entering ```0```.


#### Choice 2. Looking Up Reservation Details
To look up their flight details, the user needs to provide their unique Ticket Number that was generated after booking their flight. The program will then display all relevant information, if a valid Ticket Number is given. 


## Visual Demo
This demo uses the provided ```flights.csv``` and ```passengers.dat``` files from the /refs/ directory. 
It also uses the ```inPassenger.txt``` and ```inTicketCheck.txt``` scripts from the /source_code/sample_scripts/ directory.

| Program State | Description |
| ----- | :-----: |
| ![alt text](https://github.com/jschhie/Airline-Reservation-System/blob/master/demo/Show%20Menu.png?raw=true "Main Menu") | Main Menu Display |
| ![alt text](https://github.com/jschhie/Airline-Reservation-System/blob/master/demo/Current%20Flights%20Menu.png?raw=true "Flights Menu") | Current Flights Menu |
| ![alt text](https://github.com/jschhie/Airline-Reservation-System/blob/master/demo/Add%20Passenger.png?raw=true "Add Passenger") | Register "Rebecca Smith" as a new passenger to Flight #552. Here, Seat 8A was selected. Ticket Number generated: "552-42." | 
| ![alt text](https://github.com/jschhie/Airline-Reservation-System/blob/master/demo/Passenger%20Lookup.png?raw=true "Check Reservation Details") | Check reservation details with given Ticket Number. This validates and confirms "Rebecca Smith"'s earlier registration. |


## Acknowledgments
My former professor created some of the sample input files found in the /refs/ directory (i.e., ```flights.csv```, ```reservations.txt```, and ```passengers2.dat```). The source code and README were both written by myself. 
