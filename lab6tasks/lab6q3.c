#include <stdio.h>
int main() {
    int n, i, j, isPrime;
    printf("Enter a number: ");
    scanf("%d", &n);
    
    isPrime = 1;
    if (n <= 1) isPrime = 0;
    for (i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            isPrime = 0;
            break;
        }
    }
    if (isPrime)
        printf("%d is a Prime Number\n", n);
    else
        printf("%d is not a Prime Number\n", n);

    printf("Prime numbers from 1 to %d:\n", n);
    for (i = 2; i <= n; i++) {
        isPrime = 1;
        for (j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime)
            printf("%d ", i);
    }
    return 0;
}