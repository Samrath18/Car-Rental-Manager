#include "q1.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
  struct car *available = NULL;
  struct car *rented = NULL;
  struct car *in_repair = NULL;

  int choice, mileage, return_date;
  char plate[7];
  double profit;

  // Load lists
  load_list_from_file(&available, "available.txt");
  load_list_from_file(&rented, "rented.txt");
  load_list_from_file(&in_repair, "repair.txt");

  do {
    prompt();
    scanf("%d", &choice);

    switch (choice) {
      // Add a new car to the available-for-rent list
      case 1:
        printf("Enter the number plate of the car and the mileage: ");
        scanf("%6s %d", plate, &mileage);  // Max 6 digits for number plate
        insert_to_list(&available, plate, mileage, -1);
        printf("Car has been added to the available for rent list.\n");
        break;

      // Add a returned car to the available-for-rent list
      case 2:
        printf("Enter the number plate of the car and the final mileage: ");
        scanf("%6s %d", plate, &mileage);
        if (is_plate_in_list(rented, plate)) {
          struct car *returned_car = remove_car_from_list(&rented, plate);
          profit = profit_calculator(returned_car->mileage, mileage);
          printf("Return had been processed. User charge = $%.2f\n", profit);
          insert_to_list(&available, plate, mileage, -1);
          free(returned_car);
        } else {
          printf("Car does not exist in the rented list.\n");
        }
        break;

      // Add a returned car to the in-repair list
      case 3:
        printf("Enter the number plate of the car and the final mileage: ");
        scanf("%6s %d", plate, &mileage);
        if (is_plate_in_list(rented, plate)) {
          struct car *returned_car = remove_car_from_list(&rented, plate);
          profit = profit_calculator(returned_car->mileage, mileage);
          printf("Return had been processed. User charge = $%.2f\n", profit);
          insert_to_list(&in_repair, plate, mileage, -1);
          free(returned_car);
        } else {
          printf("Car does not exist in the rented list.\n");
        }
        break;

      // Transfer a car from the in-repair list to the available-for-rent list
      case 4:
        printf("Enter the number plate of the car: ");
        scanf("%6s", plate);
        if (is_plate_in_list(in_repair, plate)) {
          struct car *repaired_car = remove_car_from_list(&in_repair, plate);
          insert_to_list(&available, plate, repaired_car->mileage, -1);
          free(repaired_car);
          printf(
              "Car has been transferred from repair list to available for rent "
              "list.\n");
        } else {
          printf("Car does not exist in repair list.\n");
        }
        break;

      // Rent the first available car
      case 5:
        printf("Return date for the car (yymmdd): ");
        scanf("%d", &return_date);
        if (available != NULL) {
          struct car *rented_car =
              remove_car_from_list(&available, available->plate);
          insert_to_list(&rented, rented_car->plate, rented_car->mileage,
                         return_date);
          free(rented_car);
          printf("Car has been rented with the return date: %d\n", return_date);
        } else {
          printf("No cars are available for rent.\n");
        }
        break;

      // Print all the lists
      case 6:
        printf("Cars available for rent:\n");
        print_list(available);
        printf("Cars rented:\n");
        print_list(rented);
        printf("Cars in repair:\n");
        print_list(in_repair);
        break;

      // Exit the program
      case 7:
        printf("Exiting\n");
        // Save the lists to files
        save_list_to_file(available, "available.txt");
        save_list_to_file(rented, "rented.txt");
        save_list_to_file(in_repair, "repair.txt");
        break;

      default:
        printf("Invalid choice. Please enter a valid number\n");
    }
  } while (choice != 7);

  // Free every list
  free_list(&available);
  free_list(&rented);
  free_list(&in_repair);

  return 0;
}
