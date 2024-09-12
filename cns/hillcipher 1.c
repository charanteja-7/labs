

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 3

void multiplyMatrixVector(int matrix[SIZE][SIZE], int vector[SIZE], int result[SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        result[i] = 0;
        for (int j = 0; j < SIZE; ++j) {
            result[i] += matrix[i][j] * vector[j];
        }
        result[i] %= 26;
    }
}

void encrypt(int matrix[SIZE][SIZE], char *plaintext, char *ciphertext) {
    int length = strlen(plaintext);
    for (int i = 0; i < length; i += SIZE) {
        int vector[SIZE];
        for (int j = 0; j < SIZE; ++j) {
            if (i + j < length) {
                vector[j] = plaintext[i + j] - 'A';
            } else {
                vector[j] = 0;  
            }
        }
        int result[SIZE];
        multiplyMatrixVector(matrix, vector, result);
        for (int j = 0; j < SIZE; ++j) {
            ciphertext[i + j] = result[j] + 'A';
        }
    }
    ciphertext[length] = '\0';
}

void decrypt(int matrix[SIZE][SIZE], int invMatrix[SIZE][SIZE], char *ciphertext, char *plaintext) {
    int length = strlen(ciphertext);
    for (int i = 0; i < length; i += SIZE) {
        int vector[SIZE];
        for (int j = 0; j < SIZE; ++j) {
            vector[j] = ciphertext[i + j] - 'A';
        }
        int result[SIZE];
        multiplyMatrixVector(invMatrix, vector, result);
        for (int j = 0; j < SIZE; ++j) {
            plaintext[i + j] = result[j] + 'A';
        }
    }
    plaintext[length] = '\0';
}

int main() {
    int keyMatrix[SIZE][SIZE] = {
        {6, 24, 1},
        {13,16,10},
        {20,17,15}
    };

    int invMatrix[SIZE][SIZE] = {
        {8,5,10},
        {21,8,21},
        {21,12,8}
    };
    
    char* plaintext = (char*)malloc(SIZE*sizeof(char));
    printf("Enter the message : ");
    scanf("%s",plaintext);
    char ciphertext[sizeof(plaintext)];
    char decryptedtext[sizeof(plaintext)];

    encrypt(keyMatrix, plaintext, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);

    decrypt(keyMatrix, invMatrix, ciphertext, decryptedtext);
    printf("Decrypted text: %s\n", decryptedtext);

    return 0;
}
