
//take the input text, key to encrypt and decrypt
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void encrypt(char plainText[],int key){
    for(int i =0;plainText[i] != '\0';i++){
        char c = plainText[i];
        if(isalpha(c)){
            if(isupper(c)){
                c = 'A' + (c-'A'+key)%26;
            }else{
                c = 'a' + (c-'a'+key)%26;
            }
        }
        plainText[i] = c;
    }
}
void decrypt(char cipherText[],int key){
     for(int i =0;cipherText[i] != '\0';i++){
        char c = cipherText[i];
        if(isalpha(c)){
            if(isupper(c)){
                int val = (c-'A'-key)%26;
                if(val < 0) c = 'A'+val+26;
                else c = 'A' + val;
            }else{
               int val = (c-'a'-key)%26;
                if(val < 0) c = 'a'+val+26;
                else c = 'a' + val;
            }
        }
        cipherText[i] = c;
    }
}
int main(){
    char plainText[100];
    printf("Enter the plain text : ");
    scanf(" %s",plainText);
    int key;
    printf("Enter the key : ");
    scanf(" %d",&key);
    //plain text will be converted to cipher text
    encrypt(plainText, key);
    printf("\nAfter encryption (ciphertext is) : %s\n",plainText);
    //cipher text will be converted back to plaintext
    decrypt(plainText,key);
    printf("After Decryption (plaintext is) : %s\n",plainText);
}   
