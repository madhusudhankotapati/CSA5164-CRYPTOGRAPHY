#include <stdio.h>
#include <stdint.h>
#include <string.h>
#define BLOCK_SIZE 8 
#define KEY_SIZE 8    
void initial_permutation(uint8_t* block);
void final_permutation(uint8_t* block);
void des_round(uint8_t* left, uint8_t* right, uint8_t* round_key);
void des_encrypt(uint8_t* plaintext, uint8_t* key, uint8_t* ciphertext);
void des_decrypt(uint8_t* ciphertext, uint8_t* key, uint8_t* plaintext);

int main() {
    uint8_t plaintext[BLOCK_SIZE] = { 'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o' };
    uint8_t key[KEY_SIZE] = { 0x13, 0x34, 0x57, 0x79, 0x9B, 0xBC, 0xDF, 0xF1 };
    uint8_t ciphertext[BLOCK_SIZE];
    uint8_t decryptedtext[BLOCK_SIZE];
    des_encrypt(plaintext, key, ciphertext);
    des_decrypt(ciphertext, key, decryptedtext);
    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02X ", ciphertext[i]);
    }
    printf("\nDecrypted: %s\n", decryptedtext);

    return 0;
}
void initial_permutation(uint8_t* block) {
}
void final_permutation(uint8_t* block) {
}

void des_round(uint8_t* left, uint8_t* right, uint8_t* round_key) {
}
void des_encrypt(uint8_t* plaintext, uint8_t* key, uint8_t* ciphertext) {
    uint8_t block[BLOCK_SIZE];
    memcpy(block, plaintext, BLOCK_SIZE);
    initial_permutation(block);
    uint8_t left[4], right[4];
    memcpy(left, block, 4);
    memcpy(right, block + 4, 4);
    for (int i = 0; i < 16; i++) {
        uint8_t round_key[6];  
        des_round(left, right, round_key);
        if (i < 15) {
            uint8_t temp[4];
            memcpy(temp, left, 4);
            memcpy(left, right, 4);
            memcpy(right, temp, 4);
        }
    }
    uint8_t pre_output[BLOCK_SIZE];
    memcpy(pre_output, left, 4);
    memcpy(pre_output + 4, right, 4);
    final_permutation(pre_output);
    memcpy(ciphertext, pre_output, BLOCK_SIZE);
}
void des_decrypt(uint8_t* ciphertext, uint8_t* key, uint8_t* plaintext) {
    uint8_t block[BLOCK_SIZE];
    memcpy(block, ciphertext, BLOCK_SIZE);
    initial_permutation(block);
    uint8_t left[4], right[4];
    memcpy(left, block, 4);
    memcpy(right, block + 4, 4);
    for (int i = 15; i >= 0; i--) {
        uint8_t round_key[6];  
        des_round(left, right, round_key);
        if (i > 0) {
            uint8_t temp[4];
            memcpy(temp, left, 4);
            memcpy(left, right, 4);
            memcpy(right, temp, 4);
        }
    }
    uint8_t pre_output[BLOCK_SIZE];
    memcpy(pre_output, left, 4);
    memcpy(pre_output + 4, right, 4);

    final_permutation(pre_output);
    memcpy(plaintext, pre_output, BLOCK_SIZE);
}
