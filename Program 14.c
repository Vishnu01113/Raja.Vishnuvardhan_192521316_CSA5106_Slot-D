#include <stdio.h>
#include <ctype.h>

static void encryptVigenereOTP(const char *plain, const int *key, int len) {
    int i;
    printf("Ciphertext: ");
    for (i = 0; i < len; i++) {
        char ch = toupper((unsigned char)plain[i]);
        int p = ch - 'A';
        int c = (p + key[i]) % 26;
        printf("%c", c + 'A');
    }
    printf("\n");
}

int main(void) {
    const char *plain = "SENDMOREMONEY";
    int key[] = {9, 0, 1, 7, 23, 15, 21, 14, 11, 11, 2, 8, 9};
    encryptVigenereOTP(plain, key, 13);
    return 0;
}
