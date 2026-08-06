#include <stdio.h>
#include <math.h>

int main(void) {
    double total = pow(2.0, 25.0);
    printf("Approximate number of possible Playfair keys: 2^25\n");
    printf("Approximate value: %.0f\n", total);
    return 0;
}
