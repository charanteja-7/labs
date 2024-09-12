      vernamcipher
        #include <stdio.h>
        #include <string.h>
        void encryption(char plaintext[], char ciphertext[], char key[]){
            int j = 0;
            for(int i = 0; plaintext[i] != '\0'; i++){
                int pi = plaintext[i] - 'a';
                int ki = key[i % strlen(key)] - 'a';
                int xor = pi^ki;
                ciphertext[j++] = (char)(xor + 'a');
            }
            ciphertext[j] = '\0';
        }
        void decryption(char ciphertext[], char decryptedtext[],char key[]){
            int j = 0;
            for(int i = 0; ciphertext[i] != '\0'; i++){
                int ci = ciphertext[i] - 'a';
                int ki = key[i % strlen(key)] - 'a';
                int xor = ci^ki;
            decryptedtext[j++] = (char)(xor + 'a');
            }
            decryptedtext[j] = '\0';
        }
        int main(){
            char ciphertext[100],plaintext[100],decryptedtext[100];
            char key[100] = "abcde"; 
            printf("Enter the plain text : ");
            scanf(" %s",plaintext);
            encryption(plaintext,ciphertext,key);
            printf("After encryption, Cipher text is : %s\n",ciphertext);
            decryption(ciphertext,decryptedtext,key);
            printf("After decryption, Plain text is : %s\n",decryptedtext);

        }

        // Enter the plain text : charantejachukkala
        // After encryption, Cipher text is : cgcsensgkecgwjoakc
        // After decryption, Plain text is : charantejachukkala
