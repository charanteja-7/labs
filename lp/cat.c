


#include <stdlib.h> // EXIT_FAILURE, exit(), EXIT_SUCCESS
#include <unistd.h> // STDOUT_FILENO, STDIN_FILENO, STDERR_FILENO, write(), ssize_t, read()
#include <fcntl.h>  // open(), O_RDONLY
#include <string.h> // strlen()


void display(char *filename){
	int fd = open(filename, O_RDONLY);
	
	char buffer[1024];
	ssize_t bytes_read;
	while((bytes_read = (read(fd, buffer, buffer_size)))>0){
		write(STDOUT_FILENO, buffer, bytes_read);
	}
	close(fd);
}

int main(int argc, char * argv[]){
	
	if(argc >1){
		for(int i = 1; i < argc ;i++){
			 display(argv[i]);
		}
	}else{
		
		char buffer[1024];
		ssize_t bytes_read;
		while((bytes_read = (read(STDIN_FILENO, buffer, buffer_size)))>0){
			write(STDOUT_FILENO, buffer, bytes_read);
		}
	}
	return 0;
}
