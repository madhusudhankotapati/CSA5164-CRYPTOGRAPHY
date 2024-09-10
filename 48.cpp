#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to encrypt a message using Caesar cipher
void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            text[i] = (c - base + shift) % 26 + base;
        }
    }
}

// Function to decrypt a message using Caesar cipher
void decrypt(char *text, int shift) {
    // To decrypt, use the negative shift
    encrypt(text, 26 - (shift % 26));
}

int main() {
    char text[] = "defend the east wall of the castle";
    int shift = 1;

    printf("Original message: %s\n", text);

    // Encrypt the message
    encrypt(text, shift);
    printf("Encrypted message: %s\n", text);

    // Decrypt the message
    decrypt(text, shift);
    printf("Decrypted message: %s\n", text);

    return 0;
}
