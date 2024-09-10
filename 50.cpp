#include <stdio.h>
#include <string.h>

#define RAILS 3

// Function to encrypt the message using the Rail Fence Cipher
void rail_fence_encrypt(const char *message, int rails, char *encrypted) {
    int len = strlen(message);
    char fence[rails][len];
    memset(fence, ' ', sizeof(fence));

    int row = 0, direction = 1; // Direction for zigzag: 1 down, -1 up

    // Create the rail fence pattern
    for (int i = 0; i < len; i++) {
        fence[row][i] = message[i];
        if (row == 0 || row == rails - 1) {
            direction *= -1;
        }
        row += direction;
    }

    // Read the message from the rails
    int pos = 0;
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < len; j++) {
            if (fence[i][j] != ' ') {
                encrypted[pos++] = fence[i][j];
            }
        }
    }
    encrypted[pos] = '\0'; // Null-terminate the encrypted message
}

int main() {
    const char *message = "RAILFENCE";
    int rails = 3;
    char encrypted[256];

    rail_fence_encrypt(message, rails, encrypted);
    printf("Encrypted message: %s\n", encrypted);

    return 0;
}
