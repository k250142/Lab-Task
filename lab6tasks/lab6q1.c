#include <stdio.h>
int main() {
    int pin, sum = 0, temp;
    printf("Enter 4-digit PIN: ");
    scanf("%d", &pin);
    temp = pin;

    while (temp > 0) {
        sum =sum + temp % 10;
        temp =temp 
		/ 10;
    }

    if (sum > 10)
        printf("Strong PIN\n");
    else
        printf("Weak PIN\n");

    return 0;
}