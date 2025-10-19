#include <stdio.h>

long long factorial(int n) {
    long long fact = 1;
    for (int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

int main() {
    int n, i;
    printf("Enter n: ");
    scanf("%d", &n);

    printf("First %d Catalan numbers:\n", n);
    for (i = 0; i < n; i++) {
        long long c = factorial(2 * i) / (factorial(i + 1) * factorial(i));
        printf("%lld ", c);
    }
    return 0;
}