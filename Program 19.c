#include <stdio.h>

static unsigned char toyEncrypt(unsigned char block, unsigned char key) {
    return (unsigned char)((block ^ key) + 3);
}

int main(void) {
    unsigned char iv = 0x5A;
    unsigned char blocks[] = {0x10, 0x20, 0x30, 0x40};
    unsigned char key = 0x7F;
    int i;
    unsigned char prev = iv;
    printf("CBC encryption with toy block cipher\n");
    for (i = 0; i < 4; i++) {
        unsigned char x = blocks[i] ^ prev;
        unsigned char c = toyEncrypt(x, key);
        prev = c;
        printf("Block %d -> %02X\n", i + 1, c);
    }
    return 0;
}
