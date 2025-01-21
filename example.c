// Signal handler function
// void handle_sigint(int sig) {
//     printf("3ndek signal %d (SIGINT). Exiting gracefully!\n", sig);
//     // Perform any cleanup if needed
//     _exit(0); // Exit the program
// }

// int main() {
//     // Set up the signal handler for SIGINT
//     if (signal(SIGINT, handle_sigint)) {
//         perror("Error setting up signal handler");
//         return 1;
//     }

//     printf("Press Ctrl+C to send SIGINT and trigger the handler...\n");

//     // Infinite loop to keep the program running
//     while (1) {
//         printf("Program is running...\n");
//         sleep(1); // Sleep for a second to reduce CPU usage
//     }

//     return 0;
// }



//=============================================================================

// Signal handler for SIGINT (Ctrl+C)
// void handle_sigint(int sig) {
//     printf("Caught signal %d (SIGINT). Exiting gracefully!\n", sig);
//     _exit(0); // Use _exit to exit immediately
// }

// int main() {
//     // Set up the signal handler for SIGINT
//     signal(SIGINT, handle_sigint);

//     printf("Press Ctrl+C to send SIGINT...\n");

//     while (1) {
//         printf("Waiting for a signal...\n");
//         pause(); // Suspends the program until a signal is received
//     }

//     return 0;
// }

//=============================================================================

// Signal handler for SIGUSR1
#include<signal.h>
#include<unistd.h>

void signal_handler(int signum)
{
    if (signum == SIGUSR1)
        write(1, "SIGUSR1\n", 9);  // Confirmation message
    else if (signum == SIGUSR2)
        write(1, "SIGUSR2\n", 9);  // If there's an error or some issue
	_exit(0);
}

#include<stdio.h>
int main()
{
	printf("SERVER PID %d\n", getpid());
    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);

    // Keep the process alive to receive signals
    while (1)
        pause();
    return 0;
}


