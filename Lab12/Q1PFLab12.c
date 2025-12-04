#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, index = 0;
    printf("Enter number of book categories: ");
    scanf("%d", &n);

    int *stock = (int*)malloc(n * sizeof(int));

    for(i = 0; i < n; i++) {
        printf("Enter stock for category %d: ", i);
        scanf("%d", &stock[i]);
    }

    int total = 0, min = stock[0];
    for(i = 0; i < n; i++) {
        total += stock[i];
        if(stock[i] < min) {
            min = stock[i];
            index = i;
        }
    }

    printf("Total stock: %d\n", total);
    printf("Average stock: %.2f\n", (float)total/n);
    printf("Lowest stock category index: %d\n", index);

    int cat, newStock;
    printf("Enter category index to update: ");
    scanf("%d", &cat);
    printf("Enter new stock: ");
    scanf("%d", &newStock);
    stock[cat] = newStock;

    printf("Updated stock: ");
    for(i = 0; i < n; i++) printf("%d ", stock[i]);

    free(stock);
    return 0;
}
