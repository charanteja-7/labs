

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork failed");
        return 1;
    }
    
    if (pid == 0) {

        printf("This is the child process. PID: %d\n", getpid());
    } else {

        printf("This is the parent process. PID: %d\n", getpid());
        wait(NULL);
    }
    
    return 0;
}


/*output

This is the parent process. PID: 19112
This is the child process. PID: 19113

*/
