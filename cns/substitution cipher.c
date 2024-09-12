
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 52

// Function to create a substitution table for encryption
void createSubstitutionTable(char table[], int key) {
    const char allLetters[ALPHABET_SIZE] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        table[i] = allLetters[(i + key) % ALPHABET_SIZE];
    }
}

// Function to create a reverse substitution table for decryption
void createReverseSubstitutionTable(char reverseTable[], int key) {
    const char allLetters[ALPHABET_SIZE] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        reverseTable[i] = allLetters[(i - key + ALPHABET_SIZE) % ALPHABET_SIZE];
    }
}

// Function to encrypt the plaintext
void encrypt(const char *plainText, const char table[], char *cipherText) {
    for (int i = 0; plainText[i] != '\0'; i++) {
        if (isalpha(plainText[i])) {
            int index = (plainText[i] >= 'a' && plainText[i] <= 'z') ? plainText[i] - 'a' : plainText[i] - 'A' + 26;
            cipherText[i] = table[index];
        } else {
            cipherText[i] = plainText[i];
        }
    }
    cipherText[strlen(plainText)] = '\0'; // Null-terminate the string
}

// Function to decrypt the ciphertext
void decrypt(const char *cipherText, const char reverseTable[], char *decryptedText) {
    for (int i = 0; cipherText[i] != '\0'; i++) {
        if (isalpha(cipherText[i])) {
            int index = (cipherText[i] >= 'a' && cipherText[i] <= 'z') ? cipherText[i] - 'a' : cipherText[i] - 'A' + 26;
            decryptedText[i] = reverseTable[index];
        } else {
            decryptedText[i] = cipherText[i];
        }
    }
    decryptedText[strlen(cipherText)] = '\0'; // Null-terminate the string
}

int main() {
    int key = 4; // Shift key for Caesar cipher
    const char *plainText = "I am studying Data Encryption";
    char cipherText[256];
    char decryptedText[256];
    char table[ALPHABET_SIZE];
    char reverseTable[ALPHABET_SIZE];

    // Create substitution tables
    createSubstitutionTable(table, key);
    createReverseSubstitutionTable(reverseTable, key);

    // Encrypt the plaintext
    encrypt(plainText, table, cipherText);
    printf("Cipher Text is: %s\n", cipherText);

    // Decrypt the ciphertext
    decrypt(cipherText, reverseTable, decryptedText);
    printf("Recovered plain text: %s\n", decryptedText);

    return 0;
}
