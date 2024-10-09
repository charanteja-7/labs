#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main(){
	char buff[1024];
	int shmid;
	void *shm_addr;
	shmid = shmget(1124, 1024, 0666);
	if(shmid == -1){
		printf("Error in reading shared memory");
		exit(1);
	}
	//attach the shared memory to address space
	shm_addr = shmat(shmid , NULL, 0);
	printf("content at shared memory is  %s ",(char * )shm_addr);
	shmdt(shm_addr);
	printf("\n");
	return 0;
}

//output
content at shared memory is  "this is the content"
