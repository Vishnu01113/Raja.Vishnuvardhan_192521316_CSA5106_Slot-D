#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5] = {
    {'M','F','H','I','K'},
    {'U','N','O','P','Q'},
    {'Z','V','W','X','Y'},
    {'E','L','A','R','G'},
    {'D','S','T','B','C'}
};

void findPosition(char ch, int *row, int *col) {
    if (ch == 'J')
        ch = 'I';

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

void encrypt(char text[]) {
    int r1, c1, r2, c2;

    printf("Ciphertext: ");

    for (int i = 0; text[i] != '\0'; i += 2) {
        findPosition(text[i], &r1, &c1);
        findPosition(text[i + 1], &r2, &c2);

        if (r1 == r2) {
            printf("%c%c",
                   matrix[r1][(c1 + 1) % 5],
                   matrix[r2][(c2 + 1) % 5]);
        }
        else if (c1 == c2) {
            printf("%c%c",
                   matrix[(r1 + 1) % 5][c1],
                   matrix[(r2 + 1) % 5][c2]);
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
    char text[200], temp[200];
    int j = 0;

    printf("Enter Plaintext: ");
    scanf(" %[^\n]", text);

    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char ch = toupper(text[i]);
            if (ch == 'J')
                ch = 'I';
            temp[j++] = ch;
        }
    }

    if (j % 2 != 0)
        temp[j++] = 'X';

    temp[j] = '\0';

    printf("\nPlayfair Matrix:\n");
    for (int i = 0; i < 5; i++) {
        for (int k = 0; k < 5; k++)
            printf("%c ", matrix[i][k]);
        printf("\n");
    }

    encrypt(temp);

    return 0;
}
