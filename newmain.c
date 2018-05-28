/**
 * 
 * File:   problem2.c/problem2.txt
 * Author: James Grau
 * Date: May 25, 2018
 * Part 2
 * 
**/

// Include needed packages
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define constant input array max size
const int MAX_SIZE = 100;

// Method declaration
int isPrime(int);
int compareNumber(const void*, const void*);

/**
 * 
 * This method is used as the main area that runs the application
 * 
 * @return 0 on success
 * 
 **/
int main() {
    // Create needed variables
    char inputBuffer[MAX_SIZE];
    int inArr[MAX_SIZE], outArr[MAX_SIZE], entered = 0;
    
    // Display enter message
    printf("Please enter a list of integers: ");
    
    // Check and make sure that input is not null
    if(fgets(inputBuffer, sizeof(inputBuffer), stdin) != NULL) {
        // Declare the array pointer and processed character count
        char* arrayPointer = inputBuffer;
        int processedCharacters;
      
        // Check while the input returns successful
        while(sscanf(arrayPointer, "%d %n", &inArr[entered], &processedCharacters) == 1) {
            // Increment the entered counter
            entered++;
            
            // Increment the pointer by the amount of processed characters
            arrayPointer += processedCharacters;
        }
      
        // Check if the input is an empty string
        if (*arrayPointer != '\0') {
            // Display error message
            printf("Incorrect or empty input.");
            
            // Return -1 on errors
            return -1;
        }
    }
    
    // Initiate a count for entering in values for the outArr
    int counter = 0;
    
    // Loop through the entered array of integers and check if the value is prime or not
    for(int i = 0 ; i < entered; i++ ) {
        // Check if prime and add it into the outArr
       if (isPrime(inArr[i])) {
           // Add the prime number to the outArr
           outArr[counter] = inArr[i];
           
           // Increment the counter
           counter++;
       }
    }
    
    // Sort the outArr
    qsort(outArr, counter, sizeof(int), compareNumber);
    
    // Display prime sorted array message
    printf("Sorted prime numbers from the list: ");
    
    // Loop through the elements in the outArr and print them accordingly
    for(int i = 0 ; i < counter; i++ ) {
        // print the outArr value
        printf("%d ", outArr[i]);
    }    
    
    // Return 0 for success
    return 0;
}

/**
 * 
 * This function is used to take an int value and determine if it is a prime number
 * 
 * @param number: is the number to check if prime
 * @return [0 - false| 1 - true]
 * 
 * @note Adapted from: https://stackoverflow.com/questions/5281779/c-how-to-test-easily-if-it-is-prime-number
 * 
 */
int isPrime(int number) {
    //Check if passed number is less then 2 or is modulus of 2 and greater then 2
    if (number <= 1 || (number % 2 == 0 && number > 2)) return 0;
    
    // Iterate through disregarding for all even numbers
    // Start loop at 3 and increment by 2
    for(int i = 3; i < (number / 2); i+= 2) {
        // Check is number is a modulus of i and return false
        if (number % i == 0) return 0;
    }
    
    // Return 1 on success
    return 1;
}

/**
 * 
 * This method is used for comparing the two entered number
 * 
 * @param number1: is the first number to compare
 * @param number2: is the second number to compare
 * @return [-1 - number 1 is greater | 0 - equal | 1 - number 2 is greater]
 * 
 * @note - Adapted from http://devdocs.io/c/algorithm/qsort
 * 
 */
int compareNumber(const void* number1, const void* number2) {
    // Recast the passed parameters from void to int
    int number1 = *(const int*)number1;
    int number2 = *(const int*)number2;
 
    // Return compared number
    return (number1 > number2) - (number1 < number2); 
}