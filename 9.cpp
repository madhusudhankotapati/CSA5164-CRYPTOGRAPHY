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
 
    unsigned long long p = 61, q = 53;  
    unsigned long long n = p * q;       
    unsigned long long phi = (p - 1) * (q - 1);     
    unsigned long long e = 17;           
    unsigned long long d = 2753;         
    unsigned long long plaintext = 42;   
    unsigned long long ciphertext = mod_exp(plaintext, e, n);
    printf("Encrypted: %llu\n", ciphertext);
    unsigned long long decrypted = mod_exp(ciphertext, d, n);
    printf("Decrypted: %llu\n", decrypted);
    unsigned long long e_new = 7;     
    unsigned long long d_new = 1783;  
    // Encrypt with the new public key
    unsigned long long new_ciphertext = mod_exp(plaintext, e_new, n);
    printf("New Encrypted: %llu\n", new_ciphertext);

    // Decrypt with the new private key
    unsigned long long new_decrypted = mod_exp(new_ciphertext, d_new, n);
    printf("New Decrypted: %llu\n", new_decrypted);

    return 0;
}
