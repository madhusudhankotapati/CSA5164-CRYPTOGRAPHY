#include <stdio.h>
unsigned long long mod_exp(unsigned long long base, unsigned long long exp, unsigned long long mod) {
    unsigned long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;  
        base = (base * base) % mod;  
        exp /= 2;
    }
    return result;
}
int main() {
    unsigned long long n = 3233, e = 17, d = 2753;  
	    unsigned long long plaintext = 4; 

    unsigned long long ciphertext = mod_exp(plaintext, e, n); 
    printf("Encrypted: %llu\n", ciphertext);
    unsigned long long decrypted = mod_exp(ciphertext, d, n); 
    printf("Decrypted: %llu\n", decrypted);
    return 0;
}
