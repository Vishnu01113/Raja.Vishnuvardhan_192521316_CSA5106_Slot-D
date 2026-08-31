#include <stdio.h>
#include <string.h>

void ctrEncrypt(char *plaintext, char *key, unsigned long counter, char *ciphertext) {
    printf("Counter (CTR) Mode Encryption:\n");
    printf("Plaintext: %s\n", plaintext);
    printf("Key: %s\n", key);
    printf("Initial Counter: %lu\n", counter);
    printf("Counter is incremented for each block and encrypted with the key.\n");
    printf("Ciphertext = Plaintext XOR E(Key, Counter)\n");
    strcpy(ciphertext, plaintext);
    printf("Ciphertext: %s (simulated)\n", ciphertext);
}

void ctrDecrypt(char *ciphertext, char *key, unsigned long counter, char *plaintext) {
    printf("\nCounter (CTR) Mode Decryption:\n");
    printf("Ciphertext: %s\n", ciphertext);
    printf("Counter-based decryption uses same process as encryption.\n");
    strcpy(plaintext, ciphertext);
    printf("Plaintext: %s (simulated)\n", plaintext);
}

int main() {
    char plaintext[100] = "SecretMessage";
    char key[100] = "MySecretKey";
    unsigned long counter = 1;
    char ciphertext[100];
    char decrypted[100];
    
    ctrEncrypt(plaintext, key, counter, ciphertext);
    ctrDecrypt(ciphertext, key, counter, decrypted);
    
    return 0;
}
