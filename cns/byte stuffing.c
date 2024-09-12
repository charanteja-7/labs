

#include <stdio.h>
#include <string.h>

#define FLAG 'F'
#define ESC 'E'

void sender(const char input[], char stuffed[]) 
{
    int j = 0;
    
    for (int i = 0; input[i] != '\0'; i++) 
    {
        if (input[i] == FLAG || input[i] == ESC)
            stuffed[j++] = ESC;
        stuffed[j++] = input[i];
    }
   
    stuffed[j] = '\0';
}

void receiver(const char stuffed[], char destuffed[]) 
{
    int j = 0;

    for (int i = 0; stuffed[i] != '\0'; i++) 
    { 
        if (stuffed[i] == ESC){
            i++;
        
        }
        
        destuffed[j++] = stuffed[i];
    }

    destuffed[j] = '\0';
}

int main() {
    char input[100], stuffed[200], destuffed[200];

    printf("Enter Message: ");
    scanf("%s", input);

    sender(input, stuffed);
    printf("After Stuffing: %s\n", stuffed);

    receiver(stuffed, destuffed);
    printf("After Destuffing: %s\n", destuffed);

    return 0;
}
