#include <stdio.h>
#include <string.h>
#include <ctype.h>
void vigenere_encrypt(const char *plaintext, const char *keyword, char *ciphertext) {
    int len_text = strlen(plaintext);
    int len_key = strlen(keyword);
    for (int i = 0, j = 0; i < len_text; i++) {
        char ch = toupper(plaintext[i]);  
        if (isalpha(ch)) {
            char key_char = toupper(keyword[j % len_key]) - 'A';  
            ciphertext[i] = ((ch - 'A' + key_char) % 26) + 'A';  
            j++;  
        } else {
            ciphertext[i] = ch;
        }
    }
    ciphertext[len_text] = '\0';
}
int main() {
    char plaintext[100], keyword[100], ciphertext[100];  
    printf("Enter the plaintext: ");
    scanf("%s", plaintext);
    printf("Enter the keyword: ");
    scanf("%s", keyword);    
    vigenere_encrypt(plaintext, keyword, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);
    return 0;
}