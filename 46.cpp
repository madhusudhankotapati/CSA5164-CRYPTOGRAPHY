#include <stdio.h>
#include <string.h>
#include <openssl/aes.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 16

void encrypt(AES_KEY *key, unsigned char *input, unsigned char *output) {
    AES_encrypt(input, output, key);
}

void decrypt(AES_KEY *key, unsigned char *input, unsigned char *output) {
    AES_decrypt(input, output, key);
}

int main() {
    unsigned char key[KEY_SIZE] = "mysecretkey123";
    unsigned char input[] = "welcome to CSE";
    unsigned char encrypted[BLOCK_SIZE];
    unsigned char decrypted[BLOCK_SIZE];

    AES_KEY aes_key;
    AES_set_encrypt_key(key, KEY_SIZE * 8, &aes_key);

    encrypt(&aes_key, input, encrypted);
    printf("Encrypted: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02x", encrypted[i]);
    }
    printf("\n");

    AES_set_decrypt_key(key, KEY_SIZE * 8, &aes_key);
    decrypt(&aes_key, encrypted, decrypted);
    printf("Decrypted: %s\n", decrypted);

    return 0;
}
