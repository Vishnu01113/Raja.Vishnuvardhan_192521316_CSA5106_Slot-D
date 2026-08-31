#include <stdio.h>
#include <string.h>

int main() {
    printf("CBC-MAC Extension Attack Demonstration:\n\n");
    
    printf("Scenario:\n");
    printf("- Alice sends a one-block message M1 with CBC-MAC tag T1\n");
    printf("- Eve intercepts both M1 and T1\n\n");
    
    printf("Attack Steps:\n");
    printf("1. Eve has: M1 (plaintext), T1 (MAC tag)\n");
    printf("   CBC-MAC computation: T1 = E(K, M1 IV) if IV=0, then T1 = E(K, M1)\n\n");
    
    printf("2. Eve creates a new message M2 = M1 || M2_extra (extending with extra block)\n");
    printf("   Without knowing K, Eve can choose M2_extra such that:\n");
    printf("   - T2 = E(K, T1 XOR M2_extra) becomes the new tag\n\n");
    
    printf("3. Eve computes: T2_guessed = E(K, T1 XOR M2_extra) = E(K, T1 XOR M2_extra)\n");
    printf("   This transforms the old message into a new valid message!\n\n");
    
    printf("Why this works:\n");
    printf("- CBC-MAC is not prefix-free, so extension is possible\n");
    printf("- Knowing (M1, T1) is sufficient to forge (M1 || M2_extra, T2) for any M2_extra\n\n");
    
    printf("Mitigation:\n");
    printf("- Use CMAC or HMAC instead of raw CBC-MAC\n");
    printf("- Apply final encryption after CBC-MAC: T = E(K2, CBC_MAC(K1, M))\n");
    printf("- Use authenticated encryption modes (GCM, ChaCha20-Poly1305)\n");
    
    return 0;
}
