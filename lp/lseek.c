

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc , char* argv[]){
	if(argc < 2 ){
		 printf("Usage: %s <file1>\n", argv[0]);
       	return 1;
	}
	int fd = open(argv[1], O_RDONLY);
	
	if(fd == -1){
		perror("Failed to open the files\n");
		return 1;
	}
	
	char buffer[1024];
	lseek(fd , 5,SEEK_SET);
	read(fd , buffer,10);
	write(1, buffer ,10);
	close(fd);
	return 0;
}
