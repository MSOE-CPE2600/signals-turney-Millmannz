/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by:
 * 
 * Brief summary of modifications:
 */


#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void handle_signal(){
    printf("Segmentation fault received\n");
}

int main (int argc, char* argv[]) {
    // Declare a null pointer
    int* i = NULL;

    signal(SIGSEGV, handle_signal);

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}