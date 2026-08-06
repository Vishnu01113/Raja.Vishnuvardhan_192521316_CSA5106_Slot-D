#include <stdio.h>
#include <ctype.h>

int main() {
    char text[] = "HELLO";
    int shift = 3;
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha((unsigned char)text[i])) {
            char base = isupper((unsigned char)text[i]) ? 'A' : 'a';
            text[i] = (char)(((text[i] - base + shift) % 26) + base);
        }
    }
    printf("Additive cipher ciphertext: %s\n", text);
    return 0;
}
