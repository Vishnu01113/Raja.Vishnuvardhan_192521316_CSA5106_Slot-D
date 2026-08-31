#include <stdio.h>

int main() {
    printf("SHA-3 Sponge Construction - Capacity Analysis:\n\n");
    
    printf("SHA-3 Parameters (using 1024-bit output example):\n");
    printf("- Keccak state size: 1600 bits\n");
    printf("- Rate (r): 576 bits (for SHA3-256)\n");
    printf("- Capacity (c): 1024 bits (for SHA3-256)\n\n");
    
    printf("Capacity Portion (c = 1024 bits):\n");
    printf("- Initially: All capacity lanes are set to 0\n");
    printf("- During absorption: Input is XORed into the rate portion (first 576 bits)\n");
    printf("- Capacity lanes are NOT directly modified during absorption\n\n");
    
    printf("Key observations:\n");
    printf("1. The capacity portion starts as zeros before any absorption.\n");
    printf("2. During permutation (Keccak-f), the capacity is mixed with rate bits.\n");
    printf("3. After permutation rounds, capacity becomes nonzero through diffusion.\n");
    printf("4. The capacity ensures security: even if all rate bits are known, capacity remains secret.\n\n");
    
    printf("Security implication:\n");
    printf("The capacity (1024 bits) provides collision resistance of 2^512 for SHA3-256.\n");
    printf("An attacker would need to find 2^512 messages to find a collision.\n");
    
    return 0;
}
