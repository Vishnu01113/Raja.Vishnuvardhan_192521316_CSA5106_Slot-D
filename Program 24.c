#include <stdio.h>
#include <math.h>

int main() {
    int e = 31, n = 3599;
    int phi = 0;
    int p = 59, q = 61;
    phi = (p - 1) * (q - 1);
    int d = 0;
    int k = 1;
    while ((1 + k * phi) % e != 0) {
        k++;
    }
    d = (1 + k * phi) / e;
    printf("Private key d = %d\n", d);
    return 0;
}
