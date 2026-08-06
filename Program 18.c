#include <stdio.h>

int main(void) {
    int key[56] = {0};
    int i;
    for (i = 0; i < 56; i++) {
        key[i] = (i % 2 == 0) ? 1 : 0;
    }
    printf("Initial 56-bit key split into two 28-bit halves\n");
    for (i = 0; i < 28; i++) {
        printf("Left[%d]=%d ", i, key[i]);
    }
    printf("\n");
    for (i = 28; i < 56; i++) {
        printf("Right[%d]=%d ", i - 28, key[i]);
    }
    printf("\n");
    return 0;
}
