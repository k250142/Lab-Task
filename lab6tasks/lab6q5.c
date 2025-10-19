#include <stdio.h>
int main() {
    int n, i;
    unsigned long fact = 1;
    printf("Enter number: ");
    scanf("%d", &n);
    if (n>-1){
    
    	for (i = 1; i <= n; i++)
        fact *= i;

    printf("Factorial = %lu\n", fact);
	}
	else {
    	printf("Invalid Number for Factorial");
   }
    return 0;
}