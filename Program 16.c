#include <stdio.h>
#include <ctype.h>
#include <string.h>

static void encryptMono(const char *plain, const char *key, char *out) {
    int i;
    for (i = 0; plain[i] != '\0'; i++) {
        if (isalpha((unsigned char)plain[i])) {
            out[i] = key[plain[i] - 'A'];
        } else {
            out[i] = plain[i];
        }
    }
    out[i] = '\0';
}

int main(void) {
    const char *plain = "ATTACKATDAWN";
    const char *key = "QWERTYUIOPASDFGHJKLZXCVBNM";
    char cipher[100];
    encryptMono(plain, key, cipher);
    printf("Ciphertext: %s\n", cipher);
    return 0;
}
