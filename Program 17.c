#include <stdio.h>

static int rotateLeft(int value, int shift) {
    return ((value << shift) | (value >> (28 - shift))) & 0x0FFFFFFF;
}

int main(void) {
    int left = 0x1234567;
    int right = 0x89ABCDEF;
    int shifts[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};
    int i;

    printf("DES-style decryption key schedule (reverse order)\n");
    for (i = 15; i >= 0; i--) {
        left = rotateLeft(left, shifts[i]);
        right = rotateLeft(right, shifts[i]);
        printf("Round %d: left=%08X right=%08X\n", i + 1, left, right);
    }
    return 0;
}
