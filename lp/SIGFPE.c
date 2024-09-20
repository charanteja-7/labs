

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle_sigfpe(int sig){
    printf("caught SIGFPE  (Floating Point Exception), exiting..\n");
    exit(0);
}
int main(){
    signal(SIGFPE, handle_sigfpe);
    int a = 1;
    int b = 0;

    while (1) {
        printf("Calculating... (Dividing %d by %d)\n", a, b);
        a = a / b;  // This will cause a SIGFPE
        sleep(1);
    }
    return 0;
}

/*
            ......output......
            ..................
    Calculating... (Dividing 1 by 0)
    caught SIGFPE  (Floating Point Exception), exiting..



*/
