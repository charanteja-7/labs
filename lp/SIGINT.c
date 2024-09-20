SIGINT

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle_sigint(int sig){
    printf("caught SIGINT , exiting..\n");
    exit(0);
}
int main(){
    //register the signal
    signal(SIGINT,handle_sigint);
    while(1){
        printf("running (press ctrl+c to stop\n");
    }
    return 0;
}

/*
            ......output......
            ..................
    running (press ctrl+c to stop
    running (press ctrl+c to stop
    running (press ctrl+c to stop
    running (press ctrl+c to stop
    running (press ctrl+c to stop
    running (press ctrl+c to stop
    running (press ctrl+c to stop
    run^Crunning (press ctrl+c to stop
    caught SIGINT , exiting..

*/
