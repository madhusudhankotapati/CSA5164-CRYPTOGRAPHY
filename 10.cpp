#include <stdio.h>
unsigned long long gcd(unsigned long long a, unsigned long long b) {
    while (b != 0) {
        unsigned long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main() {
    unsigned long long n = 3233;
    unsigned long long e = 17;   
    unsigned long long known_plaintext = 61;
    unsigned long long p = gcd(known_plaintext, n);
    if (p > 1 && p < n) {
        unsigned long long q = n / p;
        printf("Factor found: p = %llu, q = %llu\n", p, q);
        unsigned long long phi_n = (p - 1) * (q - 1);
        unsigned long long d;
        for (d = 2; d < phi_n; d++) {
            if ((d * e) % phi_n == 1) {
                break;
            }
        }
        printf("Private key d = %llu\n", d);
    } else {
        printf("No common factor found.\n");
    }
    return 0;
}