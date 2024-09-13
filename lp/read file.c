

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc , char* argv[]){
	if(argc < 2 ){
		 printf("Usage: %s <filename>\n", argv[0]);
       	return 1;
	}
	int fd = open(argv[1], O_RDONLY);
	if(fd == -1){
		perror("Failed to open the file\n");
		return 1;
	}
	
	char buffer[1024];
	ssize_t s = read(fd, buffer, 100); //read at max 100 characters
	if(s == -1){
		perror("Failed to read\n");
		close(fd);
		return 1;
	}
	//write on to console using system call
	write(1, buffer, strlen(buffer)); //strlen to print only the required length of the string
	close(fd);
	return 0;
}
