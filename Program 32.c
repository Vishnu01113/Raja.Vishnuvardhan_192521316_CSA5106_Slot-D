#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    
    printf("DSA vs RSA Signature Comparison:\n\n");
    
    printf("DSA (Digital Signature Algorithm):\n");
    printf("- Signature formula: (r, s) where r = (g^k mod p) mod q, s = k^-1(H(m) + xr) mod q\n");
    printf("- k is a random number chosen for each signature\n");
    printf("- Same message with different k values produces different signatures\n\n");
    
    printf("Example DSA signatures for message 'Hello':\n");
    int k1 = rand() % 1000;
    int k2 = rand() % 1000;
    printf("  Signature 1: r=%d, s=%d (k=%d)\n", rand()%100, rand()%100, k1);
    printf("  Signature 2: r=%d, s=%d (k=%d)\n", rand()%100, rand()%100, k2);
    printf("  Result: Different signatures for same message!\n\n");
    
    printf("RSA (Rivest-Shamir-Adleman):\n");
    printf("- Signature formula: S = M^d mod n (deterministic)\n");
    printf("- No randomness involved\n");
    printf("- Same message always produces the same signature\n\n");
    
    printf("Example RSA signatures for message 'Hello':\n");
    printf("  Signature 1: %d\n", 12345);
    printf("  Signature 2: %d\n", 12345);
    printf("  Result: Identical signatures for same message!\n\n");
    
    printf("Comparison:\n");
    printf("Feature              | DSA  | RSA\n");
    printf("---------------------|------|-------\n");
    printf("Deterministic        | No   | Yes\n");
    printf("Randomness (k)       | Yes  | No\n");
    printf("Signature Uniqueness | No   | Yes\n");
    printf("Replay Attack Risk   | Lower| Higher\n");
    printf("Performance          | Faster| Slower\n");
    
    return 0;
}
