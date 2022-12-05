# Airline Reservation System

> Written in C++.

## Project Overview
This program simulates an virtual airline reservation system that: 
<ul>
 <li> Registers new passengers while detecting duplicate requests, </li>
 <li> Allows users to look up their booking details, </li>
 <li> Optionally cancel their reservations, and </li>
 <li> Maintains various seating capacities across multiple and customizable flights. </li>
</ul>

A visual demo can be found [here](https://github.com/jschhie/airline-reserv/#visual-demo).


## Table of Contents
* [How to Run the Program](https://github.com/jschhie/airline-reserv/#how-to-run-the-program)
  * [Input CSV File Formatting](https://github.com/jschhie/airline-reserv/#input-csv-file-formatting)
* [Visual Demo](https://github.com/jschhie/airline-reserv/#visual-demo)


## How to Run the Program  
For convenience, the corresponding ```Makefile``` has been provided. To create and run the program, the user may enter:
```bash 
cd /source_code/
make all
``` 
to create the program executable called ```airline.out```.

Next, this program expects two command line arguments as follows: 
```bash
./airline.out filepath/csv_file.csv
```

The CSV file should contain all flights' information. See the expected CSV format in the [next section](https://github.com/jschhie/airline-reserv/#input-csv-file-formatting).

<details>
 <summary>
  <b> Show Notes </b>
 </summary>
 <ul> 
  <li> Sample files (flights.csv and passengers.dat) can be found in the refs/ directory. </li> 
  <li> The latter is a binary file with sample flight reservations. </li>
  <li> The user may also replace this with an empty file to initialize all flights with zero passengers. </li>
</details>


#### Input CSV File Formatting
The very first line must state the total number of flights, *k*, for this airline reservation system. The subsequent *k* lines specify each flight's associated flight number, origin, destination, and plane dimensions. Note that only the flight numbers need to be unique. 

The table below summarizes and demonstrates the formatting.
| Line # | Value(s) | Example | Extra Notes |
| :------: | :-------- | :----------- | :--------|
| 1 | Number of flights in total |  ```4```| Single Integer, *k* |
| 2 | First Flight's flight number, origin, destination, total rows, total seats per row | ```815, Reno, San Diego, 5, 6``` | Flight #815 has a seating capacity of 30 (i.e., 5 rows * 6 seats per row) |
| ...| ...| ...|...|
| *k*+1 | Last Flight's flight number, origin, destination, total rows, total seats per row | ```512, Davis, Reno, 4, 4 ```| The last flight has a seating capacity of 16 (i.e., 4 rows * 4 seats per row) | 

<details>
 <summary>
  <b>Show Notes</b>
 </summary>
<ul>
 <li> For the sake of readability, the values listed have been separated by a comma followed by a single whitespace. </li>
 <li> The actual CSV format requires that they are separated by just a comma. </li>
 </ul>
</details>


## Visual Demo
This demonstation uses the sample files ```flights.csv``` and ```passengers.dat```. 
It also uses the corresponding scripts ```inPassenger.txt``` and ```inTicketCheck.txt```.

| Program State | Description |
| ----- | :----- |
| ![alt text](https://github.com/jschhie/Airline-Reservation-System/blob/master/demo/Updated%20Main%20Menu.png?raw=true "Main Menu") | <dl> <dt> Main Menu display </dt> </dl> |
| ![alt text](https://github.com/jschhie/Airline-Reservation-System/blob/master/demo/Updated%20Flights%20Menu.png?raw=true "Flights Menu") | <dl> <dt> Display all current flights. </dt> <dd> This can be customized by supplying an input .CSV file. </dd></dl> |
| ![alt text](https://github.com/jschhie/Airline-Reservation-System/blob/master/demo/Add%20New%20Passenger.png?raw=true "Add New Passenger") | <dl> <dt> Create New Booking </dt> <dd> Register Rebecca Smith as a new passenger to Flight #552. </dd> <dd> Selected seat: Seat 8A and Ticket Number generated: 552-42. </dd> </dl>| 
| ![alt text](https://github.com/jschhie/Airline-Reservation-System/blob/master/demo/Passenger%20Lookup.png?raw=true "Check Reservation Details") | <dl> <dt> Flight Lookup </dt> <dd> Check reservation details with given Ticket Number. </dd> <dd> This confirms ```Rebecca Smith```'s earlier booking. </dd> </dl> |
| ![alt text](https://github.com/jschhie/Airline-Reservation-System/blob/master/demo/New%20Check%20Cancellation.png?raw=true "Cancel Booking") | <dl> <dt> Cancel Booking </dt> <dd> Cancel ```Rebecca Smith```'s reservation above. </dd> </dl>|
