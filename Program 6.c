#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1;
}

int main() {
    int c1 = 'B' - 'A';
    int c2 = 'U' - 'A';
    int p1 = 'E' - 'A';
    int p2 = 'T' - 'A';

    int a, b;

    for (a = 1; a < 26; a++) {
        if (gcd(a, 26) != 1)
            continue;

        if (((a * (p2 - p1)) % 26 + 26) % 26 ==
            ((c2 - c1) % 26 + 26) % 26) {

            b = (c1 - a * p1) % 26;
            if (b < 0)
                b += 26;

            printf("Possible Key:\n");
            printf("a = %d\n", a);
            printf("b = %d\n", b);

            int inv = modInverse(a, 26);
            printf("Multiplicative Inverse of a = %d\n", inv);
        }
    }

    return 0;
}
