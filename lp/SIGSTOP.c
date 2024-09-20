#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main() {
    printf("Running... (Send SIGSTOP using `kill -STOP <pid>`)\n");
    while (1) {
         printf("Still running... (PID: %d) (Press Ctrl+C to stop)\n", getpid());
        sleep(1);
    }
    return 0;
}

//use another terminal to stop this process using the pid
//kill -STOP <pid>
