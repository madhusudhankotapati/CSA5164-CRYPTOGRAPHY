#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void encrypt(char *plaintext, int key) {
    int len = strlen(plaintext);
    int rows = (len + key - 1) / key;  
    char matrix[rows][key];
    memset(matrix, 0, sizeof(matrix));  
    for (int i = 0; i < len; i++) {
        matrix[i / key][i % key] = plaintext[i];
    }
    printf("Ciphertext: ");
    for (int col = 0; col < key; col++) {
        for (int row = 0; row < rows; row++) {
            if (matrix[row][col] != 0) {
                printf("%c", matrix[row][col]);
            }
        }
    }
    printf("\n");
}
void decrypt(char *ciphertext, int key) {
    int len = strlen(ciphertext);
    int rows = (len + key - 1) / key;  
    char matrix[rows][key];
    memset(matrix, 0, sizeof(matrix));  
    int index = 0;
    for (int col = 0; col < key; col++) {
        for (int row = 0; row < rows; row++) {
            if (index < len) {
                matrix[row][col] = ciphertext[index++];
            }
        }
    }
    printf("Plaintext: ");
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < key; col++) {
            if (matrix[row][col] != 0) {
                printf("%c", matrix[row][col]);
            }
        }
    }
    printf("\n");
}
int main() {
    char plaintext[] = "HELLO WORLD";
    int key = 4;
    printf("Original plaintext: %s\n", plaintext);
    encrypt(plaintext, key);
    char ciphertext[] = "HWEOLLRLOD";
    printf("Ciphertext to decrypt: %s\n", ciphertext);
    decrypt(ciphertext, key);
    return 0;
}
