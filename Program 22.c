#include <stdio.h>
#include <string.h>

void cbcEncrypt(char *plaintext, char *key, char *iv, char *ciphertext) {
    printf("CBC Mode Encryption:\n");
    printf("Plaintext: %s\n", plaintext);
    printf("Key: %s\n", key);
    printf("IV: %s\n", iv);
    printf("Each plaintext block is XORed with the previous ciphertext block before encryption.\n");
    printf("First block is XORed with IV.\n");
    strcpy(ciphertext, plaintext);
    printf("Ciphertext: %s (simulated)\n", ciphertext);
}

void cbcDecrypt(char *ciphertext, char *key, char *iv, char *plaintext) {
    printf("\nCBC Mode Decryption:\n");
    printf("Ciphertext: %s\n", ciphertext);
    printf("Each decrypted block is XORed with the previous ciphertext block.\n");
    strcpy(plaintext, ciphertext);
    printf("Plaintext: %s (simulated)\n", plaintext);
}

int main() {
    char plaintext[100] = "HelloWorld";
    char key[100] = "MySecretKey";
    char iv[100] = "InitVector";
    char ciphertext[100];
    char decrypted[100];
    
    cbcEncrypt(plaintext, key, iv, ciphertext);
    cbcDecrypt(ciphertext, key, iv, decrypted);
    
    return 0;
}
