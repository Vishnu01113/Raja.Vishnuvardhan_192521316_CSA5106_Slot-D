#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char plaintext[100], ciphertext[100];
    int a, b, i;

    printf("Enter plaintext: ");
    scanf("%s", plaintext);

    printf("Enter value of a: ");
    scanf("%d", &a);

    printf("Enter value of b: ");
    scanf("%d", &b);

    for (i = 0; plaintext[i] != '\0'; i++) {
        char ch = toupper(plaintext[i]);

        if (ch >= 'A' && ch <= 'Z') {
            int p = ch - 'A';
            ciphertext[i] = ((a * p + b) % 26) + 'A';
        } else {
            ciphertext[i] = plaintext[i];
        }
    }

    ciphertext[i] = '\0';

    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
