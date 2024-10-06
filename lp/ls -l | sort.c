#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pipefd[2]; // Pipe file descriptors
    pid_t ls_pid, sort_pid;

    // Create the pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork the first child for 'ls -l'
    if ((ls_pid = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (ls_pid == 0) { // Child process for 'ls -l'
        // Close the unused read end of the pipe
        close(pipefd[0]);
        
        // Redirect stdout to the write end of the pipe
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]); // Close the original write end of the pipe

        // Execute 'ls -l'
        execlp("ls", "ls", "-l", NULL);
        perror("execlp ls"); // If execlp fails
        exit(EXIT_FAILURE);
    }

    // Fork the second child for 'sort'
    if ((sort_pid = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (sort_pid == 0) { // Child process for 'sort'
        // Close the unused write end of the pipe
        close(pipefd[1]);

        // Redirect stdin to the read end of the pipe
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]); // Close the original read end of the pipe

        // Execute 'sort'
        execlp("sort", "sort", NULL);
        perror("execlp sort"); // If execlp fails
        exit(EXIT_FAILURE);
    }

    // Parent process closes both ends of the pipe
    close(pipefd[0]);
    close(pipefd[1]);

    // Wait for both child processes to finish
    waitpid(ls_pid, NULL, 0);
    waitpid(sort_pid, NULL, 0);

    return 0;
}
