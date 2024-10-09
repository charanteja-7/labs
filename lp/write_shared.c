


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
	//create a shared memory
	shmid = shmget(1124, 1024, 0666|IPC_CREAT);
	if(shmid == -1){
		printf("Error in creating shared memory");
		exit(1);
	}
	//attach the shared memory to address space
	shm_addr = shmat(shmid , NULL, 0);
	read(0, buff, 1024);
	strcpy(shm_addr, buff);
	printf("data written at %p  is %s ",shm_addr, (char * )shm_addr);
	shmdt(shm_addr);
	printf("\n");
	return 0;
}


//output
"this is the content"
data written at 0x7f1de71ed000  is "this is the content"
