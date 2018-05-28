/**
 * 
 * File:   problem1.c/problem2.txt
 * Author: James Grau
 * Date: May 25, 2018
 * Part 1
 * 
**/

// Include needed packages
#include <stdio.h>
#include <stdbool.h>

// Define a constant to hold the number of students
const int SIZE = 100;

// Method declaration
void printLockerConfiguration(bool[]);

/**
 * 
 * This method is used as the main area that runs the application
 * 
 * @return 0 on success
 * 
 **/
int main() {
    // Declare the needed array and initialize each value to 0 (false)
    bool lockers[100] = {false};
    
    // Loop through the amount of students in as defined in the SIZE constant
    for(int i = 1; i <= SIZE; i++) { // Student Array
        // Loop through each locker for the students and perform the open/close toggle
        // j = the current student - 1 -- to point to the correct array element
        // j += i -- increments by the current student  for the correct offset
        for(int j = (i - 1); j < SIZE; j += i) { // Locker Array Starts at the current student
            // Take the current lock and XOR the value swapping if it is true/false
            lockers[j] ^= true;
        }    
    }
    
    // After the lockers have been dealt with, display the current locker configuration
    printLockerConfiguration(lockers);
    
    // Return 0 for success
    return 0;
}

/**
 * 
 * This method is used to take the bool array and display the locker configuration
 * 
 * @param lockers: is the bool array of lockers
 * 
 **/
void printLockerConfiguration(bool lockers[]) {
    // Display the line stating message
    printf("Open lockers: ");
        
    // Loop through each locker array element
    for(int i = 0; i < SIZE; i++) {
        // If the current locker is open(true) perform the following
        if(lockers[i]) {
            // If the locker (i) pointer is == 99, don't print the extra ',' at the end of the line, else, print the locker number with the comma
            (i == 99) ? printf("%d", (i + 1)) : printf("%d, ", (i + 1)) ;
        }
    }
}