#include <stdio.h>
#include <string.h>
void rail_fence_encrypt(const char *text, int rails, char *cipher) {
    int len = strlen(text), dir = 1, row = 0, k = 0;
    char rail[rails][len];
    memset(rail, '\n', sizeof(rail)); 
    for (int i = 0; i < len; i++) {
        rail[row][i] = text[i];
        if (row == 0) dir = 1;         
        else if (row == rails - 1) dir = -1; 
        row += dir;
    }
    for (int i = 0; i < rails; i++)   
        for (int j = 0; j < len; j++)
            if (rail[i][j] != '\n')
                cipher[k++] = rail[i][j];

    cipher[k] = '\0'; 
}
int main() {
    char text[100], cipher[100];
    int rails;
    printf("Enter plaintext: ");
    scanf("%[^\n]%*c", text);  
    printf("Enter number of rails: ");
    scanf("%d", &rails);
    rail_fence_encrypt(text, rails, cipher);
    printf("Ciphertext: %s\n", cipher);
    return 0;
}
