#include <stdio.h>

int main(void) {
    int ecb[3] = {1, 2, 3};
    int cbc[3] = {1, 2, 3};
    int errorIndex = 1;

    printf("ECB effect: block %d is corrupted only\n", errorIndex + 1);
    printf("CBC effect: block %d and following blocks may be affected\n", errorIndex + 1);
    printf("Example: one-bit error in block 2 causes propagation into the next plaintext block\n");
    return 0;
}
