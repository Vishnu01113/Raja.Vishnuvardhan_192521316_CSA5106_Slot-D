#include <stdio.h>

// Left shift with wrapping (for 64-bit and 128-bit implementations)
unsigned long long leftShift(unsigned long long value, int bits) {
    return (value << 1) ^ ((value >> (bits - 1)) & 1 ? 0x87 : 0);
}

int main() {
    int blockSize64 = 64;
    int blockSize128 = 128;
    
    printf("CMAC (Cipher-based MAC) Subkey Derivation\n\n");
    
    // For 64-bit block cipher
    unsigned long long L64 = 0x1234567890ABCDEFULL;  // Example L value from E(K, 0^n)
    unsigned long long K64_1 = leftShift(L64, 64);
    unsigned long long K64_2 = leftShift(K64_1, 64);
    
    printf("For 64-bit block cipher:\n");
    printf("Block size: %d bits\n", blockSize64);
    printf("L (E_K(0^64)): 0x%016llX\n", L64);
    printf("K1 = L << 1 if MSB=0 else (L<<1) XOR 0x87: 0x%016llX\n", K64_1);
    printf("K2 = K1 << 1 if MSB=0 else (K1<<1) XOR 0x87: 0x%016llX\n", K64_2);
    printf("Constant used: 0x87\n\n");
    
    // For 128-bit block cipher
    unsigned long long L128 = 0x0123456789ABCDEFULL;  // Example L value
    unsigned long long K128_1 = leftShift(L128, 128);
    unsigned long long K128_2 = leftShift(K128_1, 128);
    
    printf("For 128-bit block cipher:\n");
    printf("Block size: %d bits\n", blockSize128);
    printf("L (E_K(0^128)): 0x%016llX\n", L128);
    printf("K1 = L << 1 if MSB=0 else (L<<1) XOR 0x87: 0x%016llX\n", K128_1);
    printf("K2 = K1 << 1 if MSB=0 else (K1<<1) XOR 0x87: 0x%016llX\n", K128_2);
    printf("Constant used: 0x87\n\n");
    
    printf("Key Points:\n");
    printf("1. Subkeys K1 and K2 derived from cipher key K\n");
    printf("2. L = E_K(0^n) where n is block size in bits\n");
    printf("3. K1 = L << 1 XOR Rb (where Rb = 0x87 for both 64 and 128 bit blocks)\n");
    printf("4. K2 = K1 << 1 XOR Rb\n");
    printf("5. Different from K to prevent message extension attacks\n");
    printf("\nCMAC subkeys use constants 0x87 for 64-bit blocks and 0x87 for 128-bit blocks.\n");
    
    return 0;
}
