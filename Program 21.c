#include <stdio.h>
#include <string.h>

void padData(char *data, int blockSize) {
    int dataLen = strlen(data);
    int paddingLen = blockSize - (dataLen % blockSize);
    
    printf("Original data: %s (length: %d)\n", data, dataLen);
    printf("Block size: %d\n", blockSize);
    printf("Padding required: %d bytes\n", paddingLen);
    
    // Add padding
    for (int i = 0; i < paddingLen; i++) {
        data[dataLen + i] = paddingLen;
    }
    data[dataLen + paddingLen] = '\0';
    
    printf("Padded data length: %d\n", dataLen + paddingLen);
    printf("Final block is now complete and the receiver can unpad correctly.\n");
}

void unpadData(char *data, int dataLen) {
    int paddingLen = data[dataLen - 1];
    printf("Removing %d bytes of padding...\n", paddingLen);
    data[dataLen - paddingLen] = '\0';
    printf("Unpadded data: %s\n", data);
}

int main() {
    char data[50] = "Hello";
    int blockSize = 8;
    
    padData(data, blockSize);
    printf("\n");
    unpadData(data, strlen(data));
    
    return 0;
}
