


#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]){
     
     if(argc < 2){
     	printf("usage -> ./a.out <filename>");
     	return 1;
     }
     
     if(unlink(argv[1] == 0){
     	printf("%s removed successfully", argv[1]);
     	return 0;
     }else{
     	printf("unable to remove the file");
     	return 1;
     }
     return 0;
}
