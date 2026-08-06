#include <stdio.h>

int main() {
    printf("DSA signatures differ for the same message because k is randomized each time.\n");
    printf("RSA signatures are deterministic for a given key and message.\n");
    return 0;
}
