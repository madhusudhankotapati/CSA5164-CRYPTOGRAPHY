#include <stdio.h>
unsigned long long extended_gcd(unsigned long long a, unsigned long long b, long long *x, long long *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    long long x1, y1;
    unsigned long long gcd = extended_gcd(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (a / b) * y1;

    return gcd;
}
unsigned long long find_multiplicative_inverse(unsigned long long e, unsigned long long phi_n) {
    long long x, y;
    unsigned long long gcd = extended_gcd(e, phi_n, &x, &y);
    if (gcd != 1) {
        printf("Multiplicative inverse doesn't exist.\n");
        return 0;
    } else {
        return (x % phi_n + phi_n) % phi_n;
    }
}
int main() {
    unsigned long long e = 31;        
    unsigned long long n = 3599;      
    unsigned long long p = 59, q = 61; 
    unsigned long long phi_n = (p - 1) * (q - 1); // phi(n) = (59-1) * (61-1) = 3480
    unsigned long long d = find_multiplicative_inverse(e, phi_n);
    printf("The private key d is: %llu\n", d);
    return 0;
}