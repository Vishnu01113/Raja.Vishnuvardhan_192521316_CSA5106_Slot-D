#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int n = 33;  // n = p * q = 3 * 11
    int p = 3, q = 11;
    int plaintext = 6;  // shares factor 3 with n
    
    printf("RSA Factor Vulnerability:\n");
    printf("Modulus n = %d (p=%d, q=%d)\n", n, p, q);
    printf("Plaintext: %d\n", plaintext);
    printf("gcd(plaintext, n) = gcd(%d, %d) = %d\n", plaintext, n, gcd(plaintext, n));
    
    if (gcd(plaintext, n) > 1 && gcd(plaintext, n) < n) {
        printf("\nVulnerability Found!\n");
        printf("Factor of n revealed: %d\n", gcd(plaintext, n));
        printf("If plaintext shares a factor with n, the factor can be discovered.\n");
    } else {
        printf("\nNo vulnerability in this case.\n");
    }
    
    return 0;
}
