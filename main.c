/*
 * 
 * File:   main.c
 * Author: James Grau
 * Date: May 25, 2018
 * 
 */

// Include needed packages
#include <stdio.h>
#include <stdbool.h>

//const bool FALSE = false;
//const bool TRUE = true;
const int SIZE = 100;

void printLockerConfiguration(bool[]);

int main() {
    bool lockers[100] = {false};
    
    printLockerConfiguration(lockers);
    printf("\n");
    
    for(int i = 0; i < 3; i++) {
        for(int j = i; j < SIZE; j += i) {
            if(!lockers[j]) {
                lockers[j] = true;
            }else{
                lockers[j] = false;
            }
        }
        printLockerConfiguration(lockers);
        printf("\n");
    }
    
    return 0;
}

void printLockerConfiguration(bool lockers[]) {
    for(int i = 0; i < SIZE; i++) {
        printf("%d ", lockers[i]);
    }
}

