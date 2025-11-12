/**
 * File: signal_sigaction.c
 * Modified by: Zac Millmann
 * 
 * Brief summary of program: Creates a process that waits for a SIGUSR1 signal
 * It then prints out the pid of the proccess and the random value generated
 * 
 * To test:
 * Compile and run the program(gcc -o recv recv_signal.c, ./recv)
 */
#include <wait.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void sigusr1_handler(int sig, siginfo_t *info, void *context) {
    if (sig == SIGUSR1) {
        printf("Received SIGUSR1 from process with PID: %d\n", info->si_pid);
        printf("Value received: %d\n", info->si_value.sival_int);
    }
}

int main(void) {
    struct sigaction sa;

    //Setup signal action properties
    sigemptyset(&sa.sa_mask);
    sa.sa_sigaction = sigusr1_handler; 
    sa.sa_flags = SA_SIGINFO;          


    //verify that signal is sucessfully recieved
    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    //Print pid and provide status, also used to not need to search for pid when sending signal
    printf("Process PID: %d\n", getpid());
    printf("Waiting for SIGUSR1...\n");

    while (1) {
        pause(); 
    }

    return 0;
}
