#include <stdio.h>

int main() {
    printf("RSA Modulus Reuse Safety Check:\n\n");
    
    printf("Scenario: Reusing the same modulus n with a new key pair (e2, d2)\n\n");
    
    printf("Security Analysis:\n");
    printf("1. If the old private key (e1, d1) is compromised and the modulus n is reused:\n");
    printf("   - The old private key can still be used to decrypt messages intended for the new key.\n");
    printf("   - This allows an attacker to read messages encrypted with the new public key.\n\n");
    
    printf("2. Relationship between keys with same modulus:\n");
    printf("   - Both keys share the same prime factors p and q.\n");
    printf("   - If one private key is known, it can potentially help in factoring n.\n\n");
    
    printf("Conclusion: NO, it is NOT safe to reuse the modulus with a new key pair.\n");
    printf("A new key pair must use a completely new, independently generated modulus.\n");
    
    return 0;
}
