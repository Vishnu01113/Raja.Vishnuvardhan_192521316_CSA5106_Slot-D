#include <stdio.h>

long int power(long int base, long int exp, long int mod) {
    long int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    long int p = 23;  // Prime number
    long int g = 5;   // Primitive root of p
    
    long int x = 6;   // Alice's private key
    long int y = 15;  // Bob's private key
    
    printf("Diffie-Hellman Key Exchange Implementation:\n\n");
    printf("Public parameters: p = %ld, g = %ld\n\n", p, g);
    
    long int A = power(g, x, p);
    long int B = power(g, y, p);
    
    printf("Alice's side:\n");
    printf("  Private key (x) = %ld\n", x);
    printf("  Public key (A) = g^x mod p = %ld^%ld mod %ld = %ld\n", g, x, p, A);
    
    printf("\nBob's side:\n");
    printf("  Private key (y) = %ld\n", y);
    printf("  Public key (B) = g^y mod p = %ld^%ld mod %ld = %ld\n", g, y, p, B);
    
    long int secretA = power(B, x, p);
    long int secretB = power(A, y, p);
    
    printf("\nShared Secret Calculation:\n");
    printf("  Alice computes: B^x mod p = %ld^%ld mod %ld = %ld\n", B, x, p, secretA);
    printf("  Bob computes: A^y mod p = %ld^%ld mod %ld = %ld\n", A, y, p, secretB);
    
    printf("\nShared Secret: %ld\n", secretA);
    printf("Secrets match: %s\n", (secretA == secretB) ? "YES" : "NO");
    
    return 0;
}
