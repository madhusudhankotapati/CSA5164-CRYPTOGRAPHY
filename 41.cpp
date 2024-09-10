#include <stdio.h>
int main() 
{
    char str[] = "Hello world";
    for (int i = 0; str[i] != '\0'; i++) {
        char xor_char = str[i] ^ 0;
        printf("%c", xor_char);
    }
    return 0;
}
