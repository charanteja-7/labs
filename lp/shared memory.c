shared memory

//writeShared.c

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/shm.h>


int main(){
    char buff[1000];
    int shmid;
    void *shm_addr;
    
    //create shared memory
    shmid = shmget((key_t)1124,1024,  0666|IPC_CREAT);
    
    if(shmid == -1){
        printf("unable to create shared memory");
        exit(1);
    }
    
    //attach shared memory to address space
    
    shm_addr = shmat(shmid, NULL, 0);
    
    //read user input

    printf("Enter data: ");
    fgets(buff, sizeof(buff), stdin);
    strcpy(shm_addr, buff);
    printf("Data written at %p is %s\n", shm_addr, (char *)shm_addr);
    
    //detach the memory
    shmdt(shm_addr);
    return 0;
}




//readShared.c

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/shm.h>


int main(){

    int shmid;
    void *shm_addr;
    
    //create or get shared memory
    shmid = shmget((key_t)1124, 1024, 0666|IPC_CREAT);
    
    if(shmid == -1){
        printf("unable to create shared memory");
        exit(1);
    }
    
    //attach shared memory to address space
    
    shm_addr = shmat(shmid, NULL, 0);
    
    //read the content at shared memory
     printf("Data written at %p is %s\n", shm_addr, (char *)shm_addr);
    shmdt(shm_addr);
    return 0;
}



//////////////
output



(base) cvr@cvr-H610M-H-DDR4:~/Desktop/1275$ gcc writeShared.c
(base) cvr@cvr-H610M-H-DDR4:~/Desktop/1275$ ./a.out
Enter data: linux programming
Data written at 0x7fb324069000 is linux programming

(base) cvr@cvr-H610M-H-DDR4:~/Desktop/1275$ gcc readShared.c
(base) cvr@cvr-H610M-H-DDR4:~/Desktop/1275$ ./a.out
Data written at 0x7f86a5302000 is linux programming

