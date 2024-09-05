#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 5
void create_key_square(const char *keyword, char key_square[SIZE][SIZE]) {
    int letter_count[26] = {0};
    int k = 0;
    for (int i = 0; keyword[i] != '\0'; i++) {
        char ch = toupper(keyword[i]);
        if (ch == 'J') ch = 'I'; // Combine 'I' and 'J'
        if (!letter_count[ch - 'A']) {
            key_square[k / SIZE][k % SIZE] = ch;
            letter_count[ch - 'A'] = 1;
            k++;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (i + 'A' == 'J') continue; // Skip 'J'
        if (!letter_count[i]) {
            key_square[k / SIZE][k % SIZE] = 'A' + i;
            k++;
        }
    }
}
void format_plaintext(const char *plaintext, char formatted_text[]) {
    int len = 0;

    for (int i = 0; plaintext[i] != '\0'; i++) {
        char ch = toupper(plaintext[i]);
        if (ch == 'J') ch = 'I'; 
        if (isalpha(ch)) {
            if (len > 0 && formatted_text[len - 1] == ch) {
                formatted_text[len++] = 'X'; 
            }
            formatted_text[len++] = ch;
        }
    }
    if (len % 2 != 0) {
        formatted_text[len++] = 'X'; 
    }
    formatted_text[len] = '\0';
}
void find_position(char ch, char key_square[SIZE][SIZE], int *row, int *col) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (key_square[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}
void encrypt_digraph(char a, char b, char key_square[SIZE][SIZE], char *encrypted_pair) {
    int row_a, col_a, row_b, col_b;
    find_position(a, key_square, &row_a, &col_a);
    find_position(b, key_square, &row_b, &col_b);
    if (row_a == row_b) {
        encrypted_pair[0] = key_square[row_a][(col_a + 1) % SIZE];
        encrypted_pair[1] = key_square[row_b][(col_b + 1) % SIZE];
    } else if (col_a == col_b) {
        encrypted_pair[0] = key_square[(row_a + 1) % SIZE][col_a];
        encrypted_pair[1] = key_square[(row_b + 1) % SIZE][col_b];
    } else {
        encrypted_pair[0] = key_square[row_a][col_b];
        encrypted_pair[1] = key_square[row_b][col_a];
    }
}
void playfair_encrypt(const char *plaintext, const char *keyword, char *ciphertext) {
    char key_square[SIZE][SIZE];
    create_key_square(keyword, key_square);
    char formatted_text[100];
    format_plaintext(plaintext, formatted_text);
    for (int i = 0; formatted_text[i] != '\0'; i += 2) {
        encrypt_digraph(formatted_text[i], formatted_text[i + 1], key_square, &ciphertext[i]);
    }
    ciphertext[strlen(formatted_text)] = '\0';
}
int main() {
    char keyword[100], plaintext[100], ciphertext[100];
    printf("Enter the keyword: ");
    scanf("%s", keyword);
    printf("Enter the plaintext: ");
    scanf("%s", plaintext);
    playfair_encrypt(plaintext, keyword, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);
    return 0;
}
