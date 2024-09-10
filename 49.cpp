#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

// Function to analyze the frequency of characters
void analyze_frequency(const char *ciphertext, int *freq) {
    memset(freq, 0, ALPHABET_SIZE * sizeof(int));

    for (int i = 0; ciphertext[i] != '\0'; i++) {
        char c = tolower(ciphertext[i]);
        if (isalpha(c)) {
            freq[c - 'a']++;
        }
    }
}

// Function to decrypt the message using Caesar cipher
void decrypt(const char *ciphertext, int shift, char *plaintext) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        char c = tolower(ciphertext[i]);
        if (isalpha(c)) {
            char base = 'a';
            plaintext[i] = (c - base - shift + ALPHABET_SIZE) % ALPHABET_SIZE + base;
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[strlen(ciphertext)] = '\0'; // Null-terminate the decrypted message
}

int main() {
    const char *ciphertext = "cxknxawxccxkncqjcrbcqnzdnbcrxwfruurjvbqjtnbynjan";
    int freq[ALPHABET_SIZE];
    char plaintext[256];
    int max_freq = 0;
    int most_frequent_index = 0;

    // Analyze the frequency of characters
    analyze_frequency(ciphertext, freq);

    // Find the most frequent character
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
            most_frequent_index = i;
        }
    }

    // Assuming the most frequent character corresponds to 'e'
    int shift = (most_frequent_index - ('e' - 'a') + ALPHABET_SIZE) % ALPHABET_SIZE;

    // Decrypt the ciphertext
    decrypt(ciphertext, shift, plaintext);

    printf("Most frequent character: %c\n", 'a' + most_frequent_index);
    printf("Assumed shift: %d\n", shift);
    printf("Decrypted message: %s\n", plaintext);

    return 0;
}
