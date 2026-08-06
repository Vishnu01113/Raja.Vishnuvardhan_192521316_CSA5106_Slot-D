#include <stdio.h>

int main() {
    int a = 2, b = 3;
    int p = 0;
    int c = (a * p + b) % 26;
    printf("For a=2, b=3, plaintext 0 maps to ciphertext %d\n", c);
    return 0;
}
