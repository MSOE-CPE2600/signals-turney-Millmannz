/**
 * File: signal_alarm.c
 * Modified by: Zac Millmann
 * 
 * Brief summary of program: Program sends alarm signal and waits until signal is received
 */
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <wait.h>


void handle_signal() {
    printf("Received signal\n");
    exit(1);
}

int main() {

    // Register for the signal
    signal(SIGALRM, handle_signal);

    //Send alarm signal
    alarm(5);


    // Wait until a signal is received
    while(1) {
        printf("Sleeping\n");
        sleep(1);
    }

    return 0;
}