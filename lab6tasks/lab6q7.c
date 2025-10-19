#include <stdio.h>
int main() {
    int n, rev = 0, temp;
    printf("Enter a number: ");
    scanf("%d", &n);
    temp = n;

    while (temp != 0) {
        rev = rev * 10 + temp % 10;
        temp /= 10;
    }

    if (n == rev)
        printf("Palindrome Number\n");
    else
        printf("Not a Palindrome\n");
    return 0;
}