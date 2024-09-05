#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to calculate modulo 26
int mod26(int x) {
    return (x % 26 + 26) % 26;
}

// Function to multiply key matrix with plaintext vector
void matrix_mult(int key[2][2], int plaintext[2], int ciphertext[2]) {
    ciphertext[0] = mod26(key[0][0] * plaintext[0] + key[0][1] * plaintext[1]);
    ciphertext[1] = mod26(key[1][0] * plaintext[0] + key[1][1] * plaintext[1]);
}

// Function to encrypt plaintext using Hill cipher
void hill_encrypt(const char *plaintext, const int key[2][2], char *ciphertext) {
    int len = strlen(plaintext);
    
    // Ensure input length is a multiple of 2, add padding if necessary
    if (len % 2 != 0) {
        printf("Plaintext length is not a multiple of 2, adding padding 'X'.\n");
        char padded_plaintext[101];
        strcpy(padded_plaintext, plaintext);
        strcat(padded_plaintext, "X"); // Add padding 'X'
        plaintext = padded_plaintext;
        len++;
    }

    // Encrypt plaintext
    for (int i = 0; i < len; i += 2) {
        int pt[2] = {toupper(plaintext[i]) - 'A', toupper(plaintext[i + 1]) - 'A'};
        int ct[2];
        matrix_mult(key, pt, ct);
        ciphertext[i] = ct[0] + 'A';
        ciphertext[i + 1] = ct[1] + 'A';
    }
    ciphertext[len] = '\0';
}

int main() {
    char plaintext[100], ciphertext[100];
    int key[2][2] = {{6, 24}, {1, 13}}; // Example key matrix (must be invertible modulo 26)

    printf("Enter plaintext (multiple of 2 length): ");
    scanf("%s", plaintext);

    hill_encrypt(plaintext, key, ciphertext);

    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
