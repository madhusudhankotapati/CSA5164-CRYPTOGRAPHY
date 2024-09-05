#include <stdio.h>
#include <string.h>

void row_columnar_encrypt(const char *text, int key, char *cipher) {
    int len = strlen(text), rows = (len + key - 1) / key, k = 0;
    for (int col = 0; col < key; col++)          
        for (int row = 0; row < rows; row++) {
            int idx = row * key + col;
            cipher[k++] = (idx < len) ? text[idx] : 'X';  
			    }
    cipher[k] = '\0';  
}
int main() {
    char text[100], cipher[100];
    int key;
    printf("Enter plaintext: ");
    scanf("%s", text);
    printf("Enter number of columns (key): ");
    scanf("%d", &key);
    row_columnar_encrypt(text, key, cipher);
    printf("Ciphertext: %s\n", cipher);
    return 0;
}
