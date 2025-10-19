#include <stdio.h>
int main() {
    int n, digit, even = 0, odd = 0;
    printf("Enter number: ");
    scanf("%d", &n);

    while (n != 0) {
        digit = n % 10;
        if (digit % 2 == 0)
            even++;
        else
            odd++;
        n /= 10;
    }
    printf("Even digits: %d\nOdd digits: %d\n", even, odd);
    return 0;
}