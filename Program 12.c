#include <stdio.h>
#include <ctype.h>
#include <string.h>

static void normalize(char *text) {
    int i, j = 0;
    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha((unsigned char)text[i])) {
            text[j++] = toupper((unsigned char)text[i]);
        }
    }
    text[j] = '\0';
}

static void hillEncrypt(const char *msg, int key[2][2]) {
    char work[100];
    int len, i;
    strcpy(work, msg);
    normalize(work);

    len = strlen(work);
    printf("Hill cipher encryption\n");
    for (i = 0; i < len; i += 2) {
        int a = work[i] - 'A';
        int b = (i + 1 < len) ? (work[i + 1] - 'A') : 0;
        int c = (key[0][0] * a + key[0][1] * b) % 26;
        int d = (key[1][0] * a + key[1][1] * b) % 26;
        printf("Block (%d,%d) -> (%d,%d)\n", a, b, c, d);
    }
}

int main(void) {
    int key[2][2] = {{9, 4}, {5, 7}};
    hillEncrypt("MEETMEATTHEUSUALPLACE", key);
    return 0;
}
