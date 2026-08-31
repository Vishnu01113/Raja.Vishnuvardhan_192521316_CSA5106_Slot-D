#include <stdio.h>

int gcd(int a, int b) {
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int modInverse(int a, int m) {
    for (int i = 1; i < m; i++) {
        if ((a * i) % m == 1) {
            return i;
        }
    }
    return -1;
}

char encryptChar(char p, int a, int b) {
    int pVal = p - 'A';
    int cVal = (a * pVal + b) % 26;
    return 'A' + cVal;
}

char decryptChar(char c, int a, int b) {
    int cVal = c - 'A';
    int aInv = modInverse(a, 26);
    int pVal = (aInv * (cVal - b + 26)) % 26;
    return 'A' + pVal;
}

int main() {
    int a = 2, b = 3;
    
    printf("Affine Cipher Implementation:\n\n");
    printf("Formula: E(x) = (ax + b) mod 26\n");
    printf("         D(x) = a^-1(y - b) mod 26\n\n");
    
    printf("Parameters: a=%d, b=%d\n", a, b);
    printf("Checking validity: gcd(a, 26) = gcd(%d, 26) = %d\n", a, gcd(a, 26));
    
    if (gcd(a, 26) != 1) {
        printf("ERROR: a must be coprime with 26!\n");
        return 1;
    }
    
    printf("Valid parameters (gcd = 1)\n\n");
    
    printf("Encryption table:\n");
    printf("Plaintext  | Ciphertext\n");
    printf("-----------|----------\n");
    for (int i = 0; i < 5; i++) {
        char p = 'A' + i;
        char c = encryptChar(p, a, b);
        printf("     %c     |     %c\n", p, c);
    }
    printf("    ...    |    ...\n");
    printf("\n");
    
    printf("Example encryption:\n");
    char plaintext[20] = "HELLO";
    char ciphertext[20];
    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: ");
    for (int i = 0; i < 5; i++) {
        ciphertext[i] = encryptChar(plaintext[i], a, b);
        printf("%c", ciphertext[i]);
    }
    ciphertext[5] = '\0';
    printf("\n\n");
    
    printf("Decryption:\n");
    int aInv = modInverse(a, 26);
    printf("a^-1 mod 26 = %d\n", aInv);
    printf("Ciphertext: %s\n", ciphertext);
    printf("Plaintext: ");
    for (int i = 0; i < 5; i++) {
        printf("%c", decryptChar(ciphertext[i], a, b));
    }
    printf("\n");
    
    return 0;
}
