

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = vfork();
    printf("%d\n",pid);
    if (pid < 0) {
        perror("vfork failed");
        return 1;
    }
    
    if (pid == 0) {

        printf("This is the child process. PID: %d\n", getpid());
        execlp("ls", "ls", NULL); 
        perror("execlp failed");  
        _exit(1); 
    } else {

        printf("This is the parent process. PID: %d\n", getpid());
        wait(NULL); 
    }
    
    return 0;
}

/*output

This is the child process. PID: 19204
This is the parent process. PID: 19203
a.out  dup2.c  dup.c  example.txt  fork.c  output.txt  vfork.c

*/
