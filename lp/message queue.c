message queue

//sendMessage.c

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/msg.h>
#include<sys/types.h>
#include<sys/ipc.h>

struct my_msg{
    long int msg_type;
    char message[512];
};

int main(){

    int msgid;
    int running =1;
    char buffer[50];
    struct my_msg data;
    msgid = msgget((key_t)12345, 0666|IPC_CREAT);
    if(msgid == -1){
        printf("unable to create the queue");
        exit(1);
    }
    
    while(running){
        printf("Enter the message : ");
        fgets(buffer, 50, stdin);
        data.msg_type =1 ;
 
        strcpy(data.message , buffer);
        
        if(msgsnd(msgid, (void*)&data, 512, 0) == -1){
            printf("unable to add msg to queue");
            exit(1);
        }
        if(strncmp(buffer, "end", 3) == 0){
            running = 0;
        }
    }
    printf("\n");
    return 0;
    
}


//recieveMessage.c

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/msg.h>
#include<sys/types.h>
#include<sys/ipc.h>

struct my_msg{
    long int msg_type;
    char message[512];
};

int main(){

    int msgid;
    int running =1;
    long int msg_to_rec = 0;
    struct my_msg data;
    msgid = msgget((key_t)12345, 0666|IPC_CREAT);
    if(msgid == -1){
        printf("unable to create the queue");
        exit(1);
    }
    
    while(running){
        
        
        msgrcv(msgid, (void*)&data, 512,msg_to_rec, 0);
            printf("message recieved : %s", data.message);
        if(strncmp(data.message, "end", 3) == 0){
            running = 0;
        }
    }
    msgctl(msgid,IPC_RMID,0);  
    printf("\n");
    return 0;
    
}




////////////////////////
output

(base) cvr@cvr-H610M-H-DDR4:~/Desktop/1275$ gcc sendMessage.c
(base) cvr@cvr-H610M-H-DDR4:~/Desktop/1275$ ./a.out
Enter the message : linux
Enter the message : programming
Enter the message : lab
Enter the message : end

(base) cvr@cvr-H610M-H-DDR4:~/Desktop/1275$ gcc recieveMessage.c
(base) cvr@cvr-H610M-H-DDR4:~/Desktop/1275$ ./a.out
message recieved : linux
message recieved : programming
message recieved : lab
message recieved : end
