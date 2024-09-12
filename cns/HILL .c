
#include <stdio.h>

#define SIZE 3

void getKeyMatrix(char key[], int keyMatrix[SIZE][SIZE]) {
    int k = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            keyMatrix[i][j] = (key[k] - 'A') % 26;
            k++;
        }
    }
}

void printMatrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void calculateAdjugate(int matrix[SIZE][SIZE], int adjugate[SIZE][SIZE]) {
    int minor[SIZE - 1][SIZE - 1];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int row = 0, col = 0;
            for (int k = 0; k < SIZE; k++) {
                if (k != i) {
                    col = 0;
                    for (int l = 0; l < SIZE; l++) {
                        if (l != j) {
                            minor[row][col] = matrix[k][l];
                            col++;
                        }
                    }
                    row++;
                }
            }
            int determinant = minor[0][0] * minor[1][1] - minor[0][1] * minor[1][0];
            adjugate[j][i] = ((i + j) % 2 == 0 ? 1 : -1) * determinant;
            adjugate[j][i] = (adjugate[j][i] % 26 + 26) % 26;  // Ensure positive values
        }
    }
}

int modInverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return 0;
}

void inverse(int keyMatrix[SIZE][SIZE], int inverseMatrix[SIZE][SIZE]) {
    int determinant = keyMatrix[0][0] * (keyMatrix[1][1] * keyMatrix[2][2] - keyMatrix[2][1] * keyMatrix[1][2])
                    - keyMatrix[0][1] * (keyMatrix[1][0] * keyMatrix[2][2] - keyMatrix[2][0] * keyMatrix[1][2])
                    + keyMatrix[0][2] * (keyMatrix[1][0] * keyMatrix[2][1] - keyMatrix[2][0] * keyMatrix[1][1]);

    determinant = (determinant % 26 + 26) % 26;
    int invDet = modInverse(determinant, 26);

    int adjugate[SIZE][SIZE];
    calculateAdjugate(keyMatrix, adjugate);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            inverseMatrix[i][j] = (adjugate[i][j] * invDet) % 26;
            inverseMatrix[i][j] = (inverseMatrix[i][j] + 26) % 26;  // Ensure positive values
        }
    }
}

void encrypt(int cipherMatrix[SIZE][1], int keyMatrix[SIZE][SIZE], int messageVector[SIZE][1]) {
    for (int i = 0; i < SIZE; i++) {
        cipherMatrix[i][0] = 0;
        for (int x = 0; x < SIZE; x++) {
            cipherMatrix[i][0] += keyMatrix[i][x] * messageVector[x][0];
        }
        cipherMatrix[i][0] = cipherMatrix[i][0] % 26;
    }
}

void decrypt(int messageMatrix[SIZE][1], int inverseMatrix[SIZE][SIZE], int cipherMatrix[SIZE][1]) {
    for (int i = 0; i < SIZE; i++) {
        messageMatrix[i][0] = 0;
        for (int x = 0; x < SIZE; x++) {
            messageMatrix[i][0] += inverseMatrix[i][x] * cipherMatrix[x][0];
        }
        messageMatrix[i][0] = (messageMatrix[i][0] % 26 + 26) % 26;  // Ensure positive values
    }
}

void HillCipher(char message[], char key[]) {
    int keyMatrix[SIZE][SIZE];
    getKeyMatrix(key, keyMatrix);

    int messageVector[SIZE][1];
    for (int i = 0; i < SIZE; i++) {
        messageVector[i][0] = (message[i] - 'A') % 26;
    }

    int cipherMatrix[SIZE][1];
    encrypt(cipherMatrix, keyMatrix, messageVector);

    printf("Ciphertext: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%c", (cipherMatrix[i][0] + 'A'));
    }
    printf("\n");

    int inverseMatrix[SIZE][SIZE];
    inverse(keyMatrix, inverseMatrix);

    int decryptedMessageMatrix[SIZE][1];
    decrypt(decryptedMessageMatrix, inverseMatrix, cipherMatrix);

    printf("Decrypted message: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%c", (decryptedMessageMatrix[i][0] + 'A'));
    }
    printf("\n");
}

int main() {
    char message[] = "ACT";
    char key[] = "GYBNQKURP";
    
    HillCipher(message, key);
    
    return 0;
}
