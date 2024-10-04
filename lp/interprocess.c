//user1.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>

#define BUFFERSIZE 256
int main(){
    char *path = "messages/message"; //this is the path to the file
    int fd;  //file descriptor
    mkfifo(path, 0666);   //mkfifo(<path>, <permission>);
    char arr1[BUFFERSIZE], arr2[BUFFERSIZE];

    while(1){
        fd = open(path, O_WRONLY);
        printf("user1 : ");
        fgets(arr1, BUFFERSIZE, stdin);
        write(fd, arr1, strlen(arr1)+1);
        close(fd);

        fd = open(path, O_RDONLY);
        read(fd, arr2, sizeof(arr2));
        printf("\nuser2 : %s\n",arr2);
        close(fd);
    }
    return 0;
} 


//user2
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>

#define BUFFERSIZE 256
int main(){
    char *path = "messages/message"; //this is the path to the file
    int fd;  //file descriptor
    mkfifo(path, 0666);   //mkfifo(<path>, <permission>);
    char arr1[BUFFERSIZE], arr2[BUFFERSIZE];

    while(1){
        fd = open(path, O_RDONLY);
        read(fd, arr2, sizeof(arr2));
        printf("\nuser1 : %s\n",arr2);
        close(fd);

        fd = open(path, O_WRONLY);
        printf("user2 : ");
        fgets(arr1, BUFFERSIZE, stdin);
        write(fd, arr1, strlen(arr1)+1);
        close(fd);
    }
    return 0;
}

//open two terminal and run the programs parallely to get desired output
