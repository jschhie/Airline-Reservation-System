# Airline Reservation System
> C++

## Project Overview
This C++ program simulates a virtual airline reservation system that: 
<ul>
 <li> Registers new passengers while detecting duplicate requests </li>
 <li> Allows users to look up their booking details </li>
 <li> Enables optional cancellation reservations </li>
 <li> Maintains various seating capacities across multiple customizable flights. </li>
</ul>

You can find a visual demo [here](https://github.com/jschhie/airline-reserv/#visual-demo).

## Table of Contents
* [Visual Demo](https://github.com/jschhie/airline-reserv/#visual-demo)
* [How to Run the Program](https://github.com/jschhie/airline-reserv/#how-to-run-the-program)
  * [Input CSV File Formatting](https://github.com/jschhie/airline-reserv/#input-csv-file-formatting)

## Visual Demo
This demonstration uses the following sample files:
* ```flights.csv```
* ```passengers.dat```
  
Additionally, it incorporates scripts:
* ```inPassenger.txt```
* ```inTicketCheck.txt```

| Program State | Description |
| ----- | :----- |
| ![alt text](https://github.com/jschhie/Airline-Reservation-System/blob/master/demo/Updated%20Main%20Menu.png?raw=true "Main Menu") | <dl> <dt> Main Menu display </dt> </dl> |
| ![alt text](https://github.com/jschhie/Airline-Reservation-System/blob/master/demo/Updated%20Flights%20Menu.png?raw=true "Flights Menu") | <dl> <dt> Flights Menu </dt> <dd> Displays all current flights. This can be customized by supplying an input .CSV file. </dd></dl> |
| ![alt text](https://github.com/jschhie/Airline-Reservation-System/blob/master/demo/Add%20New%20Passenger.png?raw=true "Add New Passenger") | <dl> <dt> Create New Booking </dt> <dd> Register Rebecca Smith as a new passenger on Flight #552. </dd> <dd> Selected seat: Seat 8A. Ticket Number: 552-42. </dd> </dl>| 
| ![alt text](https://github.com/jschhie/Airline-Reservation-System/blob/master/demo/Passenger%20Lookup.png?raw=true "Check Reservation Details") | <dl> <dt> Flight Lookup </dt> <dd> Check reservation details with the given Ticket Number. </dd> <dd> Confirms ```Rebecca Smith```'s earlier booking. </dd> </dl>|
| ![alt text](https://github.com/jschhie/Airline-Reservation-System/blob/master/demo/New%20Check%20Cancellation.png?raw=true "Cancel Booking") | <dl> <dt> Cancel Booking </dt> <dd> Cancel Rebecca Smith's reservation above. </dd> </dl>|

## How to Run the Program  
For convenience, a ```Makefile``` file is provided. To create and run the program, follow these steps:

1. Navigate to the source code directory:
```bash 
cd /source_code/
```

2. Build the program executable:
```bash 
make all
```

3. Run the program with the required CSV file as a command line argument:
```bash
./airline.out filepath/csv_file.csv
```

Ensure that the CSV file contains all necessary flight information. Refer to the [next section](https://github.com/jschhie/airline-reserv/#input-csv-file-formatting) for the expected CSV format.

<details>
 <summary>
  <b> Show Notes </b>
 </summary>
 <ul> 
  <li> Sample files, including <code>flights.csv</code> and <code>passengers.dat</code> can be found in the <code>refs</code> directory. </li> 
  <li> The <code>passengers.dat</code> file is a binary file containing sample flight reservations. </li>
  <li> You may also replace this file with an empty file to initialize all flights with zero passengers. </li>
</details>

#### Input CSV File Formatting
* The first line must indicate the total number of flights, *k*, for the airline reservation system.
* The following *k* lines should detail each flight's:
  * Flight number
  * origin
  * destination
  * plane dimensions

> Note: Only the flight number needs to be unique.

The table below summarizes and demonstrates the formatting.
| Line # | Value(s) | Example | Extra Notes |
| :------: | :-------- | :----------- | :--------|
| 1 | Total number of flights |  ```4```| Single Integer, *k* |
| 2 | First flight number, origin, destination, total rows, total seats per row | ```815, Reno, San Diego, 5, 6``` | Flight #815 has a seating capacity of 30 (5 rows * 6 seats per row) |
| ...| ...| ...|...|
| *k*+1 | Last flight number, origin, destination, total rows, total seats per row | ```512, Davis, Reno, 4, 4 ```| The last flight has a seating capacity of 16 (4 rows * 4 seats per row) | 

<details>
 <summary>
  <b>Show Notes</b>
 </summary>
<ul>
 <li> For readability, the values listed are separated by a comma followed by a single whitespace. </li>
 <li> The actual CSV format requires the values to be separated by only a comma. </li>
 </ul>
</details>
