#include <stdio.h>

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main(void) {
    long long a, b;

    printf("Enter two positive numbers: ");
    if (scanf("%lld %lld", &a, &b) != 2 || a <= 0 || b <= 0) {
        printf("Enter two positive integers.\n");
        return 1;
    }

    long long g = gcd(a, b);
    printf("GCD = %lld\n", g);
    printf("LCM = %lld\n", (a / g) * b);
    return 0;
}
