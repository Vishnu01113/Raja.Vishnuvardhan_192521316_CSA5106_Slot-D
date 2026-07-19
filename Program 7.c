#include <stdio.h>
#include <string.h>

int main() {
    char cipher[2000];
    int freq[256] = {0};

    printf("Enter the ciphertext:\n");
    fgets(cipher, sizeof(cipher), stdin);

    for (int i = 0; cipher[i] != '\0'; i++) {
        if (cipher[i] != '\n' && cipher[i] != ' ')
            freq[(unsigned char)cipher[i]]++;
    }

    printf("\nCharacter Frequency:\n");

    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0)
            printf("%c\t%d\n", i, freq[i]);

    return 0;
    }
}
    
