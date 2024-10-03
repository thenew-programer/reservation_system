# Dental Appointment Reservation Management System

This application is designed to manage dental appointment reservations, offering features such as adding, modifying, and deleting reservations, tracking their status, and generating statistics.

## Features

1. **Add a Reservation:**

   - Allows the addition of a new reservation by providing the following information:
     - First Name
     - Last Name
     - Phone Number
     - Age
     - Status (validated, postponed, canceled, processed)
     - Unique Reference (automatically generated)
     - Reservation Date

2. **Modify or Delete a Reservation:**

   - Modify or delete an existing reservation based on the unique reference.

3. **View Reservation Details:**

   - View the complete details of a reservation, including the date and status (validated, postponed, canceled, processed).

4. **Sort Reservations:**

   - Sort reservations by last name.
   - Sort reservations by date (optional).
   - Sort reservations by status (validated, postponed, canceled, processed).

5. **Search for Reservations:**

   - Search for a reservation by unique reference.
   - Search for a reservation by name.
   - Search for a reservation by date (optional).

6. **Statistics:**
   - Calculate the average age of patients with reservations.
   - Display the number of patients by age group (e.g., 0-18 years, 19-35 years, 36+ years).
   - Generate statistics for the total number of reservations by status (validated, canceled, etc.).

> **Note**: The project contains 10 default insertions (10 reservations automatically inserted upon program execution).

## Requirements

- **Variables**: To store reservation information.
- **Conditions**: To search, modify, and delete reservations.
- **Loops**: To iterate through the list of reservations.
- **Arrays**: To store multiple reservations.
- **Strings**: To manipulate names, phone numbers, etc.
- **Structures**: To group reservation-related information.

## How to Run the Project

### Prerequisites

- Ensure you have `make` installed.
- A C compiler like `gcc` or `cc`.

### Steps

1. **Clone the repository:**
   ```bash
   git clone https://github.com/thenew-programer/reservation_system.git
   cd reservation_system
   ```
2. **Build the project:** To compile the project, run:

   ```bash
   make

   ```

3. **Run the program:** After successful compilation, execute the program:
   ```bash
   ./youcode
   ```
4. **Clean build files:** To clean up the object files and build directory, run:
   ```bash
   make clean
   ```
5. **Full clean (including the compiled binary):** To clean up all generated files, including the binary:
   ```bash
   make fclean
   ```
6. **Rebuild the project:** To fully clean and rebuild the project:
   ```bash
   make re
   ```

## File Structure

- `./includes/`: Contains the header files.
- `./srcs/`: Contains the source files (`.c`).
- `./objs/`: Contains the object files generated during the build process.
- `Makefile`: Defines the rules for building, cleaning, and rebuilding the project.
