

#include <stdio.h>
#include<unistd.h>
#include <string.h>
#include <fcntl.h>

int main(int argc,char *argv[]){
	int fd = open(argv[1],O_RDONLY);
	if(fd == -1){
	 printf("unable to open the file");
	 return 0;
	}
	int wc = 0;
	int cc = 0;
	int lc = 0;
	char *buffer;
	ssize_t bytesread;
	while((bytesread = read(fd, buffer, 1)) > 0){
		   if(*buffer =='\n'){
			   lc++;
			   wc++;
			   
		   }
		   if(*buffer == ' '){
			   wc++;   
		   }
		  cc++;
		
	}
	printf("word count: %d\n",wc);
	printf("character count: %d\n",cc);
	printf("line count: %d\n",lc);
	close(fd);
	printf("\n");
	return 0;
}
