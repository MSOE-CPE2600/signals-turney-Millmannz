/**
 * File: send_signal.c
 * Modified by: Zac Millmann
 * 
 * Brief summary of program: Program accepts a pid as an inline command argument
 * and sends a signal with a random int value
 * 
 * Intended to send signal to recv_signal promram
 * 
 * To test:
 * Compile and run the program(gcc -o send send_signal.c, ./send <pid of ther process>)
 */
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if(argc != 2){
        printf("Please enter pid value");
        return 1;
    }

    srand(time(NULL));

    //Read pid from command line and generate random number to be sent
    pid_t pid = atoi(argv[1]);
    int val = rand();



    union sigval sv;
    sv.sival_int = val;
    
    //verify that signal is sucessfully sent
    if(sigqueue(pid, SIGUSR1, sv) == -1){
        perror("sigqueue");
        exit(EXIT_FAILURE);
    }

    printf("Sent value %d to process %d\n", val, pid);

    return 0;
}