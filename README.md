# 2024/11/11

# Car Rental Management System

This project implements a **Car Rental Management System** using C. The system manages cars in three states:
1. **Available for rent**
2. **Currently rented**
3. **In repair**

It uses linked lists for efficient data management and supports various operations such as adding cars, renting cars, and transferring cars between states.

---

## Table of Contents

1. [Introduction](#introduction)
2. [Features](#features)
3. [Program Structure](#program-structure)
   - [Main Program](#main-program)
   - [Core Functionalities](#core-functionalities)
   - [File I/O](#file-i-o)
4. [How to Run](#how-to-run)
5. [Usage](#usage)
6. [Implementation Details](#implementation-details)
   - [Memory Management](#memory-management)
   - [Profit Calculation](#profit-calculation)

---

## Introduction

The **Car Rental Management System** is designed to simplify operations for a car rental business. It manages cars in three distinct categories:
- **Available for rent**: Cars ready to be rented.
- **Rented**: Cars currently rented by customers.
- **In repair**: Cars under maintenance.

The system provides options for adding cars, processing returns, transferring cars to repair, and renting cars to customers.

---

## Features

1. **Dynamic Linked List Management**:
   - Cars are stored in linked lists, categorized by their state.
   - Operations such as insertion, deletion, and traversal are efficiently implemented.

2. **File Persistence**:
   - All data is saved to files (`available.txt`, `rented.txt`, `repair.txt`) for persistence between program runs.
   - Data is reloaded into the system upon startup.

3. **Profit Calculation**:
   - Calculates rental charges based on mileage driven.

4. **Comprehensive Menu**:
   - User-friendly menu with options for all supported operations.

---

## Program Structure

### Main Program

- **`q1.c`**:
  - Entry point of the program.
  - Implements the menu-driven interface.
  - Handles user inputs and invokes appropriate functions.

### Core Functionalities

- **`q1.h`**:
  - Contains structure definitions and function prototypes.
  - Defines the `struct car` linked list node.

- **`q1_functions.c`**:
  - Implements all core functionalities, including:
    - Adding cars to lists.
    - Transferring cars between lists.
    - Printing lists.
    - File I/O operations for data persistence.

### File I/O

- The program saves and loads lists from the following files:
  - **`available.txt`**: Cars available for rent.
  - **`rented.txt`**: Cars currently rented.
  - **`repair.txt`**: Cars in repair.
- Ensures data integrity and persistence between runs.

---

## How to Run

### Prerequisites

- A C compiler (e.g., GCC or Clang).
- Basic understanding of linked lists and file handling.

### Compilation and Execution

1. Compile the program:
   ```bash
   gcc q1.c q1_functions.c -o car_rental
   ```
2. Run the program:
   ```bash
   ./car_rental
   ```

---

## Usage

### Menu Options

The program provides the following menu options:
1. **Add a new car to the available list**:
   - Input: Number plate and mileage.
   - Adds the car to the "Available for Rent" list.

2. **Return a car to the available list**:
   - Input: Number plate and final mileage.
   - Processes the return and calculates the rental profit.

3. **Return a car to the repair list**:
   - Input: Number plate and final mileage.
   - Processes the return and moves the car to the repair list.

4. **Move a car from the repair list to the available list**:
   - Input: Number plate.
   - Transfers the car back to the available list.

5. **Rent the first available car**:
   - Input: Return date.
   - Rents the first car from the "Available for Rent" list.

6. **Print all lists**:
   - Displays the cars in all three categories.

7. **Quit**:
   - Saves the data to files and exits the program.

---

## Implementation Details

### Memory Management

- **Dynamic Memory Allocation**:
  - The `struct car` nodes are dynamically allocated using `malloc`.
  - The `free_list` function ensures proper deallocation to avoid memory leaks.

- **Error Handling**:
  - Checks for `NULL` pointers during memory allocation.
  - Gracefully handles file opening errors.

### Profit Calculation

- **Logic**:
  - Base charge: $80 for the first 200 km.
  - Additional charge: $0.15 per km beyond 200 km.
- **Implementation**:
  - `profit_calculator` function in `q1_functions.c`.
