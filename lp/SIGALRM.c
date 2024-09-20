
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>

bool alarm_flag = false;

void handle_sigalrm(int sig) {
    alarm_flag = true;  
}

void my_sleep(int seconds) {
    signal(SIGALRM, handle_sigalrm); 
    alarm(seconds);                   
    while (!alarm_flag) {
        pause(); 
    }
    alarm(0);
}

int main() {
    printf("Sleeping for 5 seconds...\n");
    my_sleep(5);
    printf("Awake!\n");
    return 0;
}

/* output
Sleeping for 5 seconds...
Awake!
*/
