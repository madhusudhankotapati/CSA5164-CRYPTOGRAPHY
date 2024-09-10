#include <stdio.h>
int main() {
    char str[] = "Hello world";
    printf("Original string: %s\n", str);
    printf("String after AND with 127: ");
    for (int i = 0; str[i] != '\0'; i++) {
        char and_char = str[i] & 127;
        printf("%c", and_char);
    }
    printf("\n");
    printf("String after XOR with 127: ");
    for (int i = 0; str[i] != '\0'; i++) {
        char xor_char = str[i] ^ 127;
        printf("%c", xor_char);
    }
    printf("\n");
    return 0;
}
