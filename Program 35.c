#include <stdio.h>
#include <ctype.h>

void encryptVigenereOTP(const char *plain, int *key, int len) {
    int i;
    for (i = 0; i < len; i++) {
        char ch = toupper((unsigned char)plain[i]);
        int p = ch - 'A';
        int c = (p + key[i]) % 26;
        printf("%c", c + 'A');
    }
    printf("\n");
}

int main() {
    const char *plain = "HELLO";
    int key[] = {3, 19, 5};
    encryptVigenereOTP(plain, key, 3);
    return 0;
}
