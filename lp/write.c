



#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc , char* argv[]){
	if(argc < 3 ){
		 printf("Usage: %s <filename> <text>\n", argv[0]);
       	return 1;
	}
	int fd = open(argv[1], O_WRONLY |  O_CREAT | O_APPEND);
	if(fd == -1){
		perror("Failed to open the file\n");
		return 1;
	}
	size_t len = strlen(argv[2]);
	ssize_t s = write(fd, argv[2] , len); 
	if(s == -1){
		perror("Failed to write\n");
		close(fd);
		return 1;
	}
	printf("<Content : %s> is written into <File : %s>\n", argv[2], argv[1]);
	close(fd);
	return 0;
}
