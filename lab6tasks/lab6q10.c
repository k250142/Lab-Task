#include <stdio.h>
int main() {
    int n, i, j, space;
    printf("Enter number of rows: ");
    scanf("%d", &n);
    space = n - 1;

    // Upper half
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= space; j++)
            printf(" ");
        for (j = 1; j <= 2 * i - 1; j++)
            if (j == 1 || j == 2 * i - 1)
                printf("*");
            else
                printf(" ");
        printf("\n");
        space--;
    }

    // Lower half
    space = 1;
    for (i = n - 1; i >= 1; i--) {
        for (j = 1; j <= space; j++)
            printf(" ");
        for (j = 1; j <= 2 * i - 1; j++)
            if (j == 1 || j == 2 * i - 1)
                printf("*");
            else
                printf(" ");
        printf("\n");
        space++;
    }

    return 0;
}