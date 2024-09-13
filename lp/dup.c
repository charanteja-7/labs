

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("example.txt", O_RDWR | O_CREAT, 0644); 
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    int new_fd = dup(fd); 
    if (new_fd == -1) {
        perror("Error duplicating file descriptor");
        close(fd);
        return 1;
    }

    write(new_fd, "Hello, world!", 13);
    close(fd);
    close(new_fd);
    
    return 0;
}
