

#include <stdio.h>
#include <string.h>

void sender(char bit[], char stuffed[]) 
{
    int count = 0;
    int j = 0;
    
    for (int i = 0; bit[i] != '\0'; i++) 
    {
        stuffed[j++] = bit[i];
        if (bit[i] == '1') 
        {
            count++;
            if (count == 5) 
            {
                stuffed[j++] = '0';
                count = 0;
            }
        }
        else
            count = 0;
    }
    stuffed[j] = '\0';
}

void receiver(char stuffed[], char destuffed[]) 
{
    int count = 0;
    int j = 0;
    
    for (int i = 0; stuffed[i] != '\0'; i++) 
    {
        destuffed[j++] = stuffed[i];
        if (stuffed[i] == '1') 
        {
            count++;
            if (count == 5) 
            {
                if (stuffed[i + 1] == '0')
                    i++;
                count = 0;
            }
        } 
        else 
            count = 0;
    }
    destuffed[j] = '\0';
}

int main() {
    char bit[100], stuffed[200], destuffed[200];
    
    printf("Enter string: ");
    scanf("%s", bit);
    
    sender(bit, stuffed);
    printf("After stuffing: %s\n", stuffed);
    
    receiver(stuffed, destuffed);
    printf("After destuffing: %s\n", destuffed);
    
    return 0;
}

//output                                                                             
// Enter string: 110101111101011111101011111110
// After stuffing: 110101111100101111101010111110110
// After destuffing: 110101111101011111101011111110
