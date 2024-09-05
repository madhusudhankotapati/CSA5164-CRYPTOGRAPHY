#include <stdio.h>
#include <ctype.h>  // For using the `toupper` and `tolower` functions

// Function to encrypt the text using Caesar cipher
void caesar_cipher(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];

        // Check if the character is an uppercase letter
        if (isupper(ch)) {
            text[i] = ((ch - 'A' + shift) % 26) + 'A';
        }
        // Check if the character is a lowercase letter
        else if (islower(ch)) {
            text[i] = ((ch - 'a' + shift) % 26) + 'a';
        }
        // Leave other characters unchanged (e.g., spaces, punctuation)
    }
}

int main() {
    char text[100];
    int shift;

    // Get user input for the plaintext and the shift value
    printf("Enter the text to encrypt: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter the shift value: ");
    scanf("%d", &shift);

    // Encrypt the text using the Caesar cipher
    caesar_cipher(text, shift);

    printf("Encrypted text: %s", text);

    return 0;
}
