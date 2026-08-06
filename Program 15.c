#include <stdio.h>
#include <ctype.h>

static void decryptShift(const char *cipher, int shift, char *out) {
    int i;
    for (i = 0; cipher[i] != '\0'; i++) {
        if (isalpha((unsigned char)cipher[i])) {
            char base = isupper((unsigned char)cipher[i]) ? 'A' : 'a';
            out[i] = (char)(((cipher[i] - base - shift + 26) % 26) + base);
        } else {
            out[i] = cipher[i];
        }
    }
    out[i] = '\0';
}

static int scoreText(const char *text) {
    int freq[26] = {8, 1, 2, 4, 12, 2, 3, 2, 6, 0, 1, 4, 2, 6, 7, 2, 1, 6, 6, 9, 3, 1, 2, 1, 2, 1};
    int i, score = 0;
    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha((unsigned char)text[i])) {
            char ch = tolower((unsigned char)text[i]);
            score += freq[ch - 'a'];
        }
    }
    return score;
}

int main(void) {
    const char *cipher = "KHOOR";
    char best[100];
    int bestShift = 0, bestScore = -1;
    int shift;

    for (shift = 0; shift < 26; shift++) {
        char candidate[100];
        decryptShift(cipher, shift, candidate);
        int s = scoreText(candidate);
        if (s > bestScore) {
            bestScore = s;
            bestShift = shift;
            strcpy(best, candidate);
        }
    }

    printf("Best shift: %d\n", bestShift);
    printf("Likely plaintext: %s\n", best);
    return 0;
}
