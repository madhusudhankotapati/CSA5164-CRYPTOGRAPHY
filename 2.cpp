#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_LEN 100
void encrypt(const char *plaintext, char *ciphertext, const char *key) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            int is_upper = isupper(plaintext[i]);
            int index = tolower(plaintext[i]) - 'a';
            ciphertext[i] = is_upper ? toupper(key[index]) : key[index];
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
}
int main() {
    char plaintext[MAX_LEN], ciphertext[MAX_LEN];
    const char *key = "QWERTYUIOPASDFGHJKLZXCVBNM";
    printf("Enter plaintext: ");
    fgets(plaintext, MAX_LEN, stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';
    encrypt(plaintext, ciphertext, key);
    printf("Ciphertext: %s\n", ciphertext);
    return 0;
}
