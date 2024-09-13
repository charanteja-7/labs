

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc , char* argv[]){
	if(argc < 3 ){
		 printf("Usage: %s <file1> <file2> \n", argv[0]);
       	return 1;
	}
	int fd1 = open(argv[1], O_RDONLY);
	int fd2 = open(argv[2], O_WRONLY | O_CREAT, 0644);
	if(fd1 == -1 || fd2 == -1){
		perror("Failed to open the files\n");
		return 1;
	}
	
	char buffer[1024];
	while(read(fd1, buffer, 100) > 0){
		write(fd2, buffer, strlen(buffer));
	}
	close(fd1);
	close(fd2);
	unlink(argv[1]);
	return 0;
}
