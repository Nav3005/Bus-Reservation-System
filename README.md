## Bus Reservation System

### Project Overview

The Bus Reservation System is a complete application designed to handle bus reservations efficiently. This system allows users to check available buses, reserve seats, and view reservations. The project is built using C for the core functionality and file handling, and aims to provide a seamless experience for managing bus schedules and reservations.

### Features

1. **Bus and Driver Management**:
   - Manage bus details including bus number, driver name, arrival and departure times, and route information.
   - Load bus details from a file and update as needed.

2. **Seat Reservation**:
   - Allow users to reserve seats on a bus with options to select multiple seats.
   - Detect and handle seat conflicts and reservations.

3. **Display Available Buses**:
   - Show a list of available buses based on departure and arrival cities.
   - Display detailed information including bus number, driver name, departure and arrival times.

4. **Show Bus Details**:
   - View specific bus details including seat availability and reservation status.

### Technologies Used

- **C**: Core programming language for the application logic.
- **File Handling**: For reading and writing bus and reservation data.

### Installation and Setup

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/Nav3005/Bus-Reservation-System.git
   cd Bus-Reservation-System

2. **Compile the Code**:
   Use a C compiler to compile the source code:
   ```bash
   gcc -o bus_reservation_system bus_reservation_system.c

3. **Run the Application**:
   ```bash
   ./bus_reservation_system

### Usage

1. **Launching the Application**:
   - Run `bus_reservation_system` to start the application.
   - The application will present a menu with options for reservations, viewing bus details, and more.

2. **Creating a Bus Schedule**:
   - Navigate to the option for adding a new bus schedule.
   - Enter details such as bus number, driver name, arrival time, departure time, and route information.
   - Save the schedule to the file by following the on-screen prompts.

3. **Reserving a Seat**:
   - Choose the option to reserve a seat.
   - Provide your personal details including name, age, and gender.
   - Enter your departure and arrival cities.
   - Select an available bus from the list of buses between your chosen cities.
   - Choose your preferred seat(s) from the available options and complete the reservation process.

4. **Viewing Bus Details**:
   - Select the option to view bus details.
   - Enter the bus number you want to inquire about.
   - The application will display detailed information about the bus, including seat availability and reservation status.

5. **Viewing Available Buses**:
   - Use the option to display available buses between specific cities.
   - The application will list buses that operate between the departure and arrival cities you specify, including departure and arrival times, bus number, and driver name.



