#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        printf("Child process (PID: %d) exiting.\n", getpid());
        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        int status;
        pid_t terminated_pid = wait(&status); // Wait for child process to terminate
        if (terminated_pid == -1) {
            perror("wait");
            exit(EXIT_FAILURE);
        }
        printf("Parent process (PID: %d) reaped child process (PID: %d).\n", getpid(), terminated_pid);
    }

    return 0;
}
//output
//Child process (PID: 26927) exiting.
//Parent process (PID: 26926) reaped child process (PID: 26927).
