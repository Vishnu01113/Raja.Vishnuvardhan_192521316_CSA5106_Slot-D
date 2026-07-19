#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char plain[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char cipher[] = "CIPHERABDFGJKLMNOQSTUVWXYZ";
    char text[100], result[100];
    int i;

    printf("Plain Alphabet : %s\n", plain);
    printf("Cipher Alphabet: %s\n", cipher);

    printf("\nEnter Plaintext: ");
    scanf("%s", text);

    for (i = 0; text[i] != '\0'; i++) {
        char ch = toupper(text[i]);

        if (ch >= 'A' && ch <= 'Z')
            result[i] = cipher[ch - 'A'];
        else
            result[i] = text[i];
    }

    result[i] = '\0';

    printf("Ciphertext: %s\n", result);

    return 0;
}
