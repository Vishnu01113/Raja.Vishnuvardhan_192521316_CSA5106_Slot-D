#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5];

void generateMatrix(char key[]) {
    int used[26] = {0};
    int i, k = 0;

    used['J' - 'A'] = 1;

    for (i = 0; key[i] != '\0'; i++) {
        char ch = toupper(key[i]);
        if (ch == 'J')
            ch = 'I';

        if (ch >= 'A' && ch <= 'Z' && !used[ch - 'A']) {
            matrix[k / 5][k % 5] = ch;
            used[ch - 'A'] = 1;
            k++;
        }
    }

    for (i = 0; i < 26; i++) {
        if (!used[i]) {
            matrix[k / 5][k % 5] = 'A' + i;
            k++;
        }
    }
}

void findPosition(char ch, int *row, int *col) {
    if (ch == 'J')
        ch = 'I';

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
}

void decrypt(char text[]) {
    int len = strlen(text);

    printf("\nPlaintext: ");

    for (int i = 0; i < len; i += 2) {
        int r1, c1, r2, c2;

        findPosition(text[i], &r1, &c1);
        findPosition(text[i + 1], &r2, &c2);

        if (r1 == r2) {
            printf("%c%c",
                   matrix[r1][(c1 + 4) % 5],
                   matrix[r2][(c2 + 4) % 5]);
        }
        else if (c1 == c2) {
            printf("%c%c",
                   matrix[(r1 + 4) % 5][c1],
                   matrix[(r2 + 4) % 5][c2]);
        }
        else {
            printf("%c%c",
                   matrix[r1][c2],
                   matrix[r2][c1]);
        }
    }
    printf("\n");
}

int main() {
    char key[100], text[500], temp[500];
    int j = 0;

    printf("Enter Playfair Key: ");
    scanf("%s", key);

    printf("Enter Ciphertext: ");
    scanf(" %[^\n]", text);

    for (int i = 0; text[i] != '\0'; i++)
        if (isalpha(text[i]))
            temp[j++] = toupper(text[i]);

    temp[j] = '\0';

    generateMatrix(key);

    printf("\nPlayfair Matrix:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            printf("%c ", matrix[i][j]);
        printf("\n");
    }

    decrypt(temp);

    return 0;
}
