/**
 * File: signal_sigaction.c
 * Modified by: Zac Millmann
 * 
 * Brief summary of program: Creates a process that waits for a SIGUSR1 signal and prints out the pid the signal is sent from
 * 
 * To test:
 * Compile and run the program(gcc -o sigaction signal_sigaction.c, ./sigaction)
 * In a seperate terminal run (kill -SIGUSR1 pid)
 */
#include <wait.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void sigusr1_handler(int sig, siginfo_t *info, void *context) {
    if (sig == SIGUSR1) {
        printf("Received SIGUSR1 from process with PID: %d\n", info->si_pid);
    }
}

int main(void) {
    struct sigaction sa;

    
    sigemptyset(&sa.sa_mask);
    sa.sa_sigaction = sigusr1_handler; 
    sa.sa_flags = SA_SIGINFO;          

    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    printf("Process PID: %d\n", getpid());
    printf("Waiting for SIGUSR1...\n");

    while (1) {
        pause(); 
    }

    return 0;
}
