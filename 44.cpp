#include <stdio.h>
#include <stdint.h>
#include <string.h>

// Blowfish constants
#define N 16
#define P_ARRAY_SIZE (N + 2)
#define SBOX_SIZE 256

// P-array and S-boxes (normally, they would be initialized with values)
uint32_t P[P_ARRAY_SIZE] = {
    0x243F6A88, 0x85A308D3, 0x13198A2E, 0x03707344, 0xA4093822, 0x299F31D0, 0x082EFA98, 0xEC4E6C89,
    0x452821E6, 0x38D01377, 0xBE5466CF, 0x34E90C6C, 0xC0AC29B7, 0xC97C50DD, 0x3F84D5B5, 0xB5470917,
    0x9216D5D9, 0x8979FB1B
};
uint32_t S[4][SBOX_SIZE] = {
    // Normally, these would be initialized with values
};

// Function prototypes
void blowfish_key_expansion(const uint8_t* key, size_t key_len);
void blowfish_encrypt(uint32_t* left, uint32_t* right);
void blowfish_decrypt(uint32_t* left, uint32_t* right);

// Example S-box function (for demonstration purposes)
uint32_t F(uint32_t x) {
    return ((S[0][x >> 24] + S[1][(x >> 16) & 0xFF]) ^ S[2][(x >> 8) & 0xFF]) + S[3][x & 0xFF];
}

void blowfish_key_expansion(const uint8_t* key, size_t key_len) {
    size_t i, j, k;
    uint32_t data, datal, datar;

    j = 0;
    for (i = 0; i < P_ARRAY_SIZE; ++i) {
        data = 0x00000000;
        for (k = 0; k < 4; ++k) {
            data = (data << 8) | key[j];
            j = (j + 1) % key_len;
        }
        P[i] ^= data;
    }

    datal = 0x00000000;
    datar = 0x00000000;
    for (i = 0; i < P_ARRAY_SIZE; i += 2) {
        blowfish_encrypt(&datal, &datar);
        P[i] = datal;
        P[i + 1] = datar;
    }

    for (i = 0; i < 4; ++i) {
        for (j = 0; j < SBOX_SIZE; j += 2) {
            blowfish_encrypt(&datal, &datar);
            S[i][j] = datal;
            S[i][j + 1] = datar;
        }
    }
}

void blowfish_encrypt(uint32_t* left, uint32_t* right) {
    uint32_t L = *left;
    uint32_t R = *right;
    int i;

    for (i = 0; i < N; ++i) {
        L = L ^ P[i];
        R = F(L) ^ R;
        // Swap L and R
        uint32_t temp = L;
        L = R;
        R = temp;
    }

    // Undo the last swap
    uint32_t temp = L;
    L = R;
    R = temp;

    R = R ^ P[N];
    L = L ^ P[N + 1];

    *left = L;
    *right = R;
}

void blowfish_decrypt(uint32_t* left, uint32_t* right) {
    uint32_t L = *left;
    uint32_t R = *right;
    int i;

    for (i = N + 1; i > 1; --i) {
        L = L ^ P[i];
        R = F(L) ^ R;
        // Swap L and R
        uint32_t temp = L;
        L = R;
        R = temp;
    }

    // Undo the last swap
    uint32_t temp = L;
    L = R;
    R = temp;

    R = R ^ P[1];
    L = L ^ P[0];

    *left = L;
    *right = R;
}

int main() {
    // Example key
    uint8_t key[] = "examplekey";
    size_t key_len = strlen((char*)key);

    // Initialize key schedule
    blowfish_key_expansion(key, key_len);

    // Example plaintext
    uint32_t left = 0x01234567;
    uint32_t right = 0x89ABCDEF;

    printf("Plaintext: %08X %08X\n", left, right);

    // Encrypt
    blowfish_encrypt(&left, &right);
    printf("Ciphertext: %08X %08X\n", left, right);

    // Decrypt
    blowfish_decrypt(&left, &right);
    printf("Decrypted: %08X %08X\n", left, right);

    return 0;
}
