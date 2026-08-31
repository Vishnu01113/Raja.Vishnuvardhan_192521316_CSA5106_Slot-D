#include <stdio.h>
#include <string.h>

void padData(unsigned char *data, int dataLen, int blockSize, unsigned char *paddedData, int *paddedLen) {
    int paddingLen = blockSize - (dataLen % blockSize);
    
    printf("Padding in Block Ciphers:\n\n");
    printf("Original data: ");
    for (int i = 0; i < dataLen; i++) printf("%c", data[i]);
    printf(" (length: %d)\n", dataLen);
    printf("Block size: %d\n", blockSize);
    
    memcpy(paddedData, data, dataLen);
    
    if (dataLen % blockSize == 0) {
        printf("\nLast block is already complete (%d bytes)\n", blockSize);
        printf("Still need to add padding for block alignment:\n");
        paddingLen = blockSize;
    } else {
        printf("Remaining bytes: %d\n", blockSize - (dataLen % blockSize));
    }
    
    printf("Padding length needed: %d bytes\n", paddingLen);
    printf("Padding value: 0x%02x (decimal %d)\n", paddingLen, paddingLen);
    
    for (int i = 0; i < paddingLen; i++) {
        paddedData[dataLen + i] = paddingLen;
    }
    
    *paddedLen = dataLen + paddingLen;
    
    printf("\nPadded data: ");
    for (int i = 0; i < *paddedLen; i++) {
        if (i < dataLen) printf("%c", paddedData[i]);
        else printf("\\x%02x", paddedData[i]);
    }
    printf(" (length: %d)\n", *paddedLen);
    printf("Data divided into %d complete blocks\n", *paddedLen / blockSize);
}

void unpadData(unsigned char *paddedData, int paddedLen, unsigned char *data, int *dataLen) {
    int paddingLen = paddedData[paddedLen - 1];
    *dataLen = paddedLen - paddingLen;
    
    printf("\n\nUnpadding Process:\n");
    printf("Padded length: %d\n", paddedLen);
    printf("Last byte value (padding length): %d\n", paddingLen);
    printf("Original data length: %d\n", *dataLen);
    
    memcpy(data, paddedData, *dataLen);
    printf("Recovered data: ");
    for (int i = 0; i < *dataLen; i++) printf("%c", data[i]);
    printf("\n");
}

int main() {
    unsigned char plaintext[50] = "Hello";
    unsigned char paddedData[50];
    unsigned char recovered[50];
    int paddedLen, recoveredLen;
    
    padData(plaintext, strlen((char *)plaintext), 8, paddedData, &paddedLen);
    unpadData(paddedData, paddedLen, recovered, &recoveredLen);
    
    printf("\n\nWhy padding is always added (even if last block is complete):\n");
    printf("1. Preserves block alignment and simplifies parsing\n");
    printf("2. Allows unambiguous removal - receiver knows exact number of padding bytes\n");
    printf("3. Without this, a message ending in block boundary would be ambiguous\n");
    printf("4. Protects against padding oracle attacks in some schemes\n");
    
    return 0;
}
