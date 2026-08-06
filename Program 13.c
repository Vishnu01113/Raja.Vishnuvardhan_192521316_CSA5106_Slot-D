#include <stdio.h>

int main(void) {
    int p1[2] = {1, 0};
    int p2[2] = {0, 1};
    int c1[2] = {2, 5};
    int c2[2] = {3, 7};

    int key[2][2] = {{c1[0], c2[0]}, {c1[1], c2[1]}};

    printf("Recovered key matrix from known plaintext-ciphertext pairs:\n");
    printf("[%d %d]\n", key[0][0], key[0][1]);
    printf("[%d %d]\n", key[1][0], key[1][1]);
    return 0;
}
