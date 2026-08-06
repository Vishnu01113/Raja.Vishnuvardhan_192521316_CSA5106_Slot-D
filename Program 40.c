#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char text[] = "SECURITY";
    char key[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha((unsigned char)text[i])) {
            text[i] = key[text[i] - 'A'];
        }
    }
    printf("Monoalphabetic substitution ciphertext: %s\n", text);
    return 0;
}
